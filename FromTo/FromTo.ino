const int v1 = 2;
const int v2 = 3;
const int v3 = 4;
const int v4 = 5;
const int v5 = 6;
const int v6 = 7;
const int v7 = 8;
const int v8 = 9;
const int motors[8] = {v1,v2,v3,v4,v5,v6,v7,v8};

const int MOTOR_COUNT = 8;
const float VIBRATIONS_FOR_COORDINATES[3][3][8] = {
  {
    { 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 0.5, 1, 1, 0.5, 0, 0, 0 },
    { 0, 0, 0, 0.5, 1, 1, 0, 0 }
  },
  {
    { 1, 1, 1, 1, 1, 0, 0, 0 },
    { 0, 0.5, 1, 1, 0.5, 0, 0.5, 1 },
    { 0, 0, 0, 0.5, 1, 1, 0, 0 }
  },
  {
    { 1, 1, 1, 0, 0, 0, 0, 1 },
    { 0, 0.5, 1, 0, 0, 0, 0.5, 1 },
    { 0, 0, 0, 0.5, 0, 0, 1, 1 }
  }
};

void setup() {
  pinMode(v1, OUTPUT);
  pinMode(v2, OUTPUT);
  pinMode(v3, OUTPUT);
  pinMode(v4, OUTPUT);
  pinMode(v5, OUTPUT);
  pinMode(v6, OUTPUT);
  pinMode(v7, OUTPUT);
  pinMode(v8, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  video();
}

void video() {
  unsigned long startTime = millis();
  delay(1800);
  circle(150,570.0); // bis 2,37 weißer Schleier
  delay(900);
  circle(200,300.0); // bis 3,57 Schatten fährt durch
  test(2,2,0,0,730,255,false); // bis 04,30 von hinten rechts nach vorne links
  // 4:30
  test(0,0,2,0,400,255,false); // bis 4,70 Nah links nach nah rechts
  test(0,2,2,2,670,175,false); //bis 5,37 hinten links nach hinten rechts
  test(2,0,1,1,800,255,true); //bis 6,17 vorne rechts nach gradeaus mittig weg (leichter Schwenker rechts)
  // Wolfsauge
  delay(730);
  circle(255,100.0); // bis 7 Mitte “Wolfsauge”
  delay(1270);
  circle(200,200.0); //bis 8,47 Mitte Wolfsauge
  
  test(2,2,1,0,800,255,true); //bis 9,27 hinten rechts nach vorne (nicht ganz vorne) links
  delay(100); // bis 9,37 Mitte Wolfsauge
  test(2,2,1,0,960,255,false); // bis 10,33 mitte leicht rechts hinten nach Mitte vorne
  test(2,0,0,0,600,255,false); // bis 10,93 sehr nah rechts nach links
  test(2,0,0,0,1170,255,true); // bis 12,10 Front von rechts nach links nah
  delay(970); //Wolf
  test(0,1,1,2,650,255,true); // -50 13,07- 13,77 links hinten nach Mitte weg
  delay(1010); // +50 bis 14,93 Wolken (war 1210)
  test(2,1,1,0,700,255,false); // + 3ms bis 15,60 Auto rechts/mitte, zoom rein
  test(0,0,0,0,400,255,false); // bis 16 Auto links/mitte
  test(1,0,1,1,700,255,false); // bis 16,70 Mitte nah, Mastershot, Schenk nach oben etwas weg
  test(0,0,0,2,500,255,false); //bis 17,20 Mitte links, nah, fährt nach links raus
  test(1,0,1,2,1170,255,false); //bis 18,37 Mitte von hinten, beschleunigt raus gerade !!!!!! Schöne Szene, rumspielen!!!
  test(0,0,2,0,1160,255,false); //bis 19,53 vorne linksmitte schenkt nach rechts
  test(1,2,1,1,970,200,true); // bis 20,50entfernt mitte geht in Kurve
  delay(220);//Laster geht auf
  vibrate(v4,255,0);
  vibrate(v5,255,0);
  vibrate(v7,255,0);
  vibrate(v8,255,150);
  vibrate(v4,0,0);
  vibrate(v5,0,0);
  vibrate(v7,0,0);
  vibrate(v8,0,0);
  delay(830); // bis 21,70
  test(1,0,2,1,570,255,false); //Ausweichmanöver mittig 
  test(2,1,0,0,1200,255,true); //bis 23,47 !!!!!! Schöne Szene, rumspielen!!!
  //Jetzt 23,27
  delay(330);//bis 24.07 fahrt auf Laster (nah)
  vibrate(v4,255,0);
  vibrate(v5,255,0);
  vibrate(v7,255,0);
  vibrate(v8,255,150);
  vibrate(v4,0,0);
  vibrate(v5,0,0);
  vibrate(v7,0,0);
  vibrate(v8,0,0);
  delay(780); //24,53
  delay(2650);//27,18
  vibrate(v4,255,0);
  vibrate(v5,255,0);
  vibrate(v7,255,0);
  vibrate(v8,255,100);
  vibrate(v4,0,0);
  vibrate(v5,0,0);
  vibrate(v7,0,0);
  vibrate(v8,0,0); //bis 27,28
  delay(1370); //bis 29,50
  vibrate(v4,255,0);
  vibrate(v5,255,0);
  vibrate(v7,255,0);
  vibrate(v8,255,150);
  vibrate(v4,0,0);
  vibrate(v5,0,0);
  vibrate(v7,0,0);
  vibrate(v8,0,0); // bis
  delay(400);
  test(1,1,0,1,1190,200,false);//30,77
  test(1,2,1,0,2800,255,true); //32,10 entfernt von vorne (überholt Laster) & Shot von hinten, fährt weg
  delay(460); //Cockpit
  test(1,1,0,0,1040,255,false); // Drift halbnah & Whoosh
  test(0,2,1,0,760,255,true); //Weit entfernt fährt auf einen zu (bis mitte)
  delay(640); //Cockpit & Natur
  test(1,1,2,0,700,255,false);
  test(1,0,0,0,2000,255,true); // !!!!!! Schöne Szene, rumspielen!!!
  delay(1500);
  vibrate(v4,255,0);
  vibrate(v5,255,0);
  vibrate(v7,255,0);
  vibrate(v8,255,100);
  vibrate(v4,0,0);
  vibrate(v5,0,0);
  vibrate(v7,0,0);
  vibrate(v8,0,0);
  delay(100);
  vibrate(v4,255,0);
  vibrate(v5,255,0);
  vibrate(v7,255,0);
  vibrate(v8,255,100);
  vibrate(v4,0,0);
  vibrate(v5,0,0);
  vibrate(v7,0,0);
  vibrate(v8,0,0);
  delay(300);
  vibrate(v4,255,0);
  vibrate(v5,255,0);
  vibrate(v7,255,0);
  vibrate(v8,255,100);
  vibrate(v4,0,0);
  vibrate(v5,0,0);
  vibrate(v7,0,0);
  vibrate(v8,0,0);
  delay(100);
  vibrate(v4,255,0);
  vibrate(v5,255,0);
  vibrate(v7,255,0);
  vibrate(v8,255,100);
  vibrate(v4,0,0);
  vibrate(v5,0,0);
  vibrate(v7,0,0);
  vibrate(v8,0,0);
  
}

void delayIfNecessary(long time) {
  if (time > 0) {
    delay(time);
  }
}

void circle (int strength, float duration) {
  unsigned long currentTime = millis();
  float step = duration / 5;
  
  vibrate(v4, strength, 0);
  vibrate(v4, 0, 0);
  delayIfNecessary(step - (millis() - currentTime));
  
  vibrate(v5, strength, 0);
  vibrate(v5, 0, 0);
  delayIfNecessary(step * 2 - (millis() - currentTime));
  
  vibrate(v6, strength, 0);
  vibrate(v6, 0, 0);
  delayIfNecessary(step * 3 - (millis() - currentTime));
  
  vibrate(v7, strength, 0);
  vibrate(v7, 0, 0);
  delayIfNecessary(step * 4 - (millis() - currentTime));
  
  vibrate(v8, strength, 0);
  vibrate(v8, 0, 0);
  delayIfNecessary(duration - (millis() - currentTime));
}

// TODO give strength meaning
void driveFromTo (int fromX, int fromY, int toX, int toY, int strength, int duration) {
  float from[8], to[8];
  getVibrationsForCoordinates(fromX, fromY, from);
  getVibrationsForCoordinates(toX, toY, to);
  Serial.println("l");
  
  vibrateArray(from, 255);
  for(int i = 0; i < 8; i++) {
    if(from[i] < to[i]) {
      for (float j = 255.0 * from[i]; i <= 255.0 * to[i]; i++) {
        vibrate(motors[i], 100 + (1.55 * j), duration);
      }
    } else if(from[i] > to[i]) {
      for (float j = 255.0 * from[i]; i >= 255.0 * to[i]; i--) {
        vibrate(motors[i], 100 + (1.55 * j), duration);
      }
    } else {
      // if from and to are equal, it does not matter which value is used for strength
      vibrate(motors[i], from[i], duration);
      Serial.println(from[i]);
    }
  }
}

void test(int fromX, int fromY, int toX, int toY, float duration, int intensity, boolean stopMotors) {
  float from[8], to[8];
  getVibrationsForCoordinates(fromX, fromY, from);
  getVibrationsForCoordinates(toX, toY, to);
  const int STEP = 10;
  float progress;
  unsigned long currentTime;
  for (float i = 0; i < duration; i = i + STEP) {
    currentTime = millis();
    progress = i / duration;
    vibrateArray(from, (1.0 - progress) * intensity);
    vibrateArray(to, progress * intensity);
    delay(STEP - (millis() - currentTime));
  }
  if(stopMotors) {
    analogWrite(v1, 0);
    analogWrite(v2, 0);
    analogWrite(v3, 0);
    analogWrite(v4, 0);
    analogWrite(v5, 0);
    analogWrite(v6, 0);
    analogWrite(v7, 0);
    analogWrite(v8, 0);
  }
}

void getVibrationsForCoordinates(int x, int y, float v[]) {
  for (int i = 0; i < MOTOR_COUNT; i = i + 1) {
    v[i] = VIBRATIONS_FOR_COORDINATES[x][y][i];
  }
}


void vibrate(int engine, int strength, int duration) {
  analogWrite(engine, strength);
  delay(duration);
}

void vibrateArray(float strength[], int intensity) {
  analogWrite(v1, strength[0]*intensity);
  analogWrite(v2, strength[1]*intensity);
  analogWrite(v3, strength[2]*intensity);
  analogWrite(v4, strength[3]*intensity);
  analogWrite(v5, strength[4]*intensity);
  analogWrite(v6, strength[5]*intensity);
  analogWrite(v7, strength[6]*intensity);
  analogWrite(v8, strength[7]*intensity);
}
