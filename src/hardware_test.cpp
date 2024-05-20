#include <Arduino.h>
#include <Wire.h>
#include "pitches.hcc"
#include "hardware_test/analog_threshold.cpp"
#include "hardware_test/I2C.cpp"
#include "hardware_test/joystick.cpp"
#include "hardware_test/buzzer.cpp"
#include "hardware_test/display.cpp"

void play_note(int note, int playback_time) {
    pinMode(buzzer_pin, OUTPUT);
    tone(buzzer_pin, note);
    delay(playback_time);
    noTone(buzzer_pin);
}

void setup() {
    Wire.begin();
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    if (!isJoystickConnected()) {
        Serial.println("Joystick nicht angeschlossen");
        play_note(37, 250);
        delay(250);
        play_note(37, 250);
        delay(250);
    }
    if (!isBuzzerConnected()) {
        Serial.println("Buzzer nicht angeschlossen");
        for (int i = 0; i < 3; ++i) {
            digitalWrite(LED_BUILTIN, LOW);
            delay(200);
            digitalWrite(LED_BUILTIN, HIGH);
            delay(200);
        }
    }
    if (!isDisplayConnected()) {
        Serial.println("Display nicht angeschlossen");
        play_note(37, 1000);
    }
}
