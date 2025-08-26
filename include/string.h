#ifndef ATLIBC_STRING_H
#define ATLIBC_STRING_H

typedef struct String {
    char* chars;
    int len;
} String;

int string_strlen(char* str);

#endif