#include "DHT.h"

#define LDR A0
#define DHTPIN A2
#define SENSOR_UMIDADE A5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // mede umidade do solo
  int soil_humidity = analogRead(SENSOR_UMIDADE);
  delay(10);

  // mede luminosidade
  int light = analogRead(LDR);
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

  if (soil_humidity > 800 && luminosidade > 500) {
    Serial.println(" Irrigando horta");
  }
  delay(2000);
}
