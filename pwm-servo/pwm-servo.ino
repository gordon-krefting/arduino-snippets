#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 194
#define SERVOMAX 630

#define POT_PIN A0

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  pwm.begin();
  pwm.setPWMFreq(60);
}

void loop() {
  int pot_value = analogRead(POT_PIN) / 5 * 5;
  int pulse_len = map(pot_value, 0, 1023, SERVOMIN, SERVOMAX);
  Serial.print("Pot Value: ");
  Serial.print(pot_value);
  Serial.print("  Pulse: ");
  Serial.println(pulse_len);
  pwm.setPWM(0, 0, pulse_len);
}

void loop_old() {
  int pulse_length = map(0, 0, 180, SERVOMIN, SERVOMAX);
  Serial.println("0 Degrees");
  pwm.setPWM(0, 0, pulse_length);
  delay(1000);

  pulse_length = map(90, 0, 180, SERVOMIN, SERVOMAX);
  Serial.println("90 Degrees");
  pwm.setPWM(0, 0, pulse_length);
  delay(1000);

  pulse_length = map(180, 0, 180, SERVOMIN, SERVOMAX);
  Serial.println("180 Degrees");
  pwm.setPWM(0, 0, pulse_length);
  delay(1000);

  pulse_length = map(90, 0, 180, SERVOMIN, SERVOMAX);
  Serial.println("90 Degrees");
  pwm.setPWM(0, 0, pulse_length);
  delay(1000);

}
