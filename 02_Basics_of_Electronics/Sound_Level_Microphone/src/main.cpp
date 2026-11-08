// Station: Geräuschpegel mit einem Mikrofonmodul beobachten

#include <Arduino.h>

const uint8_t MICROPHONE_PIN = 34;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  const int value = analogRead(MICROPHONE_PIN);
  Serial.print("Mikrofon-Rohwert: ");
  Serial.println(value);

  delay(50);
}
