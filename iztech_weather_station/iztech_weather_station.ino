#define TEMP_READ A0
#import <math.h>
#include "ESP8266WiFi.h"
#include <ESP8266HTTPClient.h>

extern const char* ssid;
extern const char* password;
const int httpPort = 80;
HTTPClient client;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("*");
  }
  Serial.println("");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  client.begin("http://192.168.1.112:80/light");
  client.addHeader("Content-Type", "text");
  client.addHeader("UserAgent", "IztechMeto-Kholat");
  client.POST(String(analogRead(TEMP_READ)));
  client.end();
  delay(100);
}
