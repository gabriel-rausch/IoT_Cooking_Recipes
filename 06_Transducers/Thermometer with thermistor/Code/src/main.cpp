/************************************************************************
 * Codebeispiel zur Berechnung der Temperatur mit Hilfe eines           *
 * NTC Heißleiter Thermisor                                             *
 * **********************************************************************/

#include <Arduino.h>


/************************************************************************
 *           Hier müssen Variablen ndividuell angepasst werden         *
 ************************************************************************/

#define powerPin 21 //Pin für Strom
#define thermistorInputPin 26 //Analoger Input Pin des Temperatursensors

#define maxAnalogOutput 4095 //Maximaler Wert den der Thermistor ausgeben kann (Achtung: kein Ohm! Muss erst in Ohm umgerechnet werden)

#define referenceResistor 2300 //Wert des statischen Widerstands in Ohm(sollte gleich zu R_25 sein, sonst gibt es kiene genauen Werte) 

#define T_25 25 //Raumtemperatur (sind bei dieser Berechnung immer 25°C)
#define R_25 2000 //Widerstand des Temperatursensors bei 25°C (Aus Datenblatt des Sensors zu entnehmen)


/*********************************************************************************************
 * Werte im Steinhart–Hart Koeffizienten Rechner berechnen                                   *
 * und hier eintragen                                                                        *
 * https://www.thinksrs.com/downloads/programs/therm%20calc/ntccalibrator/ntccalculator.html *                                                  *
 *********************************************************************************************/
#define scA 27.01318840e-3 //e-3 entspricht *10^-3
#define scB -39.52305481e-4 //e-4 entspricht *10^-4
#define scC 145.3301220e-7 //e-7 entspricht *10^-7
 

/************************************************************************
 *                              Setup                                   *
 *                  Ab hier muss nichts mehr verändert werden           *
 ************************************************************************/ 
void setup(void) {
  Serial.begin(115200);

  pinMode(powerPin, OUTPUT);
  pinMode(thermistorInputPin, INPUT);

  digitalWrite(powerPin, HIGH);

  Serial.println("Setup Finished");
}
 

/************************************************************************
 *                     Ab hier Nur noch Formeln                         *
 ************************************************************************/

void loop(void) {
/************************************************************************
 *                     Berechnung des Widerstands im NTC                *
 ************************************************************************/
  float resistance;
  float thermometerInputValue = analogRead(thermistorInputPin);
    Serial.print("Analog Input ");
    Serial.println(thermometerInputValue);
   


  resistance = referenceResistor * (maxAnalogOutput/thermometerInputValue - 1.0);  // Widerstand im Thermistor
   Serial.print("Resistance ");
  Serial.println(resistance);

/************************************************************************
 *                  Bererchnung der Temperatur                          *
 ************************************************************************/
  float T_Kelvin = 1.0/(scA + scB * log(resistance) + scC * (pow(log(resistance),3))); //Steinhart-Hart Gleichung (Ergebnis in Kelvin)
  float T_Celsius = T_Kelvin -273.15; //Umrechnung von Kelvon in Celsius
  Serial.println(T_Celsius);
  Serial.println();
  delay(1000);
}

