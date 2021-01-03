#define LED 9

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char caractere;
    caractere = Serial.read();
    if (caractere != '\n') {
      Serial.println(caractere);
      if (String(caractere) == "H") {
        digitalWrite(LED, HIGH);
      } else if (String(caractere) == "L") {
        digitalWrite(LED, LOW);
      }
      delay(10);
    }
  }
  delay(100);
}
