#include "WiFi.h"
#include "SPIFFS.h"
#include "ESPAsyncWebServer.h"
#include <DNSServer.h>
#include <ESPmDNS.h>

const char *ssid = "ESP32 Goodness";
const char *password = NULL;

//DNS
const byte DNS_PORT = 53;
DNSServer dnsServer;

AsyncWebServer server(80);

// Use this IP adress after connecting to the AP
IPAddress accessPointIP(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);

class CaptiveRequestHandler : public AsyncWebHandler
{
public:
    CaptiveRequestHandler() {}
    virtual ~CaptiveRequestHandler() {}

    bool canHandle(AsyncWebServerRequest *request)
    {
        return true;
    }

    void handleRequest(AsyncWebServerRequest *request)
    {
        request->send(SPIFFS, "/index.html", "text/html");
    }
};

void setup()
{
    //Setup WiFi AP
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(accessPointIP, accessPointIP, subnet);

    Serial.begin(115200);

    //Initialize SPIFFS
    if (!SPIFFS.begin())
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }

    //DNS Server setup
    dnsServer.setTTL(300);
    dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
    dnsServer.start(DNS_PORT, "*", accessPointIP);
    Serial.println("DNS server started");

    // Connect to Wi-Fi network with SSID and password
    Serial.println("Setting AP (Access Point)…");
    server
        .serveStatic("/", SPIFFS, "/")
        .setDefaultFile("index.html");

    //Connection handlers
    server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->redirect("/index.html");
    });

    Serial.println("Starting server...");
    server.begin();
    Serial.println("Setup done.");
}

void loop()
{
    dnsServer.processNextRequest();
}