section .bss					;инициализирование памяти
	arr resb 64					;хранятся цифры числа
	arrPos resq 1				;адрес ячейки массива arr
	num resd 1					;хранится число
section .data
	i db 3
	a db 0					
section .text
	global _start

_start:
	rdrand rax			;Получить случайное целое типа int.
	mov r12, 0ffffffffh
	and rax, r12
	mov [num], rax
	call _printBinary 	;Выводить двоичное представление на экран.
		
	mov r8, [num]		;Упорядочить байты числа по возрастанию их рангов.
_bSort:
	mov r9, 0		
	mov byte [a], 0
_comparison:			
	mov rax, 8
	mul r9
	mov cl, al	
	mov rax, 0xffff
	shl rax, cl			 
	and rax, r8			; rax - i-й байт, (i + 1)-й байт
	shr rax, cl			
	mov bx, ax			

	and rax, 0ffh		; rax - i-й байт
	xor rdx, rdx		;			
	mov r10, 16		
	div r10				;В dl хранит младшая тетрада, в al хранит старшая тетрада
	not dl				;Импликация 		
	or dl, al			; 
	mov r11b, dl		;r11b - ганг i-о байта 
	mov al, bh			
	xor rdx, rdx		; 						
	div r10				; 
	not dl				; 	
	or dl, al			; dl - ганг (i+1)-о байта
		
	cmp r11b, dl		;Проверить условие.
	jle _noswap			;Если ранг маленького байта больше чем, ранг большего байта
;_swap:			
	rol bx, 8			;то поменять местами два байта.
	and rbx, 0ffffh	
	shl rbx, cl
	mov rax, 0ffffh
	shl rax, cl
	not rax
	and r8, rax
	or r8, rbx
	mov rax, r8
	mov byte[a], 1
_noswap:
	inc r9
	cmp r9b, [i]
	jnz _comparison
	cmp byte [a], 0			;проверка конца цикла
	jnz _bSort
	
	mov rax, r8
	call _printBinary		;Выводить на экран результат преобразования.
	mov rax, 60 			;Завершить программу.
	xor rdi, rdi
	syscall

_printBinary:
	mov rcx, arr 			
	mov rbx, 10				; номер символа «перенос строки» в таблице ASCII
	mov [rcx], rbx			
	inc rcx 				 
	mov [arrPos], rcx 		 
_pushDigit:
	mov rdx, 0				
	mov rbx, 2				;основание системы счисления
	div rbx					
	push rax				
	add rdx, 48				;перевод символов в цифры
	mov rcx, [arrPos] 		
	mov [rcx], dl			;Занесение цифр из регистра в массив
	inc rcx
	mov [arrPos], rcx		
	pop rax					 
	cmp rax, 0				
	jne _pushDigit
_printDigit:
	mov rcx, [arrPos]		;извлечение цифр из массива
	mov rax, 1
	mov rdi, 1
	mov rsi, rcx
	mov rdx, 1
	syscall					;вывод на экран
	mov rcx, [arrPos]
	dec rcx
	mov [arrPos], rcx
	cmp rcx, arr			;проверка конца цикла
	jge _printDigit
	ret



