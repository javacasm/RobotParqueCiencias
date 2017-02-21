void setup() {
pinMode(4,INPUT);
pinMode(5,INPUT);

Serial.begin(9600);
}

void loop() {
  Serial.println(String("4:")+digitalRead(4)+String(" 5:")+digitalRead(5));
  delay(200);
}
