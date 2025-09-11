#ifndef ATLIBC_STRING_H
#define ATLIBC_STRING_H

#include <types.h>

typedef struct String {
    char* chars;
    size_t len;
    size_t cap;
} String;

void str__create(char* str, size_t size);
void str__clear(String* str);
size_t str__len(char* str);

#endif