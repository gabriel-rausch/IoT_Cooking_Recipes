#include <WiFi.h>
#include <HTTPClient.h>
#include <wifi_credentials.h>

int restartCounter = 0;
int wifiCheckCounter = 0;

void initWifi()
{
  WiFi.begin(WIFI_SSID, WIFI_PW);
  Serial.print("Connecting...");
  delay(500);

  // improved from Z3r0cks and alexander-jaroch
  // instead of status, better waitForConnectResult
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    delay(500);
    restartCounter++;
    Serial.println("Waiting for connection");
    if (restartCounter >= 10)
    {
      Serial.println("Restart ESP");
      ESP.restart();
    }
  }

  restartCounter = 0;
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void checkWifi()
{
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

/**
 * Call URL
 * type can be GET or POST, if POST then args should be provided
 * 
*/
void callURL(String url, String type, String POSTArgs = "")
{
  if (WiFi.status() == WL_CONNECTED)
  {

    HTTPClient http;


    http.begin(url);

    if (type == "POST") {
      http.addHeader("Content-Type", "text/plain");
      http.addHeader("Accept", "application/json");
      http.POST(POSTArgs);
    } else {
      http.GET();
    }
    
    http.end();
  }
}
