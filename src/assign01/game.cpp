#include "game.h"

int sequence[4];
int playerIndex;
double F;
int score;
unsigned long timeLimit;
unsigned long roundStartTime;
unsigned long gaOvTime;
unsigned long startTime;

void startGame() {
  playerIndex = 0;
  score = 0;
  F = setTimeLimitDifficulty();
  timeLimit = BASE_T1 * F;
  setTimeLimitDifficulty();
  lcd.clear();
  lcd.print("Go!");
  startTime=millis(); 
  while(millis() - startTime < 2000) { /*wait*/ }
}

double setTimeLimitDifficulty() {
  switch(readDifficulty()) {
    case 1: return 1.0;
    case 2: return 0.9;
    case 3: return 0.8;
    case 4: return 0.7;
    default: return 1.0;
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
    generateSequence();
    showSequenceOnLCD();

    playerIndex= 0;
    roundStartTime=millis(); 
    
    while(millis() - roundStartTime < timeLimit) {
      readInputs();
      int pressed = getButtonPressed();
      if (pressed > 0) {
        if (pressed == sequence[playerIndex]) {
            playerIndex++;
            if (playerIndex == 4) {
                score++;
                timeLimit*=F;
                return true;            
            }
        } else {
            return false;    
        }    
      }
    }
    return false;
}


void handleGameOver() {
  digitalWrite(LED_LS, HIGH);
  lcd.clear();
  lcd.print("Game Over");
  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.print(score);
  gaOvTime=millis();
  while(millis() - gaOvTime < 10000) {
    if (millis() - gaOvTime == 2000) {
        digitalWrite(LED_LS, LOW);
    }
  }
}
