// Tác giả :Thái Sơn ( Nick Chung) - arduino.vn 14/2/2017
//xem mạch nối (hình ảnh )tại thư mục chứa file này
#include "UART_ARDUINO.h"
UART Nhan;// nhận
void setup() {
  Nhan.begin(9600);// baud: 200 -> 250,000.
pinMode(13,OUTPUT);// PIN 13 OUT CHO LED
   digitalWrite(13,LOW);
    
}
uint8_t nhiet_do;
uint16_t do_am;
int32_t toc_do;
uint32_t do_cao;
float toa_do;
void reset(){

  nhiet_do=0;
  do_am=0;
  toc_do=0;
  do_cao=0;
  toa_do=0;
}
bool cho_phep_bat_dau=false;
void loop() {
  
  // ỨNG DỤNG NÀY DÙNG ĐỂ ĐỌC LIÊN TỤC GIÁ TRỊ TRẢ VỀ MÀ KHÔNG CẦN LỜI GỌI YÊU CẦU 
  if(cho_phep_bat_dau==false){
  if(Nhan.find_start_pass("ABCDEF",6,30)){
   
   cho_phep_bat_dau=true;
  }
  }
  while(cho_phep_bat_dau){
   
if(nhan_du_lieu(&nhiet_do, &do_am, &toc_do,&do_cao, &toa_do)){
  
  if((nhiet_do==25)&&(do_am==60)&&(toc_do==2700)){
    digitalWrite(13,HIGH);//BẬT ĐÈN BÁO HIỆU TEST THÀNH CÔNG
    delay(500);
    digitalWrite(13,LOW);
    
  reset();
  }
  
  cho_phep_bat_dau=false;
  
}//if lớn

  }
  
}//loop

bool nhan_du_lieu(uint8_t *a, uint16_t *b, int32_t *c, uint32_t *d,float *e){
  //b1: tìm kích thước để kiểm tra gói tin truyền về đã đủ chưa
  uint32_t kich_co_goi_tin=sizeof(*a)+sizeof(*b)+sizeof(*c)+sizeof(*d)+sizeof(*e);
    if(Serial.available()>=kich_co_goi_tin){
      //đã nhận đủ gói tin
      /////////////
      (*a)=Nhan.read_uint8_t();//1
      (*b)=Nhan.read_uint16_t();//2
      (*c)=Nhan.read_int32_t();//4
      (*d)=Nhan.read_uint32_t();//4
      (*e)=Nhan.read_float();//4

      /////////////
     // Nhan.clear_buffer();// reset lại bộ nhớ đệm
      return true;// cuối cùng trả về true báo đã nhận đủ và hoàn tất
    }else{
      return false;// báo chưa đủ 
    }
    
}
//https://github.com/NickChungVietNam/UART_ARDUINO
//http://arduino.vn/tutorial/1471-truyen-cac-so-kieu-long-int-float-trong-giao-tiep-serial-uart
