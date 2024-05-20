// Buzzer
#define buzzer_pin 0

#include <vector>

const std::vector<int> &buzzer_pins = {buzzer_pin};
const int buzzer_threshold = 20;

bool isBuzzerConnected() {
    return thresholdExceeded(buzzer_pins, buzzer_threshold);
}
