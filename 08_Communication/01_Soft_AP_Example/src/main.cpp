#include <WiFi.h>
#include <WebServer.h>

// SSID & Password
const char *ssid = "ESP32 serving you"; // Enter your SSID here
const char *password = NULL;            //Can also be a string with a password

// Use this IP adress after connecting to the AP
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80); // Object of WebServer(HTTP port, 80 is defult)

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>Hello from ESP32 Soft Access Point :D</h1>\
</body>\
</html>";

// Handle root url (/)
void handle_root()
{
  server.send(200, "text/html", HTML);
}

void setup()
{
  Serial.begin(115200);

  // Create SoftAP
  WiFi.hostname("esp_demo"); //This does not work as of yet, let me know if you get it working. Use 192.168.1.1 to connect for now
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);

  Serial.print("Connect to My access point: ");
  Serial.println(ssid);

  server.on("/", handle_root);

  server.begin();
  Serial.println("HTTP server started");
  delay(100);
}

void loop()
{
  server.handleClient();
}
