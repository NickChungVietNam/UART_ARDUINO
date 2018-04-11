/*thông báo ngày 11/4/2018
Bài viết này đã cũ ,Thư viện hiện đã được chỉnh sửa để truyền tin an toàn hơn theo link nàyi :

<link bài mới> http://arduino.vn/tutorial/5897-thu-vien-truyen-du-lieu-bat-ky-byte-long-float-double-theo-goi-tin-cho-arduino

Bài viết này được giữ lại dưới dạng tài liệu tham khảo.



*/

// Tác giả :Thái Sơn - arduino.vn 14/2/2017
//xem mạch nối (hình ảnh )tại thư mục chứa file này
//Bạn đang dùng bản nâng cấp 13/6/2017
// hỗ trợ cho tất cả các phiên bản arduino, ESP8266, ESP32

#include "UART_ARDUINO.h"
UART Gui;
void setup() {
  Gui.begin(9600);// baud: 200 -> 250,000.

}
uint8_t nhiet_do;
uint16_t do_am;
int32_t toc_do;
uint32_t do_cao;
float toa_do;

void loop() {
  //ỨNG DỤNG NÀY SẼ GỬI LIÊN TỤC DỮ LIỆU MÀ KHÔNG CẦN MÁY CHỦ YÊU CẦU
   Gui.write_string("ABCDEF",6);// THÔNG ĐIỆP BẮT ĐẦU
   delay(100);//delay ms để máy thu kịp chuẩn bị
    gui_du_lieu(25,60,2700,3600,12.1234);
  
}
void gui_du_lieu(uint8_t a, uint16_t b, int32_t c, uint32_t d,float e){
  // lưu ý : gói tin truyền đi có kích cỡ lớn nhất là 64 byte
Gui.write_uint8_t(a); // cần 1 byte
Gui.write_uint16_t(b); // cần 2 byte
Gui.write_int32_t(c); // cần 4 byte
Gui.write_uint32_t(d); // cần 4 byte
Gui.write_float(e); // cần 4 byte
// tổng cộng cần 15 byte < (max =64)
  
}

//https://github.com/NickChungVietNam/UART_ARDUINO
//http://arduino.vn/tutorial/1471-truyen-cac-so-kieu-long-int-float-trong-giao-tiep-serial-uart
