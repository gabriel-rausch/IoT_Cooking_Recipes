# Basics Coding CheatSheet

Here you'll find a quick overview of basic code fragments for Ardunio / ESP programming.  
This is a living document: feel free to add further aspects (via pull request).

## Fundamentals

### Variables
```cpp
type varName; // general variable declaration
type varName = value;

const type varName; // declaration of constant

#define VARNAME // constant that is replaced when compiling (a global example is HIGH or LOW)
```


### Arrays
```cpp
type arrayName[]; // general array declaration with defined number of items
type arrayName[]={value1, value2, value3};

type arrayName[NUMBEROFITEMS]; // declaration with defined max number of items

arrayName[index]; // get value of index (note: array index starts at 0)
```


### Data Types
```cpp
void // func: no data will be returned

bool­ean // true or false / 1 or 0

char // charater values, 'A' or "ABC" or 123

int // integer -32.768 to 32.767

long // integer -2.147.48­3.648 to 2.147.4­83.647

float // floating point number -3,402­823­5*­1038 to bis 3,4028­235­*1­038```

String // is not a data type but a simple approach to create a String class instance to handle strings. Downside: costs more of memory
String stringName = "value";
```


### Operators
```cpp
= // assigment operator

+ - * / % // add subtract multiply divide modulo

++ // increment
-- // decrement
+= // compound addition / substration / multiplication ...
```

### Comments
```cpp
// single line

/*
  block comment
*/
```


### Fundamental Examples 
```cpp
#define MYCONST 123

char mynumber = 27;

char myName[8] = "Gabriel";

String myString = "Lorem Ipsum";

String animals[3] = {"Dog", "Cat", "Bird"};

int sensorData[100] = {24, 23, 26, 15, 142, 1};

// add some more sensor data
sensorData[6] = 35;

// output this data could look like this
Serial.println( myName );
Serial.println( "Content of Var: " + myString );
Serial.println( MYCONST + mynumber + 1 );
Serial.println( animals[0] );
Serial.println( animals[1] );
Serial.println(sizeof(sensorData)/sizeof(int));
```




## Control Structures

## Conditions
```cpp
// conditional branching
if (var1 < var2) {
    
} else if (var1 < var3) {
    
} else {

}

// switch case
switch (var1) {
    case 1: 
        // ...
        break;
    case 2:
        // ...
        break
    default:
        // ...
}
```

### Logical Operators
```cpp
== // equal to
!= // not equal to
< // less than
> // greater than
<= // less than or equal to
>= // greater than or equal to
```

### Concatenation Operators
```cpp
&& // and
|| // or
! // not
```


## Loops
```cpp
// while loop
while (var1 < 10) {
    // ...    
}

// do-while loop
do {
    // ...
} while ( var1 < 10);

// for loop
for (int index = 0; index < 10; index++) {
    
}
```

## Function
```cpp
returnDataType functionName () {

}

void myFunction () {
    // ... do something
}

int anotherFunc () {
    // ... calculate something
    return numberValue;
}
```


## Basic Skeleton
```cpp
void setup() {
    // runs once after the MCU starts up
}

void loop() {
    // is called repeatedly (around 2-5 µSek)
}
```

## Global Methods

### Pin I/O
```cpp
pinMode(PIN, VALUE); // change mode of PIN: INPUT, INPUT_PULLUP or OUTPUT

digitalWrite(PIN, VALUE); // write value to pin

digitalRead(PIN); // read value of pin

touchRead(PIN); // read capacitive input value

```

### Serial
```cpp
// open up the serial monitor to inspect the output 

Serial.begin(SpeedOfBaudrate); // set speed of bits per second for serial data transmission
Serial.begin(115200); // e.g. 9600, 19200, 115200

Serial.print("text" + variable); // print text to serial monitor

Serial.println("text" + variable); // print one line of text

Serial.println("text" + variable); // print bytes
```

### Time
```cpp
delay(MSEC); // pause for miliseconds

delayMicroseconds(USEC) // paues for microseconds
```

### Math

```cpp
min(var1, var2); // calculates minimum of two num

max(var1, var2) // calculates max of two num

map(value, fromLow, fromHigh, toLow, toHigh); // map a value from one scale to another scale

constrain(value, limitLow, limitHigh); // limits a value to a specific scale

randomSeed(StartValue); // this method can be called initially to set the pseudo-random number generator. The starting value should be some fairly random data, e.g. from an analog pin input.

random(0,100); // (pseudo-) random numbers
```

## Libraries
```cpp
// additional files and external library can be included
#include <additionalLibrary.h>
#include <PubSubClient.h>
#include <WiFiClient.h>
```

Go deeper in the official docs [https://www.arduino.cc/reference/en/](https://www.arduino.cc/reference/en/)