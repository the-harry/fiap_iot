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

  // imprime os resultados das medicoes
  Serial.print("Umidade do solo: ");
  Serial.println(soil_humidity);

  Serial.print("Umidade do ar: ");
  Serial.print(air_humidity);
  Serial.println("%");

  Serial.print("Temperatura: ");
  Serial.println(temp);

  Serial.print("Luminosidade: ");
  Serial.println(light);

  Serial.println("=====================================");

  // informa o nivel de umidade do solo
  if (soil_humidity > 0 && soil_humidity < 400) {
    Serial.println(" Status: Solo umido");
  } else if (soil_humidity > 400 && soil_humidity < 800) {
    Serial.println(" Status: Umidade moderada");
  } else {
    Serial.println(" Status: Solo seco");
  }

  Serial.println("=====================================");

  delay(2000);
}
