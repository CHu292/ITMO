; Вывод сообщения с помощью системных вызовов Linux
; (без использования стандартной библиотеки С)
; 
; nasm -felf64 hello_sys.S && ld -o hello_sys hello_sys.o


            global _start

            section .text
_start:     mov rax, sys_write
            mov rdi, 1              ; 1 = stdout
            mov rsi, msg
            mov rdx, msg_len
            syscall
            mov rax, sys_exit
            ;xor rdi, rdi            ; exit code
            mov rdi, 42
            syscall
            
            section .data
msg         db      'Hello, world!', 10
msg_len     equ     $ - msg
sys_write   equ     1
sys_exit    equ     60
