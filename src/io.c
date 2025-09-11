#include <io.h>
#include <system.h>

int io__puts(String msg, int stdstream) {
    if (stdstream < 0 || stdstream > 2) {
        return -1;
    }
    return (int)__syscall(SYS_WRITE, stdstream, (long)msg.chars, msg.len - 1, 0, 0, 0);
}

int io__putc(char c, int stdstream) {
    if (stdstream < 0 || stdstream > 2) {
        return -1;
    }
    return (int)__syscall(SYS_WRITE, stdstream, (long)&c, 1, 0, 0, 0);
}

int io__gets(String* msg, int stdstream, int count) {
    if (stdstream < 0 || stdstream > 2) {
        return -1;
    }
    return (int)__syscall(SYS_READ, stdstream, (long)msg->chars, (long)count, 0, 0, 0);
}

int io__set_col(colours_t col) {
    col %= 8;
    switch(col) {
        case BLACK:
            io__puts((String){ .chars = ANSI_BLACK, .len = 8}, 1);
            break;
        case RED:
            io__puts((String){ .chars = ANSI_RED, .len = 8}, 1);
            break;
        case GREEN:
            io__puts((String){ .chars = ANSI_GREEN, .len = 8}, 1);
            break;
        case YELLOW:
            io__puts((String){ .chars = ANSI_YELLOW, .len = 8}, 1);
            break;
        case BLUE:
            io__puts((String){ .chars = ANSI_BLUE, .len = 8}, 1);
            break;
        case PURPLE:
            io__puts((String){ .chars = ANSI_PURPLE, .len = 8}, 1);
            break;
        case CYAN:
            io__puts((String){ .chars = ANSI_CYAN, .len = 8}, 1);
            break;
        case WHITE:
            io__puts((String){ .chars = ANSI_WHITE, .len = 8}, 1);
            break;
        default:
            break;
    }
    return 0;
}