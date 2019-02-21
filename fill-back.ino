#include <Adafruit_NeoPixel.h>

#define PIN 6

#define NUM_LEDS 43

#define BRIGHTNESS 40

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

uint16_t curr_pos = 0;
boolean red = false;

void setup() {
  // put your setup code here, to run once:
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i,200,0,0);
  }
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!red) {
    for(uint16_t i=0; i<curr_pos; i++) {
      strip.setPixelColor(i,200,200,200);
    }
    for(uint16_t i=curr_pos; i<strip.numPixels(); i++) {
      strip.setPixelColor(i,200,0,0);
    }
    curr_pos++;
  } else if (red) {
    for(uint16_t i=0; i<curr_pos; i++) {
      strip.setPixelColor(i,200,0,0);
    }
    for(uint16_t i=curr_pos; i<strip.numPixels(); i++) {
      strip.setPixelColor(i,200,200,200);
    }
    curr_pos++;
  }
  if (curr_pos >= NUM_LEDS) {
    curr_pos = 0;
    red = !red;
  }
  strip.show();
  delay(45);
}
