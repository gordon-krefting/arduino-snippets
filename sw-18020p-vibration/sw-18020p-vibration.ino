/*
  Uses an sw-18020p vibration sensor

  not sure this is working! One of the sensor's legs is very skinny and doesn't
  fit well in the breadboard
*/

#define LED_PIN    LED_BUILTIN
#define SENSOR_PIN 5

void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
  pinMode(LED_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  if (digitalRead(SENSOR_PIN) == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    delay(5);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}

