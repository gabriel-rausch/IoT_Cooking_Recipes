# Station: Adressierbarer RGB-LED-Streifen

In dieser Station steuerst du einen WS2812-kompatiblen RGB-LED-Streifen. Im Gegensatz zu einem analogen RGB-Streifen wird hier jede LED über eine Datenleitung einzeln angesteuert.

## Material und Anschluss

- ESP32-Dev-Board mit USB-Kabel
- WS2812-/NeoPixel-kompatibler 5-V-LED-Streifen
- Jumperkabel

Für diese Station wird nur **ein Pixel** (oder wenige Pixel) verwendet. Verbinde den Streifen bei abgezogenem USB-Kabel:

```text
ESP32 (USB-versorgt)       WS2812-Streifen
5V / VIN ----------------- 5V
GND ---------------------- GND
GPIO 18 ------------------ DIN
```

Verwende nur einen Streifen, dessen Daten-Eingang mit 3,3-V-Logik des ESP32 kompatibel ist. Der Beispielcode begrenzt die Helligkeit. Schließe für diese einfache USB-Versorgung keine weiteren LEDs an und verbinde niemals den 5-V-Anschluss des Streifens mit einem GPIO. Wenn dein Streifen eine andere Versorgung oder einen Pegelwandler benötigt, ist er für diesen Aufbau nicht geeignet.

## Aufgabe

Öffne das Projekt in PlatformIO, lade es auf den ESP32 und öffne den seriellen Monitor mit **115200 Baud**. Beobachte den Farbverlauf und die ausgegebenen RGB-Werte. Ändere die Wartezeit oder Helligkeit und beschreibe den Effekt.
