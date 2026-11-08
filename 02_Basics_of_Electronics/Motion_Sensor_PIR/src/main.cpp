// Station: Bewegung mit einem PIR-Sensor erkennen

#include <Arduino.h>

const uint8_t PIR_PIN = 27;

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  const int motionState = digitalRead(PIR_PIN);
  Serial.print("PIR-Ausgang: ");
  Serial.println(motionState == HIGH ? "Bewegung erkannt" : "Keine Bewegung");

  delay(200);
}
