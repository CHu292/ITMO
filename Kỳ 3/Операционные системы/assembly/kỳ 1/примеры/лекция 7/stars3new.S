; Вывод фиксированного количества звездочек
; (без использования стандартной библиотеки С)
;
; По мотивам https://cs.lmu.edu/~ray/notes/nasmtutorial/
; 
; nasm -felf64 stars3new.S && ld -o stars3new stars3new.o
;

            global _start
            
            section   .text
_start:
            mov       r8, 1                 ; нужное количество звездочек в первой строке
            ;mov       r9, 0                 ; количество звездочек, напечатанных в строке
new_line:
            mov       r10, output           ; в r10 адрес буфера со строкой для вывода
line:
            ;mov       byte [r10], '*'       ; добавляем очередную звездочку в строку
            ;inc       r10                   ; к следующему байту
            ;inc       r9                    ; счетчик звездочек
            ;cmp       r9, r8                ; напечатали нужное количество звездочек?
            ;jne       line                  ; цикл добавления звездочек в строку

            mov       al, '*'
            mov       rdi, [r10]
            mov       rcx, r8
            cld
            rep stosb
            mov       r10, rdi
            
            mov       byte [r10], `\n`      ; добавляем перевод строки ('\n')
            inc       r10                   ; к следующему байту
            ;mov       r9, 0                 ; сбрасываем счетчик звездочек в строке
            mov       rax, sys_write        ; номер системного вызова write
            mov       rdi, 1                ; дескриптор 1 - стандартный вывод
            mov       rsi, output           ; адрес буфера
            lea       rdx, [r8 + 1]         ; сколько символов из буфера выводить
            syscall                         ; вывод строки
            inc       r8                    ; на следующей строке выводим на одну звездочку больше
            cmp       r8, maxlines          ; напечатали заданное количество строк?
            jng       new_line              ; если нет, напечатать новую строку

            mov       rax, sys_exit         ; номер системного вызова exit
            xor       rdi, rdi              ; exit code 0 (нормальное завершение)
            syscall                         ; завершение программы

            section   .bss
maxlines    equ     1024                    ; количество строк со звездочками

dataSize    equ     1024                    ; максимальный размер буфера для строки вывода
output      resb    dataSize                ; буфер для строки

sys_write   equ     1
sys_exit    equ     60
