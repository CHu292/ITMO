.model small
.stack 100
.data
    tbao1 db "hay nhap vao mot ky tu: $" ; khoi tao xau
    tbao2 db 13,10, "ky tu da nhap: $"
    output db ? ;khoi tao bien ky tu khong co gia tri ban dau
.code
main proc
    mov ax, @data
    mov ds, ax
    
    lea dx, tbao1
    mov ah, 9
    int 21h
    
    ;nhap vao 1 ky tu tu ban phim
    mov ah, 1
    int 21h
    mov output, al
    ; gan gia tri vua nhap (duoc luu o al) vao output
    
    lea dx, tbao2 
    mov ah, 9
    int 21h
    
    lea dx, output
    mov ah, 9
    int 21h
    
    mov ah, 4ch
    int 21h
main endp
end