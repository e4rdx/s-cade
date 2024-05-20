#include <Wire.h>

bool isI2CDeviceConnected(uint8_t address) {
    Wire.setClock(400000); // 400 kHz
    Wire.beginTransmission(address + 1); // probing another address first to prevent the bus from being stuck
    Wire.endTransmission();
    Wire.beginTransmission(address);
    bool error = Wire.endTransmission();
    return (error == 0);
}
