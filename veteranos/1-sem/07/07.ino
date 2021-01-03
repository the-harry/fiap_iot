#include <Servo.h>

#define PIR 7
const int SERVO = 9;

Servo servo;
int pos;
int movimento;

void abre() {
  delay(1000);
  for(pos = 180; pos >= 0; pos--){
    servo.write(pos);
    delay(15);
  }

  delay(300);
  fecha();
}

void fecha() {
  for(pos = 0; pos < 180; pos++){
    servo.write(pos);
    delay(15);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  servo.attach(SERVO);
  servo.write(180);
}

void loop() {
  movimento = digitalRead(PIR);

  if(movimento == HIGH) {
    Serial.println("Alimentando o pet.");
    abre();

    delay(1000);
  } else {
    Serial.println("Nenhum miau...");
    delay(1000);
  }
}
