// Station: Helligkeit mit einem LDR messen

#include <Arduino.h>

const uint8_t LDR_PIN = 34;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  const int value = analogRead(LDR_PIN);
  Serial.print("LDR-Rohwert: ");
  Serial.println(value);

  delay(200);
}
