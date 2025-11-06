#include "input.h"

#define DEBOUNCE_DELAY 50

int buttonPins[4] = {BTN_B1, BTN_B2, BTN_B3, BTN_B4};
bool buttonState[4] = {false, false, false, false};
bool lastButtonState[4] = {false, false, false, false};
unsigned long lastDebounceTime[4] = {0, 0, 0, 0};

void readInputs() {
  for (int i = 0; i < 4; i++) {
    bool reading = (digitalRead(buttonPins[i]) == LOW);
    if (reading != lastButtonState[i]) {
      lastDebounceTime[i] = millis();
      lastButtonState[i] = reading;
    }
    if ((millis() - lastDebounceTime[i]) > DEBOUNCE_DELAY) {
      buttonState[i] = reading;
    }
  }
}

int getButtonPressed() {
  static bool prevPressed[4] = {false, false, false, false};
  for (int i = 0; i < 4; i++) {
    if (buttonState[i] && !prevPressed[i]) {
      prevPressed[i] = true;
      return i + 1;
    } else if (!buttonState[i]) {
      prevPressed[i] = false;
    }
  }
  return 0;
}

bool buttonPressed(int pin) {
  return digitalRead(pin) == LOW;
}

int readDifficulty() {
  int potvalue = analogRead(POT_PIN);
  return map(potvalue, 0, 660, 1, 3);
}
