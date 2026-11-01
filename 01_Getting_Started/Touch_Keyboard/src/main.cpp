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


BleKeyboard bleKeyboard("MrX", "Gabriel Rausch", 100);

void setup() {
  Serial.begin(115200);
  pinMode(4, INPUT_PULLUP);
  bleKeyboard.begin();
  Serial.println("Waiting for Bluetooth connection...");
}

void loop() {

   // Via touch
   // e.g.
   // touchRead(4)
   // if (touchRead(4) < 30) { ... }

  
  if (bleKeyboard.isConnected()) {
    if (digitalRead(4) == 0) {
      Serial.println("Sensor activated on pin!");
      bleKeyboard.press(KEY_LEFT_GUI);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('d');
      delay(100);
      bleKeyboard.releaseAll();
    }
  }
  delay(100);
}
