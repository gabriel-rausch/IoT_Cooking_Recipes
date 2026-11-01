#include <Arduino.h>
int LED = 0;
int Button = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  pinMode(Button, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:x
  // Serial.println("Hello World");

  if(digitalRead(Button) == HIGH)
  {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED,LOW);
  }  
  Serial.print("Wert=");
  Serial.print(Button);
  Serial.println(" ");
}