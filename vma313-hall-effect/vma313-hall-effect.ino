#define DEBUG 0

#if DEBUG
#define DEBUG_PRINTLN(s)  {Serial.println(F(s));}
#else
#define DEBUG_PRINTLN(s)
#endif

#define LEDPIN  2
#define HALLPIN 3

void setup() {
  pinMode(HALLPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);
  DEBUG_PRINTLN("Start...");
}

void loop() {
  delay(200);

  if (LOW == digitalRead(HALLPIN)) {
    digitalWrite(LEDPIN, HIGH);
    DEBUG_PRINTLN("Magnet YES");
  } else {
    digitalWrite(LEDPIN, LOW);
    DEBUG_PRINTLN("Magnet NO");
  }
}
