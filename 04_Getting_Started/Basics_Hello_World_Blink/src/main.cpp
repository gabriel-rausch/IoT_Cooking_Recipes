/**
 * 
 * Hello World Blink
 * 
 * What you need:
 * - Basic software environment (VSC, PlatformIO)
 * - Basic hardware requirements (ESP32, Breadboard, MicroUSB)
 * - LED, Wire
 * 
 * 
 * #Part 1: Use Variables and Serial Monitor
 * Print out some static variables via serial monitor
 * 
 * 
 * #Part 2: Blink LED continuously
 * Connect led to board (e.g. via pin 13). 
 * Note: make sure to connect led's cathode to ground!
 * Make led shine.
 * Then, write some lines of code to blink the led continuously.
 * 
 * 
 * #Part 3: Touch sensor
 * Connect wire to touch pin (e.g. on Touch0 ~ pin 4)
 * Print touch sensor value to serial monitor
 * 
 * 
 * #Part 4: Touch to Blink
 * Write some lines of code to switch led on
 * only if wire is touched
 * 
 *  
*/

#include <Arduino.h>


void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // turn the LED on (HIGH is the voltage level) and wait 200 ms
  digitalWrite(13, HIGH);
  Serial.println("On");
  delay(200);

  // turn the LED off by making the voltage LOW and wait 200 ms
  digitalWrite(13, LOW);    
  Serial.println("Off");
  delay(200);    

  // if touch sensor on pin 4 is lower than a specific sensitive value
  if(touchRead(4) < 40) {  
    // do something, when touch is active
    Serial.println("Touch Sensor active");
  }
}