.model small
.stack 100h
.data
    ; khai bao
    ;msg1... :bien, vung nho
    ;db la bien byte , do dai 8 bit
    ; day la xau dung de xuong dong va ve dau dong
    ;13 la ky tu ve dau dong (CR - carriage return)
    ;10 la ky tu them dong moi (LF - Line feed)
    msg1 db 10,13, 'nhap so thu nhat: $' ; in ra dong thong bao
    msg2 db 10,13, 'nhap so thu hai: $' 
    msg3 db 10,13, 'tong hai so la: $' 

    ; khai bao bien
    num1 db ?
    num2 db ?
    sum db ?
.code
    ; lay du lieu tu data vao DS
    mov ax, @data
    mov ds, ax

    ;xuat thong bao thu nhat
    ;lenh int 21h / ah =9 - output of string at ds:dx. string must be terminated by '$'
    ;nghia la xuat ra mot chuoi o dia chi ds:dx va phai ket thuc bang dau $
    ;lenh lea: lay dia chi cua bien gan vao dx de thuc hien leng int 21h
    ;cach thay the lenh lea:
    ;mov dx, offset msg1
    ;mov ah, 9
    ;int 21h
    mov ah, 9h
    lea dx, msg1
    int 21h

    ;nhap ky tu ban phim
    ; int 21h/ ah = 1 - read character from standard input, with echo, result is stored in AL. 
    ; if there is no character in the keyboard buffer, the function waits until any key is pressed
    ; ket qua se luu vao trong thanh ghi al, nhung thanh ghi al se thay doi lien tuc trong thoi gian chay chuong trinh
    ; de luu ket qua tron al can khai bao mot vung nho khac de luu
    mov ah, 1h
    int 21h
    sub al, 30h
    mov num1, al

    mov ah, 9h
    lea dx, msg2
    int 21h

    mov ah, 1h
    int 21h
    sub al, 30h
    mov num2, al

    ;xuat thong bao tinh tong
    mov ah, 9h
    lea dx, msg3
    int 21h


    ;tinh tong
    mov al, num1
    mov bl, num2
    add al, bl
    mov sum, al

    ;xuat ket qua
    ; xuat 1 ky tu ra man hinh
    ;ky tu xuat ra man hinh can phai nam trong thanh ghi dl
    ; int 21h / ah = 2 - write character to standard output
    ; entry : DL character to write, after execution AL =DL

    mov ah, 2h
    add sum, 30h 
    mov dl, sum
    int 21h

    
    ; lenh thoat chuong trinh : dung lenh ngat 4ch
    ; int 21h / ah = 4ch - return control to the operating system (stop program)
    mov ah, 4ch
    int 21h

end