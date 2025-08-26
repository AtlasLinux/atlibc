#ifndef ATLIBC_IO_H
#define ATLIBC_IO_H

#include <string.h>

#define STDOUT 1

// prints 'msg' to 'stdstream'
int io_puts(String msg, int stdstream);

#endif