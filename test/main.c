#include <types.h>
#include <int.h>
#include <io.h>
#include <string.h>

int uwu(void) {
    char buf[256];
    String msg = { .chars = buf, .len = 256 };
    while (1) {
        io_gets(&msg, STDIN, (int)msg.len);
        io_puts(msg, STDOUT);
        string_clear(&msg);
    }
    return 0;
}