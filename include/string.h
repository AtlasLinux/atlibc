#ifndef ATLIBC_STRING_H
#define ATLIBC_STRING_H

#include <types.h>

typedef struct String {
    char* chars;
    size_t len;
    size_t cap;
} String;

size_t string_strlen(char* str);
void string_clear(String* str);

#endif