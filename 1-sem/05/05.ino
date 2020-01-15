#define SENSOR_UMIDADE A0
#define RED_LED 5
#define YELLOW_LED 6
#define GREEN_LED 7

int medicao;

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_UMIDADE, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  medicao = analogRead(SENSOR_UMIDADE);

  Serial.print("Umidade: ");
  Serial.print(medicao);

  if (medicao > 0 && medicao < 400) {
    Serial.println(" Status: Solo umido");
    apagaleds();
    digitalWrite(GREEN_LED, HIGH);
  } else if (medicao > 400 && medicao < 800) {
    Serial.println(" Status: Umidade moderada");
    apagaleds();
    digitalWrite(YELLOW_LED, HIGH);
  } else {
    Serial.println(" Status: Solo seco");
    apagaleds();
    digitalWrite(RED_LED, HIGH);
  }
  delay(100);
}

void apagaleds() {
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}
