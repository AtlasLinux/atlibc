#ifndef ATLIBC_IO_H
#define ATLIBC_IO_H

#include <string.h>
#include <types.h>

#define STDIN 0
#define STDOUT 1

// prints 'msg' to 'stdstream'
int io_puts(String msg, int stdstream);
int io_gets(String* msg, int stdstream, int count);

#endif