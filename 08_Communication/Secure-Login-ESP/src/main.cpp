// Load Wi-Fi library
#include <WiFi.h>

// Access Point Credentials
const char *ssid = "IoT-Secure-AP";
const char *password = "123456789";

//Set Login Credentials
const char *base64Encoding = "aW90OnNlY3VyZQ=="; //base64 Credentials for "iot:secure"

// Set web server port number to 80
WiFiServer server(80);
String header;

void setup()
{
    Serial.begin(115200);

    // Connect to Wi-Fi network with SSID and password
    WiFi.softAP(ssid, password);

    // Print local IP address and start web server
    IPAddress IP = WiFi.softAPIP();
    Serial.println("IP address: ");
    Serial.println(IP);
    server.begin();
}

void loop()
{
    WiFiClient client = server.available(); // Listen for incoming clients


    if (client) //New connecting Client
    {
        Serial.println("New Client.");
        String currentLine = ""; //for incoming client data
        while (client.connected())
        {
            if (client.available()) //check for bytes to read
            {                           
                char c = client.read(); 
                Serial.write(c);        
                header += c;
                if (c == '\n') //End of Client Request, Send Response 
                {
                    if (currentLine.length() == 0)
                    {

                        if (header.indexOf(base64Encoding) >= 0) //check username and password
                        {
                            client.println("HTTP/1.1 200 OK"); //Response Code
                            client.println("Content-type:text/html");
                            client.println("Connection: close");
                            client.println();

                            client.println("<!DOCTYPE html>\n"); //Secured Webpage
                            client.println("<html>\n");
                            client.println("<body>\n");
                            client.println("<h1 style=\"color:blue;\">ESP32 Secure Webserver</h1>\n");
                            client.println("<p>Your Princess is in another Castle...</p>");
                            client.println("</body>\n");
                            client.println("</html>");

                            break;
                        }
                        // Wrong user or password
                        else
                        {
                            client.println("HTTP/1.1 401 Unauthorized");
                            client.println("WWW-Authenticate: Basic realm=\"Secure\"");
                            client.println("Content-Type: text/html");
                            client.println();
                            client.println("<html>Authentication failed</html>");
                            break;
                        }
                    }
                    else //Input is a newline, clear currentLine 
                    {
                        currentLine = "";
                    }
                } else if (c != '\r'){
                    currentLine += c;
                }
                
            }
        }
        // Clear header variable
        header = "";
        // Close connection
        client.stop();
        Serial.println("Client disconnected.");
        Serial.println("");
    }
}