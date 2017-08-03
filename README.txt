Xem chi tiết tại đây :
//https://github.com/NickChungVietNam/UART_ARDUINO
//http://arduino.vn/tutorial/1471-truyen-cac-so-kieu-long-int-float-trong-giao-tiep-serial-uart
Đây là thư viện dành cho giao tiếp Serial giữa 2 board arduino dùng để truyền nhận tất cả các kiểu số và kí tự
Công việc của nó cũng khá đơn giản!

Để truyền: Ví dụ để truyền số 12345 kiểu int, như ta đã biết trên arduino kiểu int có cỡ là 2 byte, ta sẽ tách 2 byte lưu trữ của biến này thành từng byte rồi xuất ra đường truyền.

Để nhận: Ta sẽ làm ngược lại là ghép 2 byte đã nhận về một số kiểu int.
