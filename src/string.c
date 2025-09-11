#include <string.h>

size_t str__len(char* str) {
    int c = 0;
    size_t i = 0;
    while (str[c++] != '\0') {
        i++;
    }
    return i;
}

void str__create(char* str, size_t size) {
    
}

void str__clear(String* str) {
    for (unsigned int i = 0; i < str->len; i++) {
        str->chars[i] = (char)NULL;
    }
}