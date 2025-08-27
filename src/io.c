#include <io.h>

#define SYS_READ 0
#define SYS_WRITE 1

extern long sys_call(long, long, long, long, long, long, long);

int io_puts(String msg, int stdstream) {
    if (stdstream < 0 || stdstream > 2) {
        return -1;
    }
    return (int)sys_call(SYS_WRITE, stdstream, (long)msg.chars, msg.len - 1, 0, 0, 0);
}

int io_gets(String* msg, int stdstream) {
    if (stdstream < 0 || stdstream > 2) {
        return -1;
    }
    return (int)sys_call(SYS_READ, stdstream, (long)msg->chars, msg->len - 1, 0, 0, 0);
}