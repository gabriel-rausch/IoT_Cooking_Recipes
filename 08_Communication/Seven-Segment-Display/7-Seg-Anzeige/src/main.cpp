/**
 * This example shows how to control a seven-digit-display with a shift-register.
 * For this example you need the shift-register typ 74HC95 and a seven-digit-display.
 *
 * For more details: See wireing and explanation in presentation pdf.
 * 
 */

#include <Arduino.h>


int dataPin = 15; // Pin to data pin of 74HC595 （Pin14）
int latchPin = 2; // Pin to latch pin of 74HC595 （Pin12）
int clockPin = 4; // Pin to clock pin of 74HC595 （Pin11）

byte num[] = {
    B00111111, // 0
    B00000110, // 1
    B01011011, // 2
    B01001111, // 3
    B01100110, // 4
    B01101101, // 5
    B01111101, // 6
    B00000111, // 7
    B01111111, // 8
    B01101111  // 9
};

void writeData(int value)
{
    // Set latchPin low 
    digitalWrite(latchPin, LOW);
    // Send serial data
    shiftOut(dataPin, clockPin, LSBFIRST, value);
    // Set latchPin to high
    digitalWrite(latchPin, HIGH);
}

void setup()
{
    // set pins to output
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
}

void loop()
{

    for (int i = 0; i < 10; i++)
    {
        writeData(~num[i]); // Send data
        delay(1000); 
        writeData(0xff);   // Clear display
    }
}
