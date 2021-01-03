#include <Servo.h>

#define PIR 7
#define SERVO 9
#define INTERVAL 1000

Servo servo;

int pos;
int movimento = 0;
unsigned long previousMillis = 0;

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

boolean feedTime() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;
    return true;
  }
  else {
    return false;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  servo.attach(SERVO);
  servo.write(180);
}

void loop() {
  if(movimento == HIGH && feedTime() == true) {
      Serial.println("Alimentando o pet.");
      abre();
  }
  else {
    Serial.println("Nenhum miau...");
  }

  movimento = digitalRead(PIR);
}
