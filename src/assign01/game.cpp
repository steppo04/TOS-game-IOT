#include "game.h"
#include "output.h"
#include "input.h"

int sequence[4];
int playerIndex;
double F;
int score;
unsigned long timeLimit;
unsigned long roundStartTime;
bool gameOverFlag;

void startGame() {
  playerIndex = 0;
  score = 0;
  gameOverFlag = false;
  F = setTimeLimitDifficulty();
  timeLimit = BASE_T1 * F;
  setTimeLimitDifficulty();
  lcd.clear();
  lcd.print("Go!");
  int startTime=millis(); 
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
    showSequenceOnLCD(); //4231

    playerIndex= 0;
    roundStartTime=millis(); 
    
    while(millis() - roundStartTime < timeLimit) {
      readInputs();
      int pressed = getButtonPressed();
      if (pressed > 0) {
        //Serial.println("btn pressed " + (String)pressed);
        //Serial.println("btn computed " + (String)sequence[playerIndex]); 
        //Serial.println("xxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        if (pressed == sequence[playerIndex]) {
            playerIndex++;
            if (playerIndex == 4) {
                score++;
                timeLimit*=F;
                return true;            
            }
        } else {
            gameOverFlag=true;
            return false;    
        }    
      }
    }

    gameOverFlag=true;
    return false;
}

bool isGameOver() {
  return gameOverFlag;
}

void handleGameOver() {
  digitalWrite(LED_LS, HIGH);
  lcd.clear();
  lcd.print("Game Over");
  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.print(score);
  int gaOvTime=millis();
  while(millis() - gaOvTime < 10000) {
    if (millis() - gaOvTime == 2000) {
        digitalWrite(LED_LS, LOW);
    }
  }
}
