; Вычисление n-го члена ряда Фибоначчи
;
; nasm -felf64 fib_asm.S && gcc -static -o fib_asm fib_asm.o

            global main
            extern printf

            section .text
fib:
            push    rbp
			mov		rbp, rsp
            push    r8
            push    rdi

            mov     rax, 1
            cmp     rdi, 2
            jle     end             ; если n < 3, то сразу вернуть 1
            
            dec     rdi
            call    fib             ; вычислить fib(n-1)
            add     r8, rax         ; добавить к r8
            dec     rdi
            call    fib             ; вычислить fib(n-2)
            add     r8, rax         ; добавить к r8
            mov     rax, r8         ; в r8 fib(n-1) + fib(n-2), вернуть это в качестве результата
            
end:        pop     rdi
            pop     r8
            pop     rbp
            ret                     ; возвращаемое значение - в rax
main:
            ; If this prologue is removed, printf() crashes - 
            ; because of wrong rsp alignment (which is System V ABI requirement):
            ; https://stackoverflow.com/questions/25693827/segmentation-fault-on-printf-nasm-64bit-linux
            push    rbp
            mov     rbp, rsp
            sub     rsp, 0x10
            
            mov     rdi, [n]
            call    fib
            
            mov     rdi, msg
            mov     rsi, [n]
            mov     rdx, rax
            xor     rax, rax            
            call    printf

            ; If this epilogue is removed, we get SIGSEGV
            leave
            ret
            
            section .data
n           dq      6
msg         db      `fib(%lu) = %lu\n`, 0
