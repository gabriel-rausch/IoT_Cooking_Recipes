// This example uses an ESP32 Development Board
// to connect to shiftr.io.
//
// You can check on your device after a successful
// connection here: https://www.shiftr.io/try.
//
// by Joël Gähwiler
// https://github.com/256dpi/arduino-mqtt

#include <Arduino.h>
#include <WiFi.h>
#include <MQTT.h>

const char ssid[] = "ssid";
const char pass[] = "pass";

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;
const int runTime = 120000;
bool humidity = false;

void connectWifi() {
  Serial.print("\nConnecting wifi...");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
}

void connectMQTTTclient() {
  Serial.print("\nConnecting Client...");

  while (!client.connect("esp-iot", "public", "public")) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("\nFully Connected!");
  Serial.println("");

  client.subscribe("iot/hello");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("Nachricht auf dem Kanal: " + topic);
  Serial.println("--> " + payload);
  Serial.println("");
  if(topic == "iot/hello"){
    digitalWrite(21, 1);
    delay(1000);
    digitalWrite(21, 0);
  }
}


void setup() {
  pinMode(21, OUTPUT);

  Serial.begin(115200);
  WiFi.begin(ssid, pass);

  client.begin("public.cloud.shiftr.io", net);
  client.onMessage(messageReceived);

  connectWifi();
  connectMQTTTclient();
}

void loop() {
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  // make sure the client is connected to the broker
  if (!client.connected() && millis() < runTime) {
    connectMQTTTclient();
  }

  // publish a message roughly every 5 seconds on own topic.
  if (millis() - lastMillis > 5000) {
    lastMillis = millis();
    Serial.println(millis());
    client.publish("iot/hello", "world");
  }

  // subscribe to new topic after some time (last condition only for testing)
  if(millis() > 60000 && !humidity && millis() < runTime ){
    humidity = true;
    Serial.println("Subscribed to Humidity");
    Serial.println("");
    client.subscribe("ESP_Easy/BME280/Humidity");
  }

  // disconnect and unsubscribe for next test
  if(millis() > runTime && humidity){
    Serial.println("Disconnecting and Unsubscribing Client");
    client.disconnect();
    client.unsubscribe("iot/hello");
    client.unsubscribe("ESP_Easy/BME280/Humidity");
    humidity = false;
  }
}