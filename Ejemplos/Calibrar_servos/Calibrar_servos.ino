#include <Servo.h>

Servo sLeft,sRight;

void setup() {
  sLeft.attach(10);
  sRight.attach(11);
  sLeft.write(90);
  sRight.write(90);
}

void loop() {
}
