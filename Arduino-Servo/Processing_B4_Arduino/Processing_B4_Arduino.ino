//Thư viện
#include <Servo.h>

//Khai báo servo
Servo myser;
int serpin=13;

int deg, dis;     //Biến lưu độ và khoảng cách (degree,distance)
int trig = 9;     //Chân trig của HC-SR04
int echo = 10;     //Chân echo của HC-SR04

void setup()
{
  myser.attach(serpin);   //Kết nối servo
  pinMode(trig,OUTPUT);   //Chân trig sẽ phát tín hiệu
  pinMode(echo,INPUT);    //Chân echo sẽ nhận tín hiệu
  Serial.begin(9600);     //Set Baudrate
}

void loop() 
{
 //Quay từ 0 độ đến 180 độ
 for (deg=0;deg<=180;deg++)
 {
  myser.write(deg);         //Quay servo đến deg độ
  dis=distance();           //dis gán = khoảng cách
  Serial.print(deg);        //Xuất ra serial cho Processing đọc
  Serial.print(",");
  Serial.print(dis);
  Serial.print(".");
  Serial.println("");
  delay(50);
 }

 //Quay từ 180 độ về 0 độ (tương tự ở trên)
 for (deg=180;deg>=0;deg--)
 {
  myser.write(deg);
  dis=distance();
  Serial.print(deg);
  Serial.print(",");
  Serial.print(dis);
  Serial.print(".");
  Serial.println("");
  delay(50);
 }
}

int distance()
{
    unsigned long duration; //Biến đo thời gian
  
    digitalWrite(trig,0);   //Tắt chân trig
    delayMicroseconds(2);   //Chờ 2ms
    digitalWrite(trig,1);   //Phát xung từ chân trig
    delayMicroseconds(5);   //Xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   //Tắt chân trig
    
    duration = pulseIn(echo,HIGH);  //Đo độ rộng xung HIGH ở chân echo. 
    return int(duration/2/29.412);  //Tính khoảng cách đến vật. 
}
