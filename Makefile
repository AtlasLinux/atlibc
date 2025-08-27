# Makefile — freestanding lib -> test app (NASM + GCC)

CC        := gcc
NASM      := nasm

# Compiler flags — freestanding bootstrap friendly
CFLAGS    := -O0 -g3 \
             -ffreestanding -fno-builtin -fno-stack-protector -nostdinc \
             -Iinclude \
             -Wall -Wextra -Wpedantic -Wconversion -Wdouble-promotion \
             -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion \
             -Wno-switch -Wno-conversion -Wno-unused-but-set-variable

DEPFLAGS = -MMD -MP -MF $(basename $@).d

# Linker flags for freestanding apps
LDFLAGS   := -nostdlib -static -Wl,-e,_start

BUILD_DIR := build
SRC_DIR   := src
TEST_DIR  := test

# Discover sources
SRC_C   := $(shell find $(SRC_DIR) -type f -name '*.c')
SRC_ASM := $(shell find $(SRC_DIR) -type f -name '*.asm')

# Map sources -> objects under build/
OBJ_C   := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_C))
OBJ_ASM := $(patsubst $(SRC_DIR)/%.asm,$(BUILD_DIR)/%.o,$(SRC_ASM))
OBJ_ALL := $(OBJ_C) $(OBJ_ASM)

DEPS := $(OBJ_C:.o=.d)

# Define the startup asm source and its object (adjust if your start file name differs)
START_SRC := $(SRC_DIR)/start.asm
START_OBJ := $(BUILD_DIR)/start.o

# Library info
LIBDIR  := $(BUILD_DIR)/lib
LIBNAME := atlibc.a
LIB     := $(LIBDIR)/$(LIBNAME)

# Test program to build (user asked for test/foo.c)
TEST_SRC := $(TEST_DIR)/main.c
TEST_OBJ := $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/test/%.o,$(TEST_SRC))
TEST_BIN := $(BUILD_DIR)/main

.PHONY: all lib test clean run

all: lib test

# Build the static library (exclude the startup object)
lib: $(LIB)

# Library objects = all compiled objects except the start object
LIB_OBJS := $(filter-out $(START_OBJ), $(OBJ_ALL))

$(LIB): $(LIB_OBJS) | $(LIBDIR)
	@mkdir -p $(dir $@)
	@echo "[AR] $@"
	ar rcs $@ $(LIB_OBJS)
	@ranlib $@ || true

# Build the test app (freestanding). Link order matters: start -> test -> lib
test: $(LIB) $(START_OBJ) $(TEST_OBJ)
	@echo "[LD] $(TEST_BIN)"
	$(CC) $(LDFLAGS) -o $(TEST_BIN) $(START_OBJ) $(TEST_OBJ) $(LIB)

# Generic rules -----------------------------------------------------------

# C -> object
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	@echo "[CC] $<"
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

# ASM -> object (NASM)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.asm | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	@echo "[ASM] $<"
	$(NASM) -f elf64 $< -o $@

# Test source compilation (keeps tests separate under build/test/)
$(BUILD_DIR)/test/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	@echo "[CC] $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build and lib directories exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIBDIR):
	mkdir -p $(LIBDIR)

# Clean
clean:
	rm -rf $(BUILD_DIR)

# Run the test binary
run: test
	@./$(TEST_BIN)

crun: clean run

-include $(DEPS)