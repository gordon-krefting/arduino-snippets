/*
   Sketch for reading temperature and humidity from a DHT22 sensor

   I used an AM2302 component with the pull-up resistors built in

   Notes on this sensor:
   - The read operation takes ~250 msec
   - The readings can be up to 2 sec old

   Based on a sketch by ladyada, public domain

   REQUIRES the following Arduino libraries:
   - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
   - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
*/
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22   // (other values: DHT11, DHT21)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT test!");
  dht.begin();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float f = dht.readTemperature(true); // true -> isFahrenheit
  
  if (isnan(h) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor");
    return;
  }

  Serial.print("Humidity:");
  Serial.print(h);
  Serial.print("% Temperature:");
  Serial.print(f);
  Serial.println("°F");
}
