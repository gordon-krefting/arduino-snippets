/*
  Blinks the onboard LED and writes back to the serial monitor
*/
void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  Serial.println("HIGH");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  Serial.println("LOW");
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
