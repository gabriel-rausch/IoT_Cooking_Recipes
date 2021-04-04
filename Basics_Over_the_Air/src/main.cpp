/**
 * 
 * Over the Air
 * Send Data to an End-Point within your Network
 * 
 * What you need:
 * - Basic software environment (VSC, PlatformIO and Postman for API Testing)
 * - Basic hardware requirements (ESP32, Breadboard, MicroUSB)
 * - Some Wires
 * 
 * 
 * #Part 1: Prepare sensor setup
 * For the sake of simplicity we are going to use a touch sensor input again
 * and read that data. For testing purposes you can output the data again
 * with the serial monitor.
 * 
 * #Part 2: Connect to wifi
 * For the communication to a service we need to connect the ESP to the 
 * network via wifi. I prepared some useful functions in wifi_connection.
 * You need to add your wifi credentials. A smart approach would be if
 * you store these sensitive information in another file (wifi_credentials.h),
 * define your credentials as constants. This filename is excluded in .gitignore,
 * in case if you push this exercise on some git cloud platform.
 * 
 * #Part 3: Prepare end-point
 * The measured data should be piped via the network somewhere and should be
 * displayed. Of course you can code your serverside end-point from skratch,
 * but I would prefer the lazy method for this test. Easy to use is ThingSpeak,
 * you just need to sign-up with your HFU mail (our university has a cooperation).
 * After sign-in you can create a channel with some fields.
 * 
 * #Part 4: Test end-point
 * Postman is a great and powerful API testing tool. So, copy the GET URL of your
 * ThingSpeak Channel and call this URL from Postman (you can manipulate the field data
 * directly in the url get parameters). After firing the call the value should be
 * visible in your dashboard.
 * 
 * #Part 5: ESP calls
 * Finally your can hand the API call over to the ESP code. Make sure your ESP is
 * not calling the URL every xx miliseconds, use some delay (e.g. 1 second).
 * 
 * 
*/

#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}