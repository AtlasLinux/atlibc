#include <def.h>
#include <int.h>
#include <io.h>
#include <string.h>

long main(void) {
    const String msg = { .chars = "Hello, world!\n", .len = string_strlen(msg.chars) };
    io_puts(msg, STDOUT);
    return 0;
}