#include <string.h>

size_t string_strlen(char* str) {
    int c = 0;
    size_t i = 0;
    while (str[c++] != '\0') {
        i++;
    }
    return i;
}