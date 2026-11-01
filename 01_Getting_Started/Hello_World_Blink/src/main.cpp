// Station: Hello World – Blink

#include <Arduino.h>


void setup() {
  // Start the serial connection for status and sensor output.
  Serial.begin(115200);

  // Configure GPIO 13 to control the LED.
  pinMode(13, OUTPUT);
}

void loop() {
  // Turn the LED on and report its state.
  digitalWrite(13, HIGH);
  Serial.println("On");
  delay(200);

  // Turn the LED off and report its state.
  digitalWrite(13, LOW);
  Serial.println("Off");
  delay(200);

  // Read GPIO 4's touch value; on many classic ESP32 boards it drops when touched.
  if (touchRead(4) < 40) {
    // The threshold is a starting point and may need calibration for the board.
    Serial.println("Touch Sensor active");
  }
}