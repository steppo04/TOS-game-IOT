#include "config.h"
#include "input.h"
#include "output.h"
#include "game.h"


GameState currentState = STATE_IDLE;
unsigned long lastActionTime = 0;

void setup() {
  initHardware();
  lcdInit();
  showWelcomeMessage();
}


void loop() {
  readInputs();

  switch (currentState) {
    case STATE_IDLE:
      pulseLedS();
      if (buttonPressed(BTN_B1)) {
        currentState = STATE_START;
        lastActionTime = millis();
      } else if (millis() - lastActionTime > 10000) {
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
      } else if (isGameOver()) {
        currentState = STATE_GAME_OVER;
      }
      break;

    case STATE_ROUND_OK:
      showGoodMessage();
      delay(1000);
      currentState = STATE_PLAYING;
      break;

    case STATE_GAME_OVER:
      handleGameOver();
      delay(10000);
      currentState = STATE_IDLE;
      break;
  }
}

