#include "BLEDevice.h"
#include <Arduino.h>

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice advertisedDevice) {
    Serial.print("Device found: ");
    if (advertisedDevice.haveName()) {
      Serial.print(advertisedDevice.getName().c_str());
    } else {
      Serial.print("Unknown device");
    }
    Serial.print(" RSSI: ");
    Serial.println(advertisedDevice.getRSSI());
  }
};

void setup() {
  Serial.begin(115200);
  BLEDevice::init("ESP32_MyDevice");

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(BLEUUID((uint16_t)0x180D));
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();

  // Start scanning
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true);
  pBLEScan->start(30);
}

void loop() {
  // put your main code here, to run repeatedly:
}