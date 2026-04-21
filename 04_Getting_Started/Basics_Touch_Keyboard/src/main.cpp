/**
 *
 * Basic Touch Keyboard
 *
 * What you need:
 * - Basic software environment (VSC, PlatformIO)
 * - Basic hardware requirements (ESP32, USB-Cable, Jumper Wires)
 *
 *
 * This sketch transforms the ESP32 into a bluetooth keyboard.
 * You can connect to your computer and use the touch pins to
 * send keyboard commands.
 *
 * The sketch is based on the BleKeyboard library,
 * make sure the platformio.ini contains includes this library,
 * then you can use it in your sketch.
 *
 *
 * 
 * --------------------------------------------------------
 * Read more about this Bluetooth Keyboard library 
 * and key you can trigger here:
 * https://github.com/T-vK/ESP32-BLE-Keyboard
 * 
 *
 * 
 * 
 */


/*
 *
 * Here you'll find all relevant configs for the platformio.ini
 * 
   [env:esp32dev]
   platform = espressif32@6.6.0
   board = esp32dev
   framework = arduino
   board_build.partitions = huge_app.csv
   lib_deps = t-vk/ESP32 BLE Keyboard@^0.3.2
   monitor_speed = 115200
   
   board_build.filesystem = littlefs
*/



 #include <Arduino.h>
#include <BleKeyboard.h>

#define NUM_TOUCH 4

// Touch pins on the ESP32
int touchPins[NUM_TOUCH] = {12, 14, 27, 13};

// Thresholds: lower value = more sensitive
int thresholds[NUM_TOUCH] = {40, 40, 40, 40};

// Keys that will be sent via Bluetooth
char keysToSend[NUM_TOUCH] = {'a', 'b', 'c', 'd'};

// State to avoid repeated triggering
bool touched[NUM_TOUCH] = {false};

// Create Bluetooth keyboard instance
BleKeyboard bleKeyboard("ESP32 Keyboard");

void setup() {
  Serial.begin(115200);

  // Start Bluetooth keyboard
  bleKeyboard.begin();

  Serial.println("Waiting for Bluetooth connection...");
}

void loop() {

  // Only send keys if a device is connected
  if (!bleKeyboard.isConnected()) {
    delay(100);
    return;
  }

  // Check all touch pins
  for (int i = 0; i < NUM_TOUCH; i++) {

    int value = touchRead(touchPins[i]);

    // If touched (value below threshold) and not already triggered
    if (value < thresholds[i] && !touched[i]) {

      Serial.println("Touch detected on pin " + String(touchPins[i]));

      // Send key via Bluetooth
      bleKeyboard.print(String(keysToSend[i]));

      // Mark as handled
      touched[i] = true;
    }

    // Reset state when released
    if (value >= thresholds[i]) {
      touched[i] = false;
    }
  }

  delay(50);
}
