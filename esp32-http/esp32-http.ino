#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

// contoh server (bisa lokal Flask / Node.js)
const char* serverName = "http://192.168.1.10:5000/data";

#define LDR_PIN 34

unsigned long lastTime = 0;
unsigned long timerDelay = 3000;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {

    if (WiFi.status() == WL_CONNECTED) {

      HTTPClient http;

      int ldrValue = analogRead(LDR_PIN);

      http.begin(serverName);
      http.addHeader("Content-Type", "application/json");

      String jsonData = "{\"ldr\":";
      jsonData += ldrValue;
      jsonData += "}";

      int httpResponseCode = http.POST(jsonData);

      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);

      http.end();
    } else {
      Serial.println("WiFi Disconnected");
    }

    lastTime = millis();
  }
}