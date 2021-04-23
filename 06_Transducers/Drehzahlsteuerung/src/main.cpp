#include <Arduino.h>
int ledPin = 21; //Anschluss LED Pin
const int channel = 0; //Channel 0-15, nur wichtig bei mehreren LEDs
const int frequency = 1000; //Frequenz der Wellenform am Ausgang
const int resolution = 8; //gibt an in welchen Abstufungen man Änderungen vornehmen kann. 8 Bit = Werte von 0-255




void setup() {
ledcSetup(channel, frequency, resolution);
ledcAttachPin(ledPin, channel); //weist dem Pin den jeweiligen Channel zu
pinMode (4, INPUT); //Pin für Input, in diesem Fall ein Touch Sensor

}

void loop() {
    
 if(touchRead(4) >= 20){
    ledcWrite(channel, 255); //weißt dem Channel den Ausgabewert zu
 }else{ledcWrite(channel, 30);
 }





}

