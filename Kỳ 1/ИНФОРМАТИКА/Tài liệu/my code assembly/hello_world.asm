.model small   ;chuong trinh nay chon bo nho small
.stack 100     ;kich thuoc ngan xep la 100 byte
.data
    crlf db 13,10, '$' ;ky tu xuong dong
    varHello db 'Hello world$'
  
.code
main proc ; thu tuc chinh
    ; khoi tao ds
    mov ax, @Data ; khoi tao thanh ghi ds
    mov ds, ax ;tro thanh ghi ds ve dau doan data
    
    ;hien thi loi chao dung ham 9 cua int 21h
    mov ah, 9
    
    lea dx, varHello; dong in chuoi hello world
    int 21h
    
    mov ah, 4ch
    int 21h
main endp
end
