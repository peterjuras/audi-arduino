#include <Adafruit_NeoPixel.h>

#define PIN 6
#define PIN2 10
const int pinX = A0;
const int pinY = A1;
const int pinZ = A2;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(29, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(30, PIN2, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  
  strip2.begin();
  strip2.show();
  
  strip.setBrightness(25);
  strip2.setBrightness(25);
}

void loop() {
  colorAllLeds(strip2, strip2.Color(255, 0, 0));
  colorAllLeds(strip, strip.Color(0, 255, 0));
}

void colorAllLeds(Adafruit_NeoPixel currentStrip, uint32_t color) {
  for (int i = 0; i < currentStrip.numPixels(); i++) {
    currentStrip.setPixelColor(i, color);
  }
  currentStrip.show();
}
