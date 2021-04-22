/**
 * In this example I use a third-party lib HTTPSServer to easily
 * create a self-signed SSL certificate and set up a https server
 * Read more here:
 * https://github.com/fhessel/esp32_https_server#setup-instructions
 * 
 */
#include <WiFi.h>
#include <HTTPSServer.hpp>
#include <SSLCert.hpp>
#include <HTTPRequest.hpp>
#include <HTTPResponse.hpp>
#include "webapp-index.h"
#include "service-worker.h"
 
using namespace httpsserver;

const char *ssid = "ESP32 Access Point";
const char *password = NULL;

IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
 
SSLCert * cert;
HTTPSServer * secureServer;
 
void setup() {
 
  Serial.begin(115200);
  
  /**
   * 
   * Create SSL Certificate
   * 
   */
  cert = new SSLCert();
  int createCertResult = createSelfSignedCert(
    *cert,
    KEYSIZE_2048,
    "CN=myesp.local,O=acme,C=US");
  if (createCertResult != 0) {
    Serial.printf("Error generating certificate");
    return; 
  }

  Serial.println("Certificate created with success");
  secureServer = new HTTPSServer(cert);
 
  /**
   * 
   * Star Access Point
   * 
   */
  
  WiFi.softAP(ssid, password);
  delay(500);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
  /**
   * 
   * Handle Requests
   * with HTTPS Server Instance
   * 
   */
  ResourceNode * nodeRoot = new ResourceNode("/", "GET", [](HTTPRequest * req, HTTPResponse * res){
    res->setHeader("Content-Type", "text/html");
    res->println(webappIndex);
  });
  secureServer->registerNode(nodeRoot);
  ResourceNode * nodeRootIndex = new ResourceNode("/index.html", "GET", [](HTTPRequest * req, HTTPResponse * res){
    res->setHeader("Content-Type", "text/html");
    res->println(webappIndex);
  });
  secureServer->registerNode(nodeRootIndex);

  ResourceNode * nodeServiceWorker = new ResourceNode("/service-worker.js", "GET", [](HTTPRequest * req, HTTPResponse * res){
    res->setHeader("Content-Type", "application/javascript");
    res->println(serviceWorkerJS);
  });
  secureServer->registerNode(nodeServiceWorker);

  
  /**
   * 
   * Start HTTPS Server
   * 
   */
  secureServer->start();
   
  if (secureServer->isRunning()) {
    Serial.println("Server ready.");
  }
}
 
void loop() {
  
  secureServer->loop();
  
  delay(10);
}