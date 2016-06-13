#include <Adafruit_NeoPixel.h>

#define PIN 3
const int pinX = A0;
const int pinY = A1;
const int pinZ = A2;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
}

void loop() {
  strip.setBrightness(50);
  colorAllLeds(redOrGreen(analogRead(pinZ)));
}

uint32_t redOrGreen(int input) {
  float relativeToNormal = 350 - input;
  if (relativeToNormal < 0) {
    relativeToNormal = 0;
  }

  float scale = (relativeToNormal / 70) * 255;
  return strip.Color(255 - scale, scale, 0);
}

void colorAllLeds(uint32_t color) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
  }
}
