#include <Arduino.h>

#define DAC1 25
int value = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  while (Serial.available()==0) {}

  value = Serial.parseInt();

  dacWrite(DAC1, value);
  Serial.println(value);
}