/**
 * 
 * Selfmadey Makey
 * Capacitive Touch Bananas trigger Processing 
 * and play some sound (the selfmade version of
 * a makey makey board)
 * 
 * What you need:
 * - Basic software environment (VSC, PlatformIO and Processing)
 * - Basic hardware requirements (ESP32, Breadboard, MicroUSB)
 * - Some Wires, some fruits (banana, apple...)
 * 
 * 
 * #Part 1: Touch sensor
 * Connect wire to touch pin (e.g. on Touch0 ~ pin 4)
 * Print touch sensor value to serial monitor.
 * Then stick wire into fruit, observe sensor data to
 * adjust your code: when banana is touched, than the
 * value 1 should be piped to the serial port, else
 * just 0.
 * 
 * 
 * #Part 2: Switch to processing
 * Sounds is going to to play via the computer (that makes it easier to handle
 * multiple sounds). So we need to switch from serial monitor
 * to processing.
 * In the subfolder of this exercise you'll find a skeleton
 * of a processing sketch. Read all further details there.
 * The goal is: touching banana should 
 * a) colorize screen in red
 * b) play a sound
 * 
 * 
 * #Part 3: More fruits
 * As soon as one fruit is playing you can continue
 * to exents your fruit keyboard
 *  
*/
#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("I'm alive...");
  
  if(touchRead(4) < 40) {  
    Serial.println("Touch 4 active");
  }
  delay(200);    
}