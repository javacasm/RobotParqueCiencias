#include <Servo.h>

Servo sLeft,sRight;

void setup() {
  sLeft.attach(10);
  sRight.attach(11);
  Serial.begin(9600);
}

void loop() {
 for(int i=0;i<180;i+=10)
 {
    Serial.println(i);
    sLeft.write(i);
    sRight.write(180-i);
    delay(2000);
 }
  
}
