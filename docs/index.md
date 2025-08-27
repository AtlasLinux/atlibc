# atlibc

atlibc is a from-scratch C library for Linux x86_64, with no external dependencies.
It is **not** POSIX- or ISO-C-compliant — function names, semantics, and API design
are intentionally custom.

## Building
```sh
make
```
## Usage
```c
#include <io.h>
#include <string.h>
#include <int.h>

int main(void) {
    String msg = string_from("Hello, world!\n");
    io_puts(msg, STDOUT);
    return 0;
}
```

See docs/ for API documentation.
