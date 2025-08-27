global _start

extern uwu

section .text
_start:
    call uwu

    mov rdi, rax
    mov rax, 60
    syscall
