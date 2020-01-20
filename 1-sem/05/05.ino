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

  //Solo umido
  if (medicao > 0 && medicao < 400) {
    // apaga os outros leds para acender o certo
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);

    digitalWrite(GREEN_LED, HIGH);
  //Umidade moderada
  } else if (medicao > 400 && medicao < 800) {
    // apaga os outros leds para acender o certo
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);

    digitalWrite(YELLOW_LED, HIGH);
  //Solo seco
  } else {
    // apaga os outros leds para acender o certo
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);

    digitalWrite(RED_LED, HIGH);
  }
  delay(100);
}
