; Вывод сообщения с помощью функций стандартной
; библиотеки C. Функция hello_func вызывается из
; hello_main.c
;
; nasm -felf64 hello_func.S

            global hello_func
            extern puts

            section .text
hello_func:
            mov rdi, msg
            call puts

            ret
            
            section .data
msg         db      'Hello, world!', 0
