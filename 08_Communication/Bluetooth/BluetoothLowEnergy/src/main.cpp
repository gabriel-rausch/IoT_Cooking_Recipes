#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// BLE characteristics
BLECharacteristic *pCharacteristic; //Pointer for a Characteristic Object to transmit Data to Phone
bool deviceConnected = false;
int txValue = 0;

const int led = 23;

// Defining the service & characteristics

// Generator: https://www.uuidgenerator.net/
const char *SERVICE_UUID = "c8a9fd2b-569c-4b63-980c-8fe1e0eeeace";
const char *CHARACTERISTIC_UUID_RX = "289be909-7ef4-491b-9571-23c795e1f2c3";
const char *CHARACTERISTIC_UUID_TX = "c0305350-94c8-4701-8bd7-a135d517219b";

// Class for servicCallbacks
class MyServerCallbacks : public BLEServerCallbacks // Inheritance
{
  void onConnect(BLEServer *pServer) // Overwrite functions
  {
    deviceConnected = true;
  }

  void onDisconnect(BLEServer *pServer)
  {
    deviceConnected = false;
  }
};

class MyCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic)
  {
    std::string rxValue = pCharacteristic->getValue();

    if (rxValue.length() > 0)
    {
      Serial.println("=====START=RECEIVE=====");
      Serial.print("Received Value: ");

      for (int i = 0; i < rxValue.length(); i++)
      {
        Serial.print(rxValue[i]);
      }

      // Do stuff based on the command received from the app
      if (rxValue == "1")
      {
        Serial.println("TURNING ON!");
        digitalWrite(led, HIGH);
      }
      else if (rxValue == "0")
      {
        Serial.println("TURNING OFF!");
        digitalWrite(led, LOW);
      }

      Serial.println();
      Serial.println("=====END=RECEIVE====");
    }
  }
};

void setup()
{
  Serial.begin(9600);

  pinMode(led, OUTPUT);

  // Create the BLE Device
  BLEDevice::init("ESP32BluetoothLowEnergy");

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic to notify Phone
  pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID_TX,
      BLECharacteristic::PROPERTY_NOTIFY);

  // BLE2902 needed to notify - Descriptor
  pCharacteristic->addDescriptor(new BLE2902());

  // Characteristic for data receiving from Phone
  BLECharacteristic *pRXCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID_RX,
      BLECharacteristic::PROPERTY_WRITE);

  pRXCharacteristic->setCallbacks(new MyCallbacks());

  pService->start();

  pServer->getAdvertising()->start();
  Serial.println("Wating for a client connection to notify...");
}

void loop()
{
  if (deviceConnected)
  {
    txValue = random(-10, 20); // Danke an Arduino.h !!!

    // Conversion of txValue
    char txString[8];
    dtostrf(txValue, 1, 2, txString); // Converts number to char array -> no return

    //Setting the value to the characteristic
    pCharacteristic->setValue(txString);

    //Notifying the connected client
    pCharacteristic->notify();
    Serial.println("Set value: " + String(txString));
    delay(1000);
  }
}