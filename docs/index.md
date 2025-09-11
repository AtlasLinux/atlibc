# atlibc Documentation

Welcome to the atlibc documentation.  
This library provides a minimal, custom C runtime for Linux x86_64, built from scratch with direct syscalls.  
It is **not** standards-compliant — functions and types may differ from C/POSIX conventions.

---

## Modules

- [io](io.md) – Input/output functions (`io_puts`, `io_gets`, ...)
- [string](string.md) – String manipulation (`string_len`, ...)
<!--- [memory](memory.md) – Memory management (`malloc`, `free`, ...)-->
- [system](system.md) – Syscalls and process-related functions  
- [types](types.md) – Core type definitions (`uint64_t`, `size_t` ...)

---

## Getting Started

- [Build Instructions](../README.md#building)  
- [Usage Example](../README.md#usage)  

---

## Philosophy

- Minimal: every function is written in C + assembly, no external libraries.  
- Direct: system calls are wrapped directly, no libc abstractions.  
- Experimental: APIs may change quickly as the project evolves.  
