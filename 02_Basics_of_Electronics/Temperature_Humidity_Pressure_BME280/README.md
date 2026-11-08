# Station: Temperatur und Luftfeuchtigkeit mit dem BME280

In dieser Station liest du Temperatur, Luftfeuchtigkeit und Luftdruck mit einem BME280 aus. Der Sensor überträgt seine Messwerte digital über den I²C-Bus.

## Material und Aufbau

- ESP32-Dev-Board und USB-Kabel
- BME280-Modul, Breadboard und Jumperkabel

Verbinde **3V3** mit **VIN** (oder **VCC**) und **GND** mit **GND**. Verbinde **SDA** mit **GPIO 21** und **SCL** mit **GPIO 22**. Verwende ein BME280-Modul, das mit 3,3-V-Logik arbeitet.

## Aufgabe

Öffne dieses Projekt in PlatformIO, lade es auf den ESP32 und öffne den seriellen Monitor mit **115200 Baud**. Beobachte Temperatur, relative Luftfeuchtigkeit und Luftdruck. Verändere die Bedingungen um den Sensor (zum Beispiel durch Annähern der Hand) und vergleiche die Messwerte.

Das Programm verwendet die I²C-Adresse **0x76**. Falls dein Modul die Adresse **0x77** verwendet, ändere die Adresse im Aufruf von `sensor.begin()` in `src/main.cpp`.
