#include <WiFiManager.h> 

void setup() {
  WiFi.mode(WIFI_STA);
  Serial.begin(9600);
  WiFiManager wm;
  bool res;
  res = wm.autoConnect("MEMEME");
  if(!res) {
    Serial.println("Failed to connect");
  } else {
    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
  }
}

void loop() {
  Serial.println("onw");
  delay(1000);

}
