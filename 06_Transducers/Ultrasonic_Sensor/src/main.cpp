#include <Arduino.h>

int PIN_TRIGGER = 15; //Trigger Pin
int PIN_ECHO = 4; //Echo Pin


/********* Zusatz RGB LED *********
int LED_RED = 18;
int LED_GREEN = 19;
int LED_BLUE = 5;
*/

const int SENSOR_MAX_RANGE = 400; //Maximal Wert des Sensors
long duration; //Konstante für die Zeit
long distance; //Konstante für die Distanz

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

/****Zusatz RGB LED ***********
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_GREEN, LOW); 
  
  **********/
}

void loop()
{
  digitalWrite(PIN_TRIGGER, LOW);  //Trigger pin LOW "Aus"
  delayMicroseconds(10);

  digitalWrite(PIN_TRIGGER, HIGH); //Trigger Pin HIGH zum Aussenden des Ultraschallsignals
  delayMicroseconds(10);

  duration = pulseIn(PIN_ECHO, HIGH); //Zeit bis Signal wieder beim Echo Pin ankommt
  distance = (duration / 2) * 0.03432; //Berechnung der Distanz

  if (distance > SENSOR_MAX_RANGE || distance <= 0)
  {
    Serial.println("Out of Range");
  }

  else {
    Serial.println("Abstand: " + String(distance) + " cm");
  }

/******Zusatz RGB-LED ********
  else if (distance <= 14 && distance >= 2)
  {
    Serial.println("Abstand: " + String(distance) + " cm");
    digitalWrite(LED_GREEN, 255);
    delay(100);
    digitalWrite(LED_GREEN, LOW);
  }

  else if (distance <= 25 && distance >= 14)
  {
    Serial.println("Abstand: " + String(distance) + " cm");
    digitalWrite(LED_GREEN, 255);
    digitalWrite(LED_RED, 255);
    delay(100);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, LOW);
  }

  else if (distance <= 400 && distance >= 25)
  {
    Serial.println("Abstand: " + String(distance) + " cm");
    digitalWrite(LED_RED, 255);
    delay(100);
    digitalWrite(LED_RED, LOW);
  }
  ******************/

  delay(100);
}
