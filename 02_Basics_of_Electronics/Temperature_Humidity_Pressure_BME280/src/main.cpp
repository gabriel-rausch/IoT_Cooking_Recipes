// Station: Temperatur und Luftfeuchtigkeit mit dem BME280

#include <Arduino.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 sensor;

void setup() {
  Serial.begin(115200);

  if (!sensor.begin(0x76)) {
    Serial.println("BME280 nicht gefunden. Anschluss und I2C-Adresse pruefen.");
    while (true) {
      delay(1000);
    }
  }
}

void loop() {
  Serial.print("Temperatur: ");
  Serial.print(sensor.readTemperature());
  Serial.println(" °C");

  Serial.print("Luftfeuchtigkeit: ");
  Serial.print(sensor.readHumidity());
  Serial.println(" %");

  Serial.print("Luftdruck: ");
  Serial.print(sensor.readPressure() / 100.0F);
  Serial.println(" hPa");
  Serial.println();

  delay(1000);
}
