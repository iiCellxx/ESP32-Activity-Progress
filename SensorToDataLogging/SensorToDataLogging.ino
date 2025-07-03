#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

#define DHTPIN 4       // your DHT data pin
#define DHTTYPE DHT11   // or DHT22

const char* ssid = "AlmarioFamily2.4Ghz";
const char* password = "Almariofamily@07";

const char* serverName = "http://192.168.1.6/esp32_project/insert.php";

DHT dht(DHTPIN, DHTTYPE);

unsigned long lastSend = 0;
const long interval = 30000; // 30 seconds

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
}

void loop() {
  if ((millis() - lastSend) >= interval) {
    lastSend = millis();
    sendData();
  }
}

void sendData() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = serverName;
    url += "?temp=" + String(temp);
    url += "&hum=" + String(hum);

    http.begin(url);
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.printf("Server response: %s\n", http.getString().c_str());
    } else {
      Serial.printf("Failed: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  } else {
    Serial.println("WiFi not connected.");
  }
}
