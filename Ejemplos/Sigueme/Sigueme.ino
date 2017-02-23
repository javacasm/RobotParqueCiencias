#include <Servo.h>
#include <Ultrasonic.h>

#define PIN_ECHO      8
#define PIN_TRIG      9

#define SERVO_DRCHA   11 
#define SERVO_IZDA    10

// Comando para los servos

#define ATRAS_DRCHA         180
#define ATRAS_IZDA          75
#define PARA              90
#define ADELANTE_DRCHA      0
#define ADELANTE_IZDA     115

#define UMBRAL         25
#define MARGEN          3

Servo servoIzda,servoDrcha;

Ultrasonic Ultrasonic(PIN_TRIG, PIN_ECHO);

void setup() {
  Serial.begin(9600);

  servoIzda.attach(SERVO_IZDA);
  servoDrcha.attach(SERVO_DRCHA);

}

void atras()
{
    servoDrcha.write(ATRAS_DRCHA);
    servoIzda.write(ATRAS_IZDA);  
}

void adelante()
{
    servoDrcha.write(ADELANTE_DRCHA);
    servoIzda.write(ADELANTE_IZDA);  
}

void parar()
{
    servoDrcha.write(PARA);
    servoIzda.write(PARA);
}

void loop() {
  int distancia=Ultrasonic.distanceRead();
  Serial.println(String("Distancia: ")+distancia+String("cm"));

  if(distancia<UMBRAL-MARGEN)
  {
    atras();
  } else if (distancia>UMBRAL+MARGEN)
  {
    adelante();
  } else {
    parar();
  }
  
  delay(200);

}
