#include <Servo.h>

const int servoPin = 9;

Servo servo;
int pos;

String readSerial(){
  String conteudo = "";

  if (Serial.available() > 0) {
    conteudo = Serial.readString();
  }

  delay(10);
  return conteudo;
}

void abre(){
  delay(1000);
  for(pos = 180; pos >= 0; pos--){
    servo.write(pos);
    delay(15);
  }

  delay(300);
  fecha();
}

void fecha(){
  for(pos = 0; pos < 180; pos++){
    servo.write(pos);
    delay(15);
  }
}

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(180);
}

void loop() {
  String recebido = readSerial();
  if (recebido == "open"){
    Serial.println("Alimentando o pet.");
    abre();
    recebido = ""
  }

  delay(1000)
}
