#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
const int led = 23;

const char turnON = 'a';
const char turnOFF = 'b';
char receivedChar;

void setup()
{
  Serial.begin(9600);
  SerialBT.begin("ESP32BluetoothClassic"); // Start Bluetooth
  Serial.println("ESP32 is ready. Connect via Bluetooth");
  Serial.println("To turn ON send: a");
  Serial.println("To turn OFF send: b");
  pinMode(led, OUTPUT);
}

void loop()
{
  receivedChar = (char)SerialBT.read(); // Read Data from Bluetooth Serial Monitor


  // SerialBT always refers to Bluetooth Serial Monitor
  if (receivedChar == turnON)
  {
    SerialBT.println("LED ON");
    Serial.println("LED ON");
    digitalWrite(led, HIGH);
  }

  if (receivedChar == turnOFF)
  {
    SerialBT.println("LED OFF");
    Serial.println("LED OFF");
    digitalWrite(led, LOW);
  }
  delay(20);
}