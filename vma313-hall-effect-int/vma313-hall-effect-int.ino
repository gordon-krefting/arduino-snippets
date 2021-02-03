#define DEBUG 0

#if DEBUG
#define DEBUG_PRINTLN(s)  {Serial.println(s);}
#else
#define DEBUG_PRINTLN(s)
#endif

#define LEDPIN  2
#define HALLPIN 3

volatile byte state=LOW;

void setup() {
  pinMode(HALLPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(HALLPIN), event, CHANGE);

  Serial.begin(9600);
  DEBUG_PRINTLN("Start...");
}

void loop() {
  digitalWrite(LEDPIN, state);
}

void event() {
  state = !state;
  DEBUG_PRINTLN("change");
}
