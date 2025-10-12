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

 
#include <Arduino.h>
#include <BleKeyboard.h>

/**
 * Create the Bluetooth keyboard
 *
 * Parameters:
 * 1st parameter (string, e.g. "Typerius42"):
 *    - Device Name (must be unique for each device, otherwise conflicts may occur)
 * 2nd parameter:
 *    - Device Manufacturer
 * 3rd parameter:
 *    - Battery Level (0–100)
 *
 */
BleKeyboard bleKeyboard(HERE_THE_UNIQUE_NAME_OF_YOUR_BLUETOOTH_DEVICE, "Gabriel Rausch", 100);

void setup()
{
  Serial.begin(115200);

  bleKeyboard.begin();
}

void loop()
{
  Serial.println("I'm alive...");

  if (touchRead(4) < 40)
  {
    Serial.println("Touch 4 active");
  }

  if (bleKeyboard.isConnected())
  {

    if (touchRead(4) < 40)
    {
      bleKeyboard.print("A");
    }
  }

  delay(200);
}