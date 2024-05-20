#include <Arduino.h>
#include <vector>

const std::vector<int> &joystick_pins = {A2, A3};
const int joystick_threshold = 450;

bool isJoystickConnected() {
    return thresholdReached(joystick_pins, joystick_threshold);
}