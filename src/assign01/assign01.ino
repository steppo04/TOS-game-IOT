#include "config.h"
#include "input.h"
#include "output.h"
#include "game.h"

#include <avr/interrupt.h>
#include <avr/sleep.h>

GameState currentState;
unsigned long lastActionTime;
bool justWakeUp;

void setup() {
  currentState = STATE_IDLE;
  lastActionTime = 0;
  justWakeUp = false;
  initHardware();
  lcdInit();
  showWelcomeMessage();
}

void loop() {
  readInputs();

  switch (currentState) {
    case STATE_IDLE:
      pulseLedS();
      showLevel();

      if (buttonPressed(BTN_B1)) {
        if (justWakeUp) {
          justWakeUp = false;
          while(millis() - lastActionTime < 600) {}
        } else {
          currentState = STATE_START;
          analogWrite(LED_LS, 0); 
          lastActionTime = millis();
        }
      }
      else if (millis() - lastActionTime > 10000) {
        enterDeepSleep();
      }

      break;

    case STATE_START:
      startGame();
      currentState = STATE_PLAYING;
      break;

    case STATE_PLAYING:
      if (playRound()) {
        currentState = STATE_ROUND_OK;
      } else {
        currentState = STATE_GAME_OVER;
      }
      break;

    case STATE_ROUND_OK:
      showGoodMessage();
      currentState = STATE_PLAYING;
      break;

    case STATE_GAME_OVER:
      handleGameOver();
      currentState = STATE_IDLE;
      lcd.clear();
      showWelcomeMessage();
      lastActionTime = millis();
      break;
  }
}

/*empty functions, just for the waking up after the deep sleep*/
void wakeUp() {}

/*Put the system into deep sleep mode*/
void enterDeepSleep() {
  analogWrite(LED_LS, 0);
  lcd.clear();
  lcd.noBacklight();

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  attachInterrupt(digitalPinToInterrupt(BTN_B1), wakeUp, RISING);
  sleep_mode();

  sleep_disable();
  detachInterrupt(digitalPinToInterrupt(BTN_B1));
  justWakeUp = true;

  lcd.backlight();
  lcd.clear();
  showWelcomeMessage();

  lastActionTime = millis();
}
