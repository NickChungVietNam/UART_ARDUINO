
/*
< Tác giả PhùngThái Sơn, Hà NAM, Việt Nam. Trang web: arduino.vn/NickChung>
<Mình xin giữ bản quyền tài liệu này, bạn có thể sử dụng tài cho mọi mục đích nhưng cần trích thông tin tác giả, cảm ơn bạn đã đón đọc, hi vọng bài viết thực sự có ích cho bạn!>


//ý tưởng của mình là dùng thêm SoftwareSerial để dùng nhiều cổng Serial hơn
// được đến đâu hay đến đấy vậy
#include <SoftwareSerial.h>
#define CHANEL_0 0
// kênh 0 chính là dùng Serial tại 2 cổng 0 và 1
#define CHANEL_1 1
#define CHANEL_2 2
#define CHANEL_3 3
#define CHANEL_4 4
#define CHANEL_5 5
#define CHANEL_6 6
#define PORT_1_RX_2_TX_3 SoftwareSerial CHANEL_1(2, 3); // RX, TX
#define PORT_2_RX_4_TX_5 SoftwareSerial CHANEL_2(4, 5); // RX, TX
#define PORT_3_RX_6_TX_7 SoftwareSerial CHANEL_3(6, 7); // RX, TX
#define PORT_4_RX_8_TX_9 SoftwareSerial CHANEL_4(8, 9); // RX, TX
#define PORT_5_RX_10_TX_11 SoftwareSerial CHANEL_5(10, 3); // RX, TX
#define PORT_6_RX_12_TX_13 SoftwareSerial CHANEL_6(2, 3); // RX, TX
*/
class UART
{
  public:
/*
  UART(byte chanel){
    Chon_kenh=chanel;
    // constructor
  };
*/
  UART(){
    // constructor
  };
  void begin(uint32_t muc_baud){
    Serial.begin(muc_baud);
  };
void write_double(double value);
double read_double();
void write_float(float value);
float read_float();
void write_int8_t(int8_t value);
int8_t read_int8_t();
void write_uint8_t(uint8_t value);
uint8_t read_uint8_t();
void write_int16_t(int16_t value);
int16_t read_int16_t();
void write_uint16_t(uint16_t value);
uint16_t read_uint16_t();
void write_uint32_t(uint32_t value);
uint32_t read_uint32_t();
void write_int32_t(int32_t value);
int32_t read_int32_t();
void write_char(unsigned char value);
unsigned char read_char();
void write_string(unsigned char value[], uint32_t n );
void  read_string(unsigned char *value, uint32_t n);
void send_pass(unsigned char value[], uint32_t n );
bool check_pass(unsigned char value[], uint32_t n );
void write_string( char value[], uint32_t n );
void  read_string( char *value, uint32_t n);

void write_string_delay(unsigned char value[], uint32_t n,  uint16_t delay_us);

void write_string_delay( char value[], uint32_t n,  uint16_t delay_us);


void send_pass(char value[], uint32_t n );
bool check_pass( char value[], uint32_t n );
void clear_buffer();
bool find_start_pass(unsigned char value[], uint32_t n, uint32_t count_byte_max );

bool find_start_pass( char value[], uint32_t n, uint32_t count_byte_max );

private:/*
  byte Chon_kenh;// chọn kênh
  void GHI(unsigned char gia_tri){
    Serial.write(gia_tri);
  }
  unsigned char DOC(){
   return Serial.read();
  }*/
};// class




void UART::write_double(double value)
{
   byte *p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){ 
     Serial.write(*p++);    
    
   }
}

double UART::read_double()
{
  uint8_t C[8];
double value = 0.0;
if(Serial.available()>=sizeof(value)){

Serial.readBytes(C, sizeof(value));
   
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){

      *p++=C[i];
   }
   return value;
}else{
  return 0;
}
}
void UART::write_float(float value)
{
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
Serial.write(*p++);
   }
}

float UART::read_float()
{uint8_t C[4];
float value = 0.0;
if(Serial.available()>=sizeof(value)){
Serial.readBytes(C, sizeof(value));
   
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
      *p++=C[i];
   }
   return value;
}else{
  return 0;
}
}

void UART::write_int8_t(int8_t value){
  
  // số cần gửi có giá trị trong khoảng -128->127
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
Serial.write(*p++);
   }
}

int8_t UART::read_int8_t(){
  //số trả về có giá trị trong khoảng -128 - 127
  uint8_t C[1];
int8_t value = 0;
if(Serial.available()>=sizeof(value)){
Serial.readBytes(C, sizeof(value));
   
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
      *p++=C[i];
   }
   return value;
}else{
  return 0;
}
}



void UART::write_uint8_t(uint8_t value){
  
  // số cần gửi có giá trị trong khoảng 0 ->255
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
Serial.write(*p++);
   }
}

uint8_t UART::read_uint8_t(){
  //số trả về có giá trị trong khoảng 0->255
  uint8_t C[1];
uint8_t value = 0;
if(Serial.available()>=sizeof(value)){
Serial.readBytes(C, sizeof(value));
   
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
      *p++=C[i];
   }
   return value;
}else{
  return 0;
}
}


void UART::write_int16_t(int16_t value){
  
  // số cần gửi có giá trị trong khoảng -32768 -> 32767
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
Serial.write(*p++);
   }
}

int16_t UART::read_int16_t(){
  //số trả về có giá trị trong khoảng -32768 -> 32767
  uint8_t C[2];
int16_t value = 0;
if(Serial.available()>=sizeof(value)){
Serial.readBytes(C, sizeof(value));
   
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
      *p++=C[i];
   }
   return value;
}else{
  return 0;
}
}



void UART::write_uint16_t(uint16_t value){
  
  // số cần gửi có giá trị trong khoảng 0->65535
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
Serial.write(*p++);
   }
}

uint16_t UART::read_uint16_t(){
  //số trả về có giá trị trong khoảng  0->65535
  uint8_t C[2];
uint16_t value = 0;
if(Serial.available()>=sizeof(value)){
Serial.readBytes(C, sizeof(value));
   
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
      *p++=C[i];
   }
   return value;
}else{
  return 0;
}
}

void UART::write_uint32_t(uint32_t value){
  
  // số cần gửi có giá trị trong khoảng 0->4,294,967,295
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
Serial.write(*p++);
   }
}


uint32_t UART::read_uint32_t(){
  //số trả về có giá trị trong khoảng  0->4,294,967,295
  uint8_t C[4];
uint32_t value = 0;
if(Serial.available()>=sizeof(value)){
Serial.readBytes(C, sizeof(value));
   
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
      *p++=C[i];
   }
   return value;
}else{
  return 0;
}
}



void UART::write_int32_t(int32_t value){
  
  // số cần gửi có giá trị trong khoảng  -2,147,483,648 -> 2,147,483,647
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
Serial.write(*p++);
   }
}


int32_t UART::read_int32_t(){
  //số trả về có giá trị trong khoảng  -2,147,483,648 -> 2,147,483,647
  uint8_t C[4];
int32_t value = 0;
if(Serial.available()>=sizeof(value)){
Serial.readBytes(C, sizeof(value));
   
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
      *p++=C[i];
   }
   return value;
}else{
  return 0;
}
}



void UART::write_char(unsigned char value){
  
  // số cần gửi có giá trị trong khoảng  0->255 , tương ứng 256 kí tự trong bảng mã ASCII
  // mỗi lần chỉ gửi được 1 kí tự
   byte* p = (byte*)(void*)&value;
   for (int i = 0; i < sizeof(value); i++){
Serial.write(*p++);
   }
}


unsigned char UART::read_char(){
  
  // số cần gửi có giá trị trong khoảng  0->255 , tương ứng 256 kí tự trong bảng mã ASCII
  // mỗi lần chỉ gửi được 1 kí tự
 unsigned char C;
if(Serial.available()>=1){
C=Serial.read();
   
   return C;
}else{
  return 0;
}
}

void UART::send_pass(unsigned char value[], uint32_t n ){
  //n là số kí tự cần lấy

  write_string(value,n);// gửi một chuỗi chữ để máy thu nhận dạng
//clear_buffer();
}

void UART::send_pass( char value[], uint32_t n ){
  //n là số kí tự cần lấy

  write_string(value,n);// gửi một chuỗi chữ để máy thu nhận dạng
//clear_buffer();
}

bool UART::find_start_pass(unsigned char value[], uint32_t n, uint32_t count_byte_max ){
//tìm cho tới khi gặp một kí tự giống với chuỗi nhập vào thì trả về true
unsigned char Check[n];// tạo một mảng để làm buffer
for( uint32_t i=0; i<n; i++){
  Check[i]=0;
  }
uint32_t count=0;
uint32_t count_tim_ra=0;// đếm số lần kiểm tra đúng
while( count <count_byte_max ){// nếu nhỏ hơn số byte muốn duyệt
 
  if(Serial.available()){
  
    count_tim_ra=0;
Check[n-1]=(unsigned char)Serial.read();// đọc 1 byte và nhập vào ô cuối cùng
for( uint32_t i=0; i<n; i++){
  if( Check[i]==value[i]){
count_tim_ra++;
    continue;// nếu dữ liệu trùng thì kiểm tra tiếp
  }else{
    if(i==n-1){
       continue;
    }
    Check[i]=Check[i+1];// nếu không thì dịch dữ liệu
  
  }

}
if(count_tim_ra==n){
// kết thúc for mà không có lỗi (trùng khớp)
return true;// thì thoát ngay
}
count++;
}//if

}// while
return false;//
}

bool UART::find_start_pass( char value[], uint32_t n, uint32_t count_byte_max ){
//tìm cho tới khi gặp một kí tự giống với chuỗi nhập vào thì trả về true
 char Check[n];// tạo một mảng để làm buffer
for( uint32_t i=0; i<n; i++){
  Check[i]=0;
  }
uint32_t count=0;
uint32_t count_tim_ra=0;// đếm số lần kiểm tra đúng
while( count <count_byte_max ){// nếu nhỏ hơn số byte muốn duyệt
 
  if(Serial.available()){
  
    count_tim_ra=0;
Check[n-1]=( char)Serial.read();// đọc 1 byte và nhập vào ô cuối cùng
for( uint32_t i=0; i<n; i++){
  if( Check[i]==value[i]){
count_tim_ra++;
    continue;// nếu dữ liệu trùng thì kiểm tra tiếp
  }else{
    if(i==n-1){
       continue;
    }
    Check[i]=Check[i+1];// nếu không thì dịch dữ liệu
  
  }

}
if(count_tim_ra==n){
// kết thúc for mà không có lỗi (trùng khớp)
return true;// thì thoát ngay
}
count++;
}//if

}// while
return false;//
}

bool UART::check_pass(unsigned char value[], uint32_t n ){
   //n là số kí tự cần lấy
if(Serial.available()>=n){
  for(uint32_t i=0; i<n; i++){
    if( value[i]==Serial.read()){
      continue;// nếu dữ liệu trùng thì kiểm tra tiếp
    }else{
      //nếu dữ liệu khác thì dừng ngay và báo 
      return false;
    }
  }
  //clear_buffer();
  return true;// kết thúc kiểm tra mà đúng hết thì báo đúng
}else{

return false;
}
  
}
bool UART::check_pass(char value[], uint32_t n ){
   //n là số kí tự cần lấy
if(Serial.available()>=n){
  for(uint32_t i=0; i<n; i++){
    if( value[i]==Serial.read()){
      continue;// nếu dữ liệu trùng thì kiểm tra tiếp
    }else{
      //nếu dữ liệu khác thì dừng ngay và báo 
      return false;
    }
  }
  //clear_buffer();
  return true;// kết thúc kiểm tra mà đúng hết thì báo đúng
}else{

return false;
}
  
}
void UART::write_string(unsigned char value[], uint32_t n ){
  // gửi một mảng kí tự
  //n là số kí tự cần lấy 

   for (int i = 0; i < n; i++){
Serial.write(value[i]);
   }
}

void UART::write_string_delay(unsigned char value[], uint32_t n,  uint16_t delay_us){
  // gửi một mảng kí tự
  //n là số kí tự cần lấy 

   for (int i = 0; i < n; i++){
Serial.write(value[i]);
delayMicroseconds(delay_us);
   }
}


void UART::write_string_delay( char value[], uint32_t n,  uint16_t delay_us){
  // gửi một mảng kí tự
  //n là số kí tự cần lấy 

   for (int i = 0; i < n; i++){
Serial.write(value[i]);
delayMicroseconds(delay_us);
   }
}
void UART::write_string( char value[], uint32_t n ){
  // gửi một mảng kí tự
  //n là số kí tự cần lấy 

   for (int i = 0; i < n; i++){
Serial.write(value[i]);
   }
}
void  UART::read_string(unsigned char *value, uint32_t n){
  //n là số kí tự cần lấy

if(Serial.available()>=n){
  for(uint32_t i=0; i<n; i++){
    *(value +i)=Serial.read();
  }
}
}
void  UART::read_string( char *value, uint32_t n){
  //n là số kí tự cần lấy

if(Serial.available()>=n){
  for(uint32_t i=0; i<n; i++){
    *(value +i)=Serial.read();
  }
}
}

void UART::clear_buffer(){
// xóa toàn bộ dữ liệu đang có trên buffer
  // bộ nhớ buffer có kích thước tối đa 64 byte
  if(Serial.available()>=1){
  uint8_t kich_thuoc=Serial.available();
  uint8_t C[64];
  Serial.readBytes(C, kich_thuoc);
  //Bằng cách sử dụng lệnh đọc thì toàn bộ dữ liệu sẽ bị xóa khi đọc xong
   }
}