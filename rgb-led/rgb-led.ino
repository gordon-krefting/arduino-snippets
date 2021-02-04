/*
   Lights up an RGB LED with a vaguely pleasing randomized series of colors.
*/

#define RED_PIN   11
#define GREEN_PIN 10
#define BLUE_PIN  9

void setup() {
  pinMode(RED_PIN,   OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN,  OUTPUT);
  randomSeed(analogRead(0));
}

int angle = 0;
int redFactor   = 1;
int greenFactor = 1;
int blueFactor  = 1;

void loop() {
  set_color(scale(angle*redFactor), scale(angle*greenFactor), scale(angle*blueFactor));
  angle ++;
  if (angle > 359) {
    angle = 0;
    redFactor   = random(1, 4);
    greenFactor = random(1, 4);
    blueFactor  = random(1, 4);
  }
  delay(20);
}

void set_color(int red, int green, int blue) {
  analogWrite(RED_PIN,   red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN,  blue);
}

float scale(int angle) {
  return (sin(angle * M_PI / 180) + 1) / 2 * 255;
}
