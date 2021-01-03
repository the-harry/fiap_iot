#include "DHT.h"

#define LED_GREEN 12
#define LED_RED 13
#define HIGROMETRO A1
#define LDR A2
#define DHTPIN A3
#define DHTTYPE DHT11
#define BUTTON 8

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  // mede umidade do solo
  int soil_humidity = analogRead(HIGROMETRO);
  delay(10);

  // mede luminosidade
  int luminosidade = analogRead(LDR);
  delay(10);

  // mede umidade do ar
  float air_humidity = dht.readHumidity();
  if (isnan(air_humidity)) {
    Serial.println("Erro ao ler DHT.");
  }
  delay(10);

  // mede temperatura
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    Serial.println("Erro ao ler DHT.");
  }
  delay(10);

  // verifica se pode irrigar ou nao
  if ((soil_humidity > 800 && luminosidade > 500) || digitalRead(BUTTON) == HIGH) {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
    Serial.println(" Irrigando horta");
  } else if (soil_humidity > 800 && luminosidade < 500) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    Serial.println("Solo seco, porem muito sol, abortando irrigacao.");
  }

  // imprime valores das medicoes
  Serial.print("Umidade do solo: ");
  Serial.println(soil_humidity);

  Serial.print("Umidade do ar: ");
  Serial.print(air_humidity);
  Serial.println("%");

  Serial.print("Temperatura: ");
  Serial.println(temp);

  Serial.print("Luminosidade: ");
  Serial.println(luminosidade);

  Serial.println("=====================================\n\n");

  delay(2000);
}
