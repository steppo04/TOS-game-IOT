#include "game.h"
#include "output.h"
#include "input.h"

int playerIndex;
int F;
int score;
unsigned long timeLimit;
unsigned long roundStartTime;
bool gameOverFlag;

void startGame() {
  playerIndex = 0;
  score = 0;
  gameOverFlag = false;
  timeLimit = BASE_T1;
  setTimeLimitDifficulty();
  lcd.clear();
  lcd.show("Go!");
  delay(1000);
}

void setTimeLimitDifficulty() {
  switch(readDifficulty()) {
    case 1:
      F = 0.9;
      break;
    case 2:
      F = 0.7;
      break;
    case 3:
      F = 0.5;
      break;
    case 4:
      F = 0.3;
      break;
      
  }
}

void generateSequence() {
  int used[5] = {0};
  for (int i = 0; i < 4; i++) {
    int num;
    do {
      num = random(1, 5);
    } while(used[num]);
    used[num] = 1;
    sequence[i] = num;
  }

}

bool playRound() {

}

bool isGameOver() {

}

void handleGameOver() {

}
