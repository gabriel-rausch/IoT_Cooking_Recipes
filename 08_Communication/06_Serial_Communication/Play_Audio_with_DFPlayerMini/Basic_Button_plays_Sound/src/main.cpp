/**
 * 
 * Here are some fundamentals code fragments to play sounds with DFPlayerMini
 * Check the readme file in upper folder to learn more about the player and
 * its configuration
 * 
 */

#include <Arduino.h>
#include "DFRobotDFPlayerMini.h"

HardwareSerial mySoftwareSerial(1);
DFRobotDFPlayerMini myDFPlayer;


void setup()
{
  mySoftwareSerial.begin(9600, SERIAL_8N1, 16, 17);
  Serial.begin(115200);
  
  Serial.println(F("Initializing DFPlayer ..."));

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(myDFPlayer.readType(),HEX);
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.setTimeOut(500);
  
  myDFPlayer.volume(20);  //Set volume value (0~30).

  // plays file 0001.mp3 on sd-card
  myDFPlayer.play(1);
}

void loop() {

}
