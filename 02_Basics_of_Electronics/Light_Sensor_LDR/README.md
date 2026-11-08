# Station: Helligkeit mit einem LDR messen

In dieser Station liest du mit einem lichtabhängigen Widerstand (LDR) die Helligkeit als analogen Messwert ein. Du beobachtest, wie sich der Wert bei unterschiedlichen Lichtverhältnissen verändert.

## Material und Aufbau

- ESP32-Dev-Board und USB-Kabel
- LDR, Widerstand (z. B. 10 kΩ), Breadboard und Jumperkabel

Baue einen Spannungsteiler auf: Verbinde den LDR mit **3V3** und einem gemeinsamen Messpunkt. Verbinde diesen Messpunkt über den Festwiderstand mit **GND** und zusätzlich mit **GPIO 34**. Schließe den ESP32 erst nach dem Aufbau an die Stromversorgung an.

## Aufgabe

Öffne das Projekt in PlatformIO, lade es auf den ESP32 und öffne den seriellen Monitor mit **115200 Baud**. Vergleiche die Messwerte bei abgedecktem und beleuchtetem LDR. Erkläre, warum der ESP32 einen analogen Eingang statt eines digitalen Eingangs verwendet.

Der ausgegebene Wert ist ein ADC-Rohwert, keine Messung in Lux. Sein Verlauf hängt von der Anordnung des LDR und des Festwiderstands ab.
