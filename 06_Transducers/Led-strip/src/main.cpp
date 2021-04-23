#include <Arduino.h>
#include <analogWrite.h> //external library defined in platformio.ini

int red = 18;
int blue = 21;
int green = 19;
int blue_value = 255;
int green_value = 255;
int red_value = 255;

void setup() {
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
    Serial.begin(9600);
    red_value = 1;  // start fade with red
}

void loop() {
    analogWrite(red, red_value);
    analogWrite(green, green_value);
    analogWrite(blue, blue_value);

    if (red_value < 255 && blue_value == 255) {
        red_value++;
        green_value--;
    }
    if (green_value < 255 && red_value == 255) {
        green_value++;
        blue_value--;
    }
    if (blue_value < 255 && green_value == 255) {
        red_value--;
        blue_value++;
    }
    Serial.printf("rgb(%d,%d,%d)\n", red_value, green_value, blue_value);

    delay(30);
}