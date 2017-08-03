// Tác giả :Thái Sơn ( Nick Chung) - arduino.vn 14/2/2017
//xem mạch nối (hình ảnh )tại thư mục chứa file này
//Bạn đang dùng bản nâng cấp 13/6/2017
// hỗ trợ cho tất cả các phiên bản arduino, ESP8266, ESP32

#include "UART_ARDUINO.h"
UART Gui;
void setup() {
  Gui.begin(9600);// baud: 200 -> 250,000.

}
 char t[6]="ABCDEF";// truyền 1 kí tự trong bảng ASCII
void loop() {
  if(Gui.check_pass("abc",3)==true){
    // kiểm tra có yêu cầu từ máy chủ
   Gui.write_string("ACBDEF",6);
   // 6 có nghĩa là cỡ của chuỗi gồm 6 chữ cái
   //hoặc  Gui.write_string("ABCDEF",6);
  }
}

//https://github.com/NickChungVietNam/UART_ARDUINO
//http://arduino.vn/tutorial/1471-truyen-cac-so-kieu-long-int-float-trong-giao-tiep-serial-uart



