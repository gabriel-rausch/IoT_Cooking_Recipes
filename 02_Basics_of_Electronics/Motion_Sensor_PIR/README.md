# Station: Bewegung mit einem PIR-Sensor erkennen

In dieser Station liest du den digitalen Ausgang eines PIR-Sensors (Passiv-Infrarot) aus. Der Sensor meldet, wenn er eine Bewegung beziehungsweise Änderung der Infrarotstrahlung in seinem Erfassungsbereich erkennt.

## Material und Aufbau

- ESP32-Dev-Board und USB-Kabel
- PIR-Sensormodul, Breadboard und Jumperkabel

Verbinde **GND** des Sensors mit **GND** des ESP32 und den Signalausgang **OUT** mit **GPIO 27**. Versorge das Modul entsprechend seinem Datenblatt. Der Signalausgang darf höchstens **3,3 V** liefern; verbinde niemals ein 5-V-Signal direkt mit einem ESP32-GPIO.

## Aufgabe

Öffne das Projekt in PlatformIO, lade es auf den ESP32 und öffne den seriellen Monitor mit **115200 Baud**. Warte nach dem Einschalten zunächst die Aufwärmzeit des Sensors ab. Bewege dich anschließend im Erfassungsbereich und beobachte den Wechsel des digitalen Signals.

Die Aufwärmzeit und die Dauer des Ausgangssignals hängen vom Sensormodul und seinen Einstellungen ab.
