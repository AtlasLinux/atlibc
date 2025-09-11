#include <types.h>
#include <io.h>
#include <string.h>

int main(void) {
    String msg = { .chars = "Hello, world.\n", .len = 15 };
    for (int i = 0; i < msg.len; i++) {
        io__putc(msg.chars[i], STDOUT);
        io__set_col(i);
    }
    return 0;
}