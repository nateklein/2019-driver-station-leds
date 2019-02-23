#include <Adafruit_NeoPixel.h>

#define PIN 6

#define NUM_LEDS 47

#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

uint16_t max_running = 5;
uint16_t vel[5] = {};
uint16_t pos[5] = {};
uint16_t interval;
//uint16_t pos = 0;
uint16_t counter = 0;

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
  for (uint16_t i=0; i<max_running; i++) {
    Serial.println(pos[i]);
    if (pos[i] + vel[i] > NUM_LEDS) {
      pos[i] = 0;
      vel[i] = random(2,5);
    } else if (pos[i] == 0) {
      vel[i] = random(2,5);
    }
    pos[i] += vel[i];
    strip.setPixelColor(pos[i],200,200,200);
  }
  strip.show();
  interval = random(15,100);
  delay(interval);
}
