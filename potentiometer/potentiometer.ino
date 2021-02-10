/*
  Read values from a basic potentiometer on A0 and 3.3v
*/

#define POT_PIN A0

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
}

void loop() {
  int val = constrain(analogRead(POT_PIN), 0, 680);
  val = map(val, 0, 680, 255, 0);
  Serial.print("Pot Value: ");
  Serial.println(val);
  delay(1000);
}

