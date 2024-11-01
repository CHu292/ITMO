; Вывод сообщения с помощью функций стандартной
; библиотеки C
;
; nasm -felf64 hello_libc.S && gcc -static -o hello_libc hello_libc.o

            global main
            extern puts, exit

            section .text
main:
            mov rdi, msg
            call puts

            ;mov rdi, 42
            ;call exit

            ret
            
            section .data
msg         db      'Hello, world!', 0
