#include <ESP8266WiFi.h>

#define HTTP_PORT 80

const char* ssid     = "ssid";
const char* password = "senhasinistra";

const char* host = "viacep.com.br";
const char* cep   = "03047000";

WiFiClient client;

void wifi_connection(){
  Serial.print("Conectando ao SSID: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi conectado");
  Serial.println("Endereco IP: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(9600);
  delay(10);
  wifi_connection();
  delay(1000);
}

void loop() {
  Serial.print("connecting to ");
  Serial.println(host);

  if (!client.connect(host, HTTP_PORT)) {
    Serial.println("connection failed");
    return;
  }

  String uri = "/ws/";
  uri += cep;
  uri += "/json";

  Serial.print("Requesting URL: ");
  Serial.println(uri);

  client.print(String("GET ") + uri + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
  delay(5000);
}
