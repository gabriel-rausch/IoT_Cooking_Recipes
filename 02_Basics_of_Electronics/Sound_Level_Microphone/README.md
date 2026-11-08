# Station: Geräuschpegel mit einem Mikrofonmodul beobachten

In dieser Station liest du den analogen Ausgang eines Mikrofonmoduls ein. Du beobachtest, wie sich der Rohwert bei unterschiedlichen Geräuschen verändert.

## Material und Aufbau

- ESP32-Dev-Board und USB-Kabel
- Mikrofonmodul mit analogem Ausgang **AO**, Breadboard und Jumperkabel

Verbinde **GND** des Moduls mit **GND** des ESP32, seine Versorgung mit **3V3** und den analogen Ausgang **AO** mit **GPIO 34**. Prüfe das Datenblatt deines Moduls: Das Signal an **AO** darf höchstens **3,3 V** betragen. Verbinde nicht den digitalen Schwellwert-Ausgang **DO**.

## Aufgabe

Öffne das Projekt in PlatformIO, lade es auf den ESP32 und öffne den seriellen Monitor mit **115200 Baud**. Vergleiche die ausgegebenen Werte bei Ruhe und bei verschiedenen Geräuschen. Überlege, warum ein einzelner Rohwert die Lautstärke nicht zuverlässig beschreibt.

Der ADC-Rohwert ist keine Messung in Dezibel. Das Beispiel zeichnet keine Audiodaten auf und führt keine Spracherkennung durch.
