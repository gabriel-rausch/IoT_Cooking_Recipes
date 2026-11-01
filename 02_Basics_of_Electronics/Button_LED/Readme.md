# Station: Button and LED

In dieser Station steuerst du eine LED mit einem Drucktaster. Dabei lernst du, einen digitalen Eingang zu lesen und den internen Pull-up-Widerstand des ESP32 zu verwenden.

## Material und Aufbau

- ESP32-Dev-Board und USB-Kabel
- Breadboard und Jumperkabel
- Drucktaster
- LED

Schließe die LED über **GPIO 13** und **GND** an. Verbinde den Taster zwischen **GPIO 18** und **GND**. Der Taster benötigt in dieser Schaltung keinen externen Widerstand, da der ESP32 den internen Pull-up aktiviert. Baue die Schaltung zunächst ohne Stromversorgung auf.

## Aufgaben

1. Öffne dieses Projekt in VS Code mit PlatformIO, kompiliere es und lade es auf den ESP32.
2. Öffne den seriellen Monitor mit **115200 Baud**. Drücke und löse den Taster: Die LED sollte beim Drücken leuchten, und der Monitor die Zustandsänderungen melden.
3. Erkläre, warum der Eingang bei `INPUT_PULLUP` im Ruhezustand `HIGH` und beim Drücken `LOW` liest.
4. Ändere das Programm so, dass die LED nach jedem Tastendruck ihren Zustand wechselt, statt nur während des Drückens zu leuchten.

## Hinweise

Taster haben je nach Bauform unterschiedliche Pin-Anordnungen; prüfe, welche Kontakte beim Drücken verbunden werden. Die GPIO-Nummern gelten für das konfigurierte ESP32-Dev-Board.
