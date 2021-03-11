#include <ArduinoJson.h>
#include <LittleFS.h>
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

// config settings
String remote_server = "unknown.address";
String device_nickname = "unknown.sensor";

// stuff for a simple webserver
ESP8266WebServer server(80);
void handleRoot();
void handleConfigForm();
void handleUpdateConfig();
void handleNotFound();
void handleDir();

void setup() {
  Serial.begin(9600);

  // Wf_Fi Manager stuff
  WiFi.mode(WIFI_STA);
  WiFiManager wm;

  if(!wm.autoConnect("NodeMCU Setup")) {
    Serial.println("Unable to connect to Wi-Fi");
  } else {
    Serial.print("Wi-Fi connection successful. IP: ");
    Serial.println(WiFi.localIP());
  }

  // web app handlers
  server.on("/", handleRoot);
  server.on("/dir", handleDir);
  server.on("/config-form", handleConfigForm);
  server.on("/update-config", handleUpdateConfig);
  server.onNotFound(handleNotFound);
  server.begin();

  LittleFS.begin();

  // load config / create if need be
  readConfig();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String o = getFileContents("home.html");
  o.replace("%ssid%", WiFi.SSID());
  o.replace("%remote_server%", remote_server);
  o.replace("%device_nickname%", device_nickname);
  server.send(200, "text/html", o);
}

void handleConfigForm() {
  String o = getFileContents("config-form.html");
  o.replace("%remote_server%", remote_server);
  o.replace("%device_nickname%", device_nickname);
  server.send(200, "text/html", o);
}

void handleUpdateConfig() {
  remote_server = server.arg("remote_server");
  device_nickname = server.arg("device_nickname");
  writeConfig();
  server.sendHeader("Location", "/");
  server.send(303);
}

/* Only does the root level */
void handleDir() {
  String o = "";
  Serial.println("handleDir");
  Dir dir = LittleFS.openDir("/");
  while (dir.next()) {
    o += dir.fileName();
    o += "\n";
  }
  server.send(200, "text/plain", o);
}

void handleNotFound() {
  server.send(404, "text/plain", "Your file is not here! (" + server.uri() + ")");
}

void dumpFileToSerial(String fName) {
  Serial.println(getFileContents(fName));
}

String getFileContents(String fName) {
  String o = "";
  File f = LittleFS.open(fName, "r");
  while (f.available()) {
    o += f.readString();
  }
  f.close();
  return o;
}

void readConfig() {
  if (!LittleFS.exists("config.json")) {
    writeConfig();
    return;
  }
  File f = LittleFS.open("config.json", "r");
  DynamicJsonDocument doc(1024);
  DeserializationError err = deserializeJson(doc, f);
  if (err) {
    Serial.print(F("deserializeJson failed: "));
    Serial.println(err.f_str());
  } else {
    remote_server = doc["remote_server"].as<String>();
    device_nickname = doc["device_nickname"].as<String>();
  }
  f.close();
}

void writeConfig() {
  DynamicJsonDocument doc(1024);
  doc["remote_server"] = remote_server;
  doc["device_nickname"] = device_nickname;
  File f = LittleFS.open("config.json", "w");
  serializeJson(doc, f);
  f.close();
  serializeJson(doc, Serial);
}
