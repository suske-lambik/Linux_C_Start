.global _start

.section .data
message: .ascii "Hello world using AT&T syntax.\n"

.section .text
_start:
    mov $1, %rax        # syscall 1 is sys_write in x86_64
    mov $1, %rdi        # file descriptor 1 is stdout
    mov $message, %rsi  # 
    mov $32, %rdx       # length of message 
    syscall             # execute syscall with arguments in the required registers

    mov $60, %rax       # syscall 60 is sys_exit in x86_64
    mov $0, %rdi        # exit status is 0
    syscall
