// Station: Potentiometer and Serial Monitor

#include <Arduino.h>

const uint8_t POTENTIOMETER_PIN = 34;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  const int value = analogRead(POTENTIOMETER_PIN);
  Serial.print("Potentiometer value: ");
  Serial.println(value);

  delay(200);
}
