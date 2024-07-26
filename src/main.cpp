#include "BLEDevice.h"
#include <Arduino.h>

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice advertisedDevice) {
    Serial.print("Device found: ");
    Serial.print(advertisedDevice.getName().c_str());
    Serial.print(" RSSI: ");
    Serial.println(advertisedDevice.getRSSI());
  }
};


void setup() {
  Serial.begin(115200);
  BLEDevice::init("ESP-1");
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true);
  pBLEScan->start(30);
}

void loop() {
  // put your main code here, to run repeatedly:
}
