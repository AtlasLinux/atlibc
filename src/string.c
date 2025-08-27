#include <string.h>

size_t string_strlen(char* str) {
    int c = 0;
    size_t i = 0;
    while (str[c++] != '\0') {
        i++;
    }
    return i;
}

void string_clear(String* str) {
    for (int i = 0; i < str->len; i++) {
        str->chars[i] = (char)NULL;
    }
}