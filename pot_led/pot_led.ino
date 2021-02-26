/*
  Read values from a basic potentiometer on A0 and 3.3v
  Dims and brightens an led based on the pot values
*/

#define POT_PIN A0
#define LED_PIN 9

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int val = constrain(analogRead(POT_PIN), 0, 680);
  val = map(val, 0, 680, 255, 0);
  analogWrite(LED_PIN, val); 
  delay(10);
}

