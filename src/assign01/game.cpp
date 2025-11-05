#include "game.h"
#include "output.h"
#include "input.h"

int playerIndex;
int score;
unsigned long timeLimit;
unsigned long roundStartTime;
bool gameOverFlag;

void startGame() {
  playerIndex = 0;
  score = 0;
  gameOverFlag = false;
  setTimeLimitDifficulty();

}

void setTimeLimitDifficulty() {
  timeLimit = BASE_T1;
  switch(readDifficulty()) {
    case 1:
      break;
    case 2:
      timeLimit -= 1000;
      break;
    case 3:
      timeLimit -= 2000;
      break;
    case 4:
      timeLimit -= 3000;
  }
}


bool playRound() {

}

bool isGameOver() {

}

void handleGameOver() {

}

void generateSequence() {

}
