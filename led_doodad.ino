/*
 * use 16mhz(pll)
 * be sure to re-burn the bootloader
 * WS2812B's get cranky otherwise
 */
#include <Adafruit_NeoPixel.h>

#define PIN        4
#define NUMPIXELS  2
#define BRIGHTNESS 200

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 10;
uint16_t hue = 0;

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.setPixelColor(0, pixels.gamma32(pixels.ColorHSV(hue, 255, BRIGHTNESS)));
  pixels.setPixelColor(1, pixels.gamma32(pixels.ColorHSV((uint16_t)hue+5000, 255, BRIGHTNESS)));
  
  pixels.show();
  delayMicroseconds(delayval);
  hue++;
}
