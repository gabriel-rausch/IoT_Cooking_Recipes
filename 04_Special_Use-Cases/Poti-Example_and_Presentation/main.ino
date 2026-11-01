//poti readout and mapping - The Fundamentals of IoT SoSe21
//Code by Mike Blank 

#define poti A1

int long potiAkt;
int long potiMap;

void setup() {
    pinMode(poti, INPUT);       //configure pin as input
    Serial.begin(115200);       //start Serialoutput
}

void loop() {   
    potiAkt = analogRead(poti);                 //read current poti possition
    potiMap = map(potiAkt, 0, 1024, 0, 100);    //map current possition to 0 - 100

    Serial.print("Wir sind bei: ");             //do fancy serial out
    Serial.print(potiMap);
    Serial.println("%");
}