#include <Adafruit_NeoPixel.h>

#define PIN 3
#define PIN2 5

const int pinX = A0;
const int pinY = A1;
const int pinZ = A2;
const int pinButton = 2;

Adafruit_NeoPixel stickStrip = Adafruit_NeoPixel(29, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel dockStrip = Adafruit_NeoPixel(30, PIN2, NEO_GRB + NEO_KHZ800);

void setup() {
  // State button
  pinMode(pinButton, INPUT);
  
  stickStrip.begin();
  stickStrip.show(); // Initialize all pixels to 'off'

  dockStrip.begin();
  dockStrip.show(); // Initialize all pixels to 'off'
  
  stickStrip.setBrightness(15);
  dockStrip.setBrightness(255);
  
  Serial.begin(9600);
}


int buttonState = 0;
int lastButtonState = 0;
int pushes = 0;

void loop() {
  Serial.println(digitalRead(pinButton));
  buttonState = digitalRead(pinButton);
  if (buttonState != lastButtonState && buttonState == HIGH) {
      pushes++;
      delay(50);
  }
  lastButtonState = buttonState;
  
  if (pushes % 2 == 0) {
    ambientLight();
  } else {
    decisionMaking();
  }
}

void ambientLight() {
  // 239 235 208
//  colorAllLeds(dockStrip, dockStrip.Color(255, 200, 50));
//  colorAllLeds(stickStrip, stickStrip.Color(255, 200, 50));
  colorAllLeds(dockStrip, dockStrip.Color(255, 0, 255));
  colorAllLeds(stickStrip, stickStrip.Color(255, 0, 255));
}

void decisionMaking() {
  int sensorInput = analogRead(pinZ);
  uint32_t color1 = redOrGreen(stickStrip, sensorInput);
  uint32_t color2 = redOrGreen(dockStrip, sensorInput);
  colorAllLeds(stickStrip, color1);
  colorAllLeds(dockStrip, color2);
}

uint32_t redOrGreen(Adafruit_NeoPixel & strip, int input) {
  float relativeToNormal = 380 - input;
  if (relativeToNormal < 0) {
    relativeToNormal = 0;
  }

  float scale = (relativeToNormal / 100) * 255;
  if (scale > 255) {
    scale = 255;
  }
  return strip.Color(255 - scale, scale, 0);
}

void colorAllLeds(Adafruit_NeoPixel & strip, uint32_t color) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}
