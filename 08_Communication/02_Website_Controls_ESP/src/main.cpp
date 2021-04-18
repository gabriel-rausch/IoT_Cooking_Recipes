#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include "website-index.h"

// SSID & Password
const char *ssid = "ESP32 Access Point"; // Enter your SSID here
const char *password = NULL;            //Can also be a string with a password

// Use this IP adress after connecting to the AP
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80); // Object of WebServer(HTTP port, 80 is defult)

#define LEDPIN 13

// Handle root url (/)
void handleRoot()
{
  String htmlstring = websiteIndex;
  server.send(200, "text/html", htmlstring);
}

void handleLEDOn()
{
  Serial.println("LED ON");
  digitalWrite(LEDPIN, HIGH);
}

void handleLEDOff()
{
  Serial.println("LED OFF");
  digitalWrite(LEDPIN, LOW);
}

void setup()
{
  Serial.begin(115200);

  WiFi.softAP(ssid, password);

  // might be you need to set a short delay until
  // the access point is ready for the softAP configuration
  delay(500);

  WiFi.softAPConfig(local_ip, gateway, subnet);

  // set what happens for specific get requests
  server.on("/", handleRoot);
  server.on("/led/on", handleLEDOn);
  server.on("/led/off", handleLEDOff);

  server.begin();
  Serial.println("HTTP server started");

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  delay(100);

  // init the led pin
  pinMode(LEDPIN, OUTPUT);
}

void loop()
{
  server.handleClient();
}
