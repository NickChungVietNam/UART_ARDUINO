// Tác giả :Thái Sơn ( Nick Chung) - arduino.vn 14/2/2017
//xem mạch nối (hình ảnh )tại thư mục chứa file này
//Bạn đang dùng bản nâng cấp 13/6/2017
// hỗ trợ cho tất cả các phiên bản arduino, ESP8266, ESP32

/*
Truyền số khác:
 Làm tương tự, 
void write_double() từ 2.2250738585072014 E – 308  đến 1.7976931348623158 E + 308.
void write_float();   từ 1.175494351 E – 38 đến 3.402823466 E + 38
void write_int8_t();  từ -128 đến 127
void write_uint8_t(); từ 0 đến 255
void write_int16_t();  từ -32768 đến 32767
void write_uint16_t(); từ 0 -> 65536
void write_uint32_t();từ 0 ->4,294,967,295
void write_int32_t(); từ -2,147,483,648 -> 2,147,483,647
Chú ý: trên arduino uno R3, kiểu float và double có cùng cỡ là 4 byte,(  giá trị   từ 1.175494351 E – 38 đến 3.402823466 E + 38);
Trên arduino Due, kiểu double mới có cỡ 8 byte.
Tốc độ truyền các số có kích thước lớn (byte) sẽ chậm hơn các số có kích thước nhỏ hơn (điều này là dĩ nhiên).!

*/



