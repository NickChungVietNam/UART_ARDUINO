// Tác giả :Thái Sơn ( Nick Chung) - arduino.vn 14/2/2017
//xem mạch nối (hình ảnh )tại thư mục chứa file này
//Bạn đang dùng bản nâng cấp 13/6/2017
// hỗ trợ cho tất cả các phiên bản arduino, ESP8266, ESP32

#include "UART_ARDUINO.h"
UART Nhan;// nhận
byte button=5;// 
void setup() {
  Nhan.begin(9600);// baud: 200 -> 250,000.
pinMode(13,HIGH);// PIN 13 OUT CHO LED
  pinMode(button ,INPUT_PULLUP);
    //sử dụng một nút ấn (button) nối với pin 5 và nguồn âm
    // nhấn nút để yêu cầu mạch phát trả về dữ liệu
}
uint32_t Num;

void loop() {
if(digitalRead(button)==0){
    // nhấn nút để yêu cầu mạch phát trả về dữ liệu
    delay(300);//chống nhiễu
    Nhan.send_pass("abc",3);
    //máy chủ gửi một mật khẩu yêu cầu là : abc
    // 3 : là số lượng chữ cái
    //(do đó mật khẩu càng ngắn càng tốc độ nhanh hơn nhưng cũng dễ bị sai hơn(do bị trùng với số của dữ liệu))
}
  if(Serial.available()>=sizeof(Num)){
    Num=Nhan.read_uint32_t();
    if(Num==123456789){
      digitalWrite(13,1);// bật đèn, báo hiệu test thành công.
    }
  }
}//loop

//https://github.com/NickChungVietNam/UART_ARDUINO
//http://arduino.vn/tutorial/1471-truyen-cac-so-kieu-long-int-float-trong-giao-tiep-serial-uart

