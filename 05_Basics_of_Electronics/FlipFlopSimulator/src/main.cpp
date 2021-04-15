#include <Arduino.h>

#define SET 5
#define RESET 18
#define Q 16
#define Q_INV 17

void write(bool q)
{
  digitalWrite(Q, q);
  digitalWrite(Q_INV, !q);
}

void setup()
{
  // put your setup code here, to run once:
  // Serial.begin(115200);
  pinMode(5, INPUT);
  pinMode(18, INPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  write(false);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (digitalRead(SET) == 0)
  {
    write(true);
  }
  else if (digitalRead(RESET) == 0)
  {
    write(false);
  }
}
