# Station: Hello World – Blink

In dieser Station startest du ein ESP32-Projekt mit PlatformIO und probierst drei Grundlagen aus: serielle Ausgabe, LED-Steuerung und Touch-Erkennung. Zum Schluss soll die LED auf eine Berührung reagieren.

## Material und Aufbau

- ESP32-Dev-Board mit Touch-Funktion, USB-Kabel und Breadboard
- LED mit Vorwiderstand (z. B. 220–1.000 Ω), Jumperkabel
- Visual Studio Code mit PlatformIO

Verbinde **GPIO 13** über den Vorwiderstand mit der LED-Anode und die Kathode mit **GND**. Verbinde ein Jumperkabel mit **GPIO 4**; das freie Ende dient als Touchfläche. Baue die Schaltung ohne Stromversorgung auf. Pinbelegung und Touch-Funktionen können je nach ESP32-Modell abweichen.

## Aufgaben

1. **Starten:** Öffne das Projekt, kompiliere es, übertrage es auf den ESP32 und öffne den seriellen Monitor mit **115200 Baud**.
2. **Serielle Ausgabe:** Ergänze Variablen verschiedener Datentypen und gib Namen und Werte mit `Serial.print()` aus. Beobachte, wann `setup()` ausgeführt wird.
3. **LED blinken lassen:** Beobachte LED und Meldungen `On`/`Off`. Ändere `delay()` und beschreibe den Effekt auf das Blinktempo.
4. **Touch testen:** Gib den Wert von `touchRead(4)` im seriellen Monitor aus und vergleiche ihn bei freiem und berührtem Kabel. Passe den Schwellwert `40` an deine Messwerte an.
5. **Sensor und Aktor verbinden:** Ändere den Code so, dass die LED nur bei erkannter Berührung leuchtet und sonst ausgeschaltet ist.

## Prüfe dein Verständnis

- Was machen `pinMode()`, `digitalWrite()` und `delay()`?
- Wie verändert sich der Touch-Wert beim Berühren?

**Tipp:** Bei klassischen ESP32-Modellen sinkt der Touch-Wert beim Berühren häufig. Das Verhalten hängt vom Board und Aufbau ab. Wenn die Erkennung nicht funktioniert, prüfe den verwendeten Touch-Pin und beobachte zuerst die Messwerte.
