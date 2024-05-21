#include <Arduino.h>
#include <vector>

bool thresholdReached(const std::vector<int> &pins, int threshold) {
    for (int pin: pins) {
        pinMode(pin, INPUT);
        if (analogRead(pin) < threshold) {
            return false;
        }
    }
    return true;
}

bool thresholdExceeded(const std::vector<int> &pins, int threshold) {
    for (int pin: pins) {
        pinMode(pin, INPUT);
        if (analogRead(pin) > threshold) {
            return false;
        }
    }
    return true;
}