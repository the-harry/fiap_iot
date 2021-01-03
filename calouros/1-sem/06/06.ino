#include <Servo.h>

#define PIR 7
#define SERVO 9
#define INTERVAL 1000

Servo servo;

int pos;
int movimento = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  servo.attach(SERVO);
  servo.write(180);
}

void loop() {
  if (digitalRead(PIR) == HIGH) {
    Serial.println("Alimentando o pet.");

    for (pos = 180; pos >= 0; pos--) {
      servo.write(pos);
      delay(15);
    }

    delay(300);

    for (pos = 0; pos < 180; pos++) {
      servo.write(pos);
      delay(15);
    }
  }
  else {
    Serial.println("Nenhum miau...");
  }
  delay(1000);
}
