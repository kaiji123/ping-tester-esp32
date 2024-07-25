#include <WiFi.h>
#include <ESPping>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* ping_host = "8.8.8.8"; // IP address of the host to ping (Google DNS)

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected!");
}

void loop() {
  // Perform the ping test
  bool success = Ping.ping(pping_host);

  if (success) {
    Serial.print("Ping successful. Time taken: ");
    Serial.print(Ping.averageTime());
    Serial.println(" ms");
  } else {
    Serial.println("Ping failed.");
  }

  delay(10000); // Wait 10 seconds before the next ping
}
