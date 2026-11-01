// Station: Adressierbarer RGB-LED-Streifen

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

const uint8_t DATA_PIN = 18;
const uint16_t LED_COUNT = 1;
const uint8_t MAX_BRIGHTNESS = 24;

Adafruit_NeoPixel strip(LED_COUNT, DATA_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.setBrightness(MAX_BRIGHTNESS);
  strip.clear();
  strip.show();
}

void loop() {
  // Grundfarben überblenden; die Helligkeit bleibt für USB-Betrieb begrenzt.
  static uint8_t step = 0;
  static uint8_t phase = 0;

  uint8_t red;
  uint8_t green;
  uint8_t blue;

  if (phase == 0) {
    red = 255 - step;
    green = step;
    blue = 0;
  } else if (phase == 1) {
    red = 0;
    green = 255 - step;
    blue = step;
  } else {
    red = step;
    green = 0;
    blue = 255 - step;
  }

  strip.setPixelColor(0, strip.Color(red, green, blue));
  strip.show();
  Serial.printf("RGB: %u, %u, %u\n", red, green, blue);

  if (step == 255) {
    step = 0;
    phase = (phase + 1) % 3;
  } else {
    step++;
  }

  delay(30);
}
