#ifndef ATLIBC_IO_H
#define ATLIBC_IO_H

#include <string.h>
#include <types.h>

#define STDIN 0
#define STDOUT 1

#define ANSI_BLACK "\033[0;30m"
#define ANSI_RED "\033[0;31m"
#define ANSI_GREEN "\033[0;32m"
#define ANSI_YELLOW "\033[0;33m"
#define ANSI_BLUE "\033[0;34m"
#define ANSI_PURPLE "\033[0;35m"
#define ANSI_CYAN "\033[0;36m"
#define ANSI_WHITE "\033[0;37m"

typedef enum {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    CYAN,
    WHITE,
} colours_t;

// prints 'msg' to 'stdstream'
int io__puts(String msg, int stdstream);
int io__putc(char c, int stdstream);
int io__gets(String* msg, int stdstream, int count);
int io__set_col(colours_t col);

#endif