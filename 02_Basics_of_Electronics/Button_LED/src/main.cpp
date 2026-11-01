// Station: Button and LED

#include <Arduino.h>

const uint8_t LED_PIN = 13;
const uint8_t BUTTON_PIN = 18;

bool lastButtonPressed = false;

void setup() {
  Serial.begin(115200);

  // The internal pull-up keeps the input HIGH until the button connects it to GND.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // With INPUT_PULLUP, a pressed button reads LOW.
  const bool buttonPressed = digitalRead(BUTTON_PIN) == LOW;
  digitalWrite(LED_PIN, buttonPressed ? HIGH : LOW);

  // Report only state changes instead of flooding the serial monitor.
  if (buttonPressed != lastButtonPressed) {
    Serial.println(buttonPressed ? "Button pressed" : "Button released");
    lastButtonPressed = buttonPressed;
  }
}
