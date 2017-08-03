// Tác giả :Thái Sơn ( Nick Chung) - arduino.vn 14/2/2017
//xem mạch nối (hình ảnh )tại thư mục chứa file này
//Bạn đang dùng bản nâng cấp 13/6/2017
// hỗ trợ cho tất cả các phiên bản arduino, ESP8266, ESP32

#include "UART_ARDUINO.h"
UART NHAN;
void setup() {
  Gui.begin(9600);// baud: 200 -> 250,000.
pinMode(13, OUTPUT);
   digitalWrite(13,LOW);
}

void loop() {
  
  if(NHAN.find_start_pass("abcd",4,30)==true){
  	// hàm này dùng để tìm một chuỗi kí tự 
  	//khác với hàm hàm check_pass(); hàm này sẽ tìm sự xuất hiện của một chuỗi có nghĩa trong một chuỗi bất kì
  	// trả về true nếu nó tìm thấy
  	// ví dụ chuỗi định nghĩa là "abcd" , chuỗi nhập vào là "aggbds" -> trả về false 
  	// chuỗi nhập vào là " 12397abcd8383" -> trả về true khi thấy có "abcd"
  	//ta dùng hàm này để bắt đầu một công việc nào đó
  	// n=4 (n max =10) : là số kích thước(byte) của chuỗi (lớn nhất là 10 vì vòng lặp sẽ bị hụt nếu lớn hơn do tiêu tốn quá nhiều thời gian)
  	// n càng nhỏ thì kiểm tra càng nhanh, n quá lớn sẽ không thể đáp ứng tốc độ 
  	//count_max= 40 là số byte lớn nhất cần đọc, nếu đọc >40 byte mà chưa tìm thấy chuỗi giống thì trả về false
// có thể thử hàm này bằng cách nhập kí tự trên màn hình Serial Monitor
   
   digitalWrite(13,HIGH);//
  }else{
   digitalWrite(13,LOW);
 
  }
}


//https://github.com/NickChungVietNam/UART_ARDUINO
//http://arduino.vn/tutorial/1471-truyen-cac-so-kieu-long-int-float-trong-giao-tiep-serial-uart


