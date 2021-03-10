#include <WiFiManager.h> 

/*
 * Note: ModeMCU stores wi-fi connection deets in a memory location that isn't 
 * overwritten by uploading new code.
 * 
 * Uses WiFi manager to connect to an access point. When the app starts, the
 * manager will look for previous connection info. If there isn't any, it will
 * spin up an access point ("NodeMCU Setup") and a web server at 192.168.4.1.
 * A user (me!) can connect to the access point and choose a real access point
 * and enter a password.
 */

// stuff for a simple webserver
ESP8266WebServer server(80);
void handleRoot();
void handleNotFound();

void setup() {
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  WiFiManager wm;



  if(!wm.autoConnect("NodeMCU Setup")) {
    Serial.println("Unable to connect to Wi-Fi");
  } else {
    Serial.print("Wi-Fi connection successful. IP: ");
    Serial.println(WiFi.localIP());
  }

  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  Serial.println("Yo!");
  server.send(200, "text/plain", "Yo!");
}

void handleNotFound() {
  Serial.println("No!");
  Serial.println(server.uri());
  server.send(404, "text/plain", "No!");
}