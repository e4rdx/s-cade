bool isDisplayConnected() {
    if (!isI2CDeviceConnected(0x3C)) {
        return false;
    }
    return true;
}