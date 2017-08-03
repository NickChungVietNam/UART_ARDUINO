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
uint8_t nhiet_do;
uint16_t do_am;
int32_t toc_do;
uint32_t do_cao;
float toa_do;

void loop() {
if(digitalRead(button)==0){
    // nhấn nút để yêu cầu mạch phát trả về dữ liệu
    delay(300);//chống nhiễu
    Nhan.send_pass("abc",3);
    //máy chủ gửi một mật khẩu yêu cầu là : abc
    // 3 : là số lượng chữ cái
    //(do đó mật khẩu càng ngắn càng tốc độ nhanh hơn nhưng cũng dễ bị sai hơn(do bị trùng với số của dữ liệu))
}
  
if(nhan_du_lieu(&nhiet_do, &do_am, &toc_do,&do_cao, &toa_do)==true){
  
    if(nhiet_do==25){
      if(do_am==60){
        if(toc_do==2700){
        if(do_cao==3600){
        if(toa_do==12.1234){
          digitalWrite(13,1);//bật đèn để báo test thử nghiệm thành công (số truyền qua là chính xác)
         }
         }
        }
       }
    }
}//if lớn
}//loop
bool nhan_du_lieu(uint8_t *a, uint16_t *b, int32_t *c, uint32_t *d,float *e){
  //b1: tìm kích thước để kiểm tra gói tin truyền về đã đủ chưa
  uint32_t kich_co_goi_tin=sizeof(*a)+sizeof(*b)+sizeof(*c)+sizeof(*d)+sizeof(*e);
    if(Serial.available()>=kich_co_goi_tin){
      //đã nhận đủ gói tin
      /////////////
      (*a)=Nhan.read_uint8_t();
      (*b)=Nhan.read_uint16_t();
      (*c)=Nhan.read_int32_t();
      (*d)=Nhan.read_uint32_t();
      (*e)=Nhan.read_float();

      /////////////
     // Nhan.clear_buffer();// reset lại bộ nhớ đệm
      return true;// cuối cùng trả về true báo đã nhận đủ và hoàn tất
    }else{
      return false;// báo chưa đủ 
    }
    
}

//https://github.com/NickChungVietNam/UART_ARDUINO
//http://arduino.vn/tutorial/1471-truyen-cac-so-kieu-long-int-float-trong-giao-tiep-serial-uart
