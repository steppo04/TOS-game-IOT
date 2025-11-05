#include "config.h"
#include "input.h"
#include "output.h"
#include "game.h"

#include <avr/interrupt.h>
#include <avr/sleep.h>

GameState currentState = STATE_IDLE;
unsigned long lastActionTime = 0;
int gaOvTime = 0;
int stRouTime = 0;

void setup() {
  initHardware();
  lcdInit();
  showWelcomeMessage();
  attachInterrupt(digitalPinToInterrupt(BTN_B1), wakeUp,  RISING);
}

void wakeUp() {}


void loop() {
  readInputs();
  switch (currentState) {
    case STATE_IDLE:
      pulseLedS();
      showLevel();
      if (buttonPressed(BTN_B1)) {
        currentState = STATE_START;
        lastActionTime = millis();
      } /*else if (millis() - lastActionTime > 10000) {
        enterDeepSleep();
      }*/
      break;

    case STATE_START:
      startGame();
      currentState = STATE_PLAYING;
      break;

    case STATE_PLAYING:
      if (playRound()) {
        currentState = STATE_ROUND_OK;
      } else if (isGameOver()) {
        currentState = STATE_GAME_OVER;
      }
      break;

    case STATE_ROUND_OK:
      showGoodMessage();
      stRouTime = millis();
      while(millis() - stRouTime < 1000) { /*wait*/ }
      currentState = STATE_PLAYING;
      break;

    case STATE_GAME_OVER:
      handleGameOver();
      gaOvTime=millis(); 
      while(millis() - gaOvTime < 10000) { /*wait*/ }
      currentState = STATE_IDLE;
      lcd.clear();
      showWelcomeMessage();
      break;
  }
}

void enterDeepSleep() {
  analogWrite(LED_LS, 0);
  lcd.clear();
  lcd.noBacklight();
  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);

  sleep_enable();
  sleep_mode();
  sleep_disable();


  lcd.backlight();
  lcd.clear();
  showWelcomeMessage();
}

