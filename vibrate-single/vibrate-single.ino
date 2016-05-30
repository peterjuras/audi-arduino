const int engine1 = 6;
const int engine2 = 10;
const int engine3 = 11;

void setup() {
  pinMode(engine1, OUTPUT);
  pinMode(engine2, OUTPUT);
  pinMode(engine3, OUTPUT);
}

void vibrate(int engine, int strength, int ms) {
  analogWrite(engine, strength);
  delay(ms);
}

void vibrateSingle(int engine, int strength, int ms) {
  analogWrite(engine1, 0);
  analogWrite(engine2, 0);
  analogWrite(engine3, 0);

  vibrate(engine, strength, ms);
}

void loop() {
  const int frequency = 100;
  
  vibrateSingle(engine1, 255, frequency);
  vibrateSingle(engine2, 255, frequency);
  vibrateSingle(engine3, 255, frequency);
}
