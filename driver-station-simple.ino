#include <Adafruit_NeoPixel.h>

#define PIN 6

#define NUM_LEDS 43

#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

uint16_t curr_pos = 0;
boolean back = false;

void setup() {
  // put your setup code here, to run once:
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i,200,0,0);
  }
  strip.setPixelColor(curr_pos,200,200,200);
  strip.setPixelColor(curr_pos+1,200,200,200);
  if (curr_pos >= NUM_LEDS) {
    back = true;
  } else if (curr_pos == 0) {
    back = false;
  }
  
  if (back) {
    curr_pos--;
  } else {
    curr_pos++;
  }
  strip.show();
  delay(45);
}
