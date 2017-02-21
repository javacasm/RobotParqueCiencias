#include <Servo.h>



#define BLANCO 0
#define NEGRO  1

#define SENSOR_DRCHA  5
#define SENSOR_IZDA   4

#define SERVO_DRCHA   7 
#define SERVO_IZDA    8


// Comando para los servos
#define ATRAS         0
#define PARA          90
#define ADELANTE      180

Servo servoIzda,servoDrcha;

void setup() {
  pinMode(SENSOR_DRCHA,INPUT);
  pinMode(SENSOR_IZDA,INPUT);

  Serial.begin(9600);

  servoIzda.attach(SERVO_IZDA);
  servoDrcha.attach(SERVO_DRCHA);
}

void loop() {
  
  Serial.println(String("izda:")+digitalRead(SENSOR_IZDA)+String(" drcha:")+digitalRead(SENSOR_DRCHA));

  if(digitalRead(SENSOR_IZDA)==BLANCO)
  {
    servoIzda.write(PARA);
  }
  else
  {
    servoIzda.write(ADELANTE);
  }

  if(digitalRead(SENSOR_DRCHA)==BLANCO)
  {
    servoDrcha.write(PARA);
  }
  else
  {
    servoDrcha.write(ATRAS);
  }


  if((digitalRead(SENSOR_DRCHA)==BLANCO) && (digitalRead(SENSOR_IZDA)==BLANCO))
  {   // Me he perdido un poco, voy hacia atras
    servoDrcha.write(ADELANTE);
    servoIzda.write(ATRAS);  
    delay(400);
  }
}
