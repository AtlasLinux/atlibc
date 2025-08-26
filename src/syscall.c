#include <int.h>

long sys_call(long n,
              long a1, long a2, long a3,
              long a4, long a5, long a6)
{
    long ret;
    register long r10 asm("r10") = a4;
    register long r8  asm("r8")  = a5;
    register long r9  asm("r9")  = a6;

    asm volatile (
        "syscall"
        : "=a" (ret)                    /* output: RAX = return value */
        : "a" (n),                      /* RAX = syscall number */
          "D" (a1),                     /* RDI = arg1 */
          "S" (a2),                     /* RSI = arg2 */
          "d" (a3),                     /* RDX = arg3 */
          "r" (r10), "r" (r8), "r" (r9) /* r10,r8,r9 = arg4-6 */
        : "rcx", "r11", "memory"
    );
    return ret;
}
