const int engine1 = 6;
const int engine2 = 9;
const int engine3 = 11;

void setup() {
  pinMode(engine1, OUTPUT);
  pinMode(engine2, OUTPUT);
  pinMode(engine3, OUTPUT);
}

void vibrate(int engine,int strength, int ms) {
  analogWrite(engine, strength);
  delay(ms);
}

void vibrateSingle(int engine, int strength, int ms) {
  analogWrite(engine1, 0);
  analogWrite(engine2, 0);
  analogWrite(engine3, 0);

  vibrate(engine, strength, ms);
}

void wave(int frequency, int intensity, boolean reverse) {
  if (reverse) {
    vibrateSingle(engine3, intensity, frequency);
    vibrateSingle(engine2, intensity, frequency);
    vibrateSingle(engine1, intensity, frequency);
  } else {
    vibrateSingle(engine1, intensity, frequency);
    vibrateSingle(engine2, intensity, frequency);
    vibrateSingle(engine3, intensity, frequency);
  }
}

void bendEngines(int engine1, int engine2, int engine3, int intensity, int duration) {
  vibrate(engine1, intensity * 0.85f, duration * 0.125f);
  vibrate(engine2, intensity * 0.85f, duration * 0.125f);
  vibrate(engine1, 0, 0);
  delay(0.10f * duration);
  vibrate(engine3, intensity, 0);
  delay(0.05f * duration);
  vibrate(engine2, 0, 0);
  delay(0.5f * duration);
  vibrate(engine3, 0, 0);
}

void bend(int intensity, int duration, boolean reverse) {
  if (reverse) {
    bendEngines(engine3, engine2, engine1, intensity, duration);
  } else {
    bendEngines(engine1, engine2, engine3, intensity, duration);
  }
}

void peaks(int interval) {
  int i;
  for (i = 0; i <= 100; i++) {
    vibrate(engine1, 100 + (1.55 * i), interval * 2);
  }
  for (i = 0; i < 100; i++) {
    vibrate(engine2, 100 + (1.55 * i), interval);
    vibrate(engine1, 255 - (2.55 * i), interval);
  }
  for (i = 0; i < 100; i++) {
    vibrate(engine3, 100 + (1.55 * i), interval);
    vibrate(engine2, 255 - (2.55 * i), interval);
  }
  delay(2000);
  vibrate(engine1, 0, 0);
  vibrate(engine2, 0, 0);
  vibrate(engine3, 0, 0);
  delay(1000);
}



void loop() {
//  wave(500, 125, false);
//  wave(500, 125, true);
//  bend(200, 3000, false);
//  bend(200, 3000, true);
  peaks(25);
//  delay(2000);
}
