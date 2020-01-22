#include "DHT.h"

#define SENSOR_UMIDADE A0
#define LDR A1
#define DHTPIN A2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int soil_humidity;

float temperature() {
  float temp = dht.readTemperature();
  if (!isnan(temp)) {
    return temp;
  } else {
    Serial.println("Erro ao ler DHT.");
    return 0;
  }
}

float airHumidity() {
  float humidity = dht.readHumidity();
  if (!isnan(humidity)) {
    return humidity;
  } else {
    Serial.println("Erro ao ler DHT.");
    return 0;
  }
}

float soilHumidity() {
  float humidity = analogRead(SENSOR_UMIDADE);
  if (!isnan(humidity)) {
    return humidity;
  } else {
    Serial.println("Erro ao ler higrometro.");
    return 0;
  }
}

int readLdr() {
  return analogRead(LDR);
}

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  int soil_humidity = soilHumidity();
  delay(10);
  float air_humidity = airHumidity();
  delay(10);
  float temp = temperature();
  delay(10);
  int light = readLdr();

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
