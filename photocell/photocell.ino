/*
  Read values from a basic photocell
*/

int photocellPin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
}

void loop() {
  Serial.print("Photocell Value: ");
  Serial.println(analogRead(photocellPin));
  delay(1000);
}

