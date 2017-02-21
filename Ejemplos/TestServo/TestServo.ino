#include <Servo.h>

Servo sLeft,sRight;

void setup() {
  sLeft.attach(7);
  sRight.attach(8);

}

void loop() {
  sLeft.write(0);
  sRight.write(180);

  delay(5000);

  sLeft.write(90);
  sRight.write(90);


  delay(5000);

  sLeft.write(180);
  sRight.write(0);


}
