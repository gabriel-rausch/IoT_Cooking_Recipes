#include <WiFi.h>
#include <HTTPClient.h>
#include <wifi_credentials.h>

int restartCounter = 0;
int wifiCheckCounter = 0;

void initWifi() {
  WiFi.begin(WIFI_SSID, WIFI_PW);
  Serial.print("Connecting...");
  delay(500);

  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(500);
    restartCounter++;
    Serial.println("Waiting for connection");
    if (restartCounter >= 5)
    {
      Serial.println("Restart ESP");
      ESP.restart();
    }
  }

  restartCounter = 0;
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.isConnected());
}

void checkWifi() {
  if (wifiCheckCounter >= 100)
  {
    wifiCheckCounter = 0;
    if (WiFi.status() != WL_CONNECTED)
    {
      Serial.println("WiFi disconnected - restart ESP");
      ESP.restart();
    }
    else
    {
      Serial.println("WiFi still connected...");
    }
  }

  wifiCheckCounter++;
}


String timeStampRequest() {
    if ((WiFi.waitForConnectResult() == WL_CONNECTED)) {     

        HTTPClient http;
        http.begin("https://time.gentlemens-squad.de/seconds"); // baut sich das HTTP-Konstrukt zusammen mit der URL
        int httpCode = http.GET();                                     
        String time = "";
        if (httpCode > 0) {            
             time = http.getString();
        }
        else {
            Serial.println("Error on HTTP request");
        }
        http.end(); 
        return time;
    }
}

// void callURL(String url) {
//   if (WiFi.status() == WL_CONNECTED) {

//     HTTPClient http;

//     http.begin(url);
//     int httpCode = http.GET();
//     http.end();
//   }
// }