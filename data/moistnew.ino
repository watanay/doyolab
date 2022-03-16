#include <Servo.h>

Servo myservo;
int deg;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,OUTPUT);
   
  deg=0;
  myservo.attach(11);
  myservo.write(0);
}

void loop(){
 Serial.println(analogRead(A1));  
 delay(1000);

 // put your main code here, to run repeatedly:
  int val=0;
  if (deg>180){
    deg=0;
  }
  val=analogRead(A1);
  Serial.println(val);
  // 数値が430以上の時（乾いているとき）:
  if (val>600){
   // サーボが何度動くか:
    myservo.write(185);
   // 湿っているときの数値:
  }if (val<30){
    myservo.write(160);
  }
  delay(10);

}
