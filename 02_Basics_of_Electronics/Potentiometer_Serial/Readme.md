# Station: Potentiometer und Serial Monitor

In dieser Station liest du die Stellung eines Potentiometers mit dem Analog-Eingang des ESP32 aus. Beim Drehen verändert sich der Messwert, den du im seriellen Monitor beobachten kannst.

## Material und Aufbau

- ESP32-Dev-Board und USB-Kabel
- Potentiometer (z. B. 10 kΩ) und Jumperkabel

Verbinde die beiden äußeren Anschlüsse des Potentiometers mit **3V3** und **GND**. Verbinde den mittleren Anschluss (Schleifer) mit **GPIO 34**.

## Aufgabe

Öffne das Projekt in PlatformIO, lade es auf den ESP32 und öffne den seriellen Monitor mit **115200 Baud**. Drehe das Potentiometer langsam und beobachte, wie sich der ausgegebene Messwert verändert. Erkläre, warum der ESP32 den Wert analog einliest und nicht nur zwischen `HIGH` und `LOW` unterscheidet.

Der Messwert wird alle 200 ms ausgegeben. Bei der eingestellten 12-Bit-Auflösung liegt er typischerweise zwischen 0 und 4095; der tatsächlich erreichbare Bereich kann je nach ESP32-Modell variieren.
