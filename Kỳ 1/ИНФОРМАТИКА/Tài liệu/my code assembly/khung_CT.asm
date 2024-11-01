.model small ;chế độ bộ nhớ
.stack 100h ; kích thước ngăn xếp
.data ; các dòng dưới data là khai báo
  ; khai báo dữ liệu
  ; ngoài các thanh ghi khai báo các biến tại đây
  
.code
.main Proc; 
  ; khởi tạo DS **
  ; bắt buộc phải có
  mov ax, @Data; khởi đầu thanh ghi ds
  mov ds, ax; trỏ thanh ghi ds về đầu đoạn data
  ; các lệnh của trương trình đặt tại đây
  
  ;trở về DOS dùng hàm ch của int 21h
  mov ah, 4ch
  int 21h
main endp
end
