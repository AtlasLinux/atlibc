#include <string.h>

int string_strlen(char* str) {
    int c = 0;
    int i = 0;
    while (str[c++] != '\0') {
        i++;
    }
    return i;
}