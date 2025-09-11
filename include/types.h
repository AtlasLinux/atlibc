#ifndef ATLIBC_DEF_H
#define ATLIBC_DEF_H

typedef long                ptrdiff_t;
typedef unsigned long       size_t;
typedef long                ssize_t;

typedef signed char         int8_t;
typedef short               int16_t;
typedef int                 int32_t;
typedef long                int64_t;

typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned long       uint64_t;

typedef long                intptr_t;
typedef unsigned long       uintptr_t;

#define SIZE_MAX 18446744073709551615UL

#define NULL ((void*)0)

#endif
