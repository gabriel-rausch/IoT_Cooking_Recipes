/**
 * 
 * Selfmadey Makey
 * 
 * This processing sketch is a simple starting point
 * to play some sound when the banana/apple/... with the ESP
 * is touched.
 * The skeleton listens on the serial port (here default port is 3,
 * please check your ports). When value is 1 than the screen is colorized.
 *
 * You need to: 
 * 0) perhaps you need to adjust the basic settings (port, baudrate, sensorValue)
 * 1) add the sound functionality (the processing docs
 * provide great information about these lines of code).
 * 2) adjust the code if you receive more than just one data
 * (currently listening for 1 and 0, you can extend that)
 *  
*/
 
import processing.serial.*;


Serial port;

void setup()
{
  String portName = Serial.list()[3];
  port = new Serial(this, portName, 115200);
  port.clear();
}

void draw()
{
  if ( port.available() > 0) 
  {
    String sensorValString = port.readStringUntil(13);
    
    if (sensorValString != null && sensorValString.length() < 4) {
      int sensorValInt = Integer.parseInt(trim(sensorValString));
      println(sensorValInt);
      
      if(sensorValInt == 1) {
        background(255,0,0);
      } else {
        background(255,255,255);
      }
    }
  } 
  
}
