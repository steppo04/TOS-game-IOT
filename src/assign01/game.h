#ifndef GAME_H
#define GAME_H

#include "config.h"
#include "output.h"
#include "input.h"

enum GameState {
  STATE_IDLE,
  STATE_START,
  STATE_PLAYING,
  STATE_ROUND_OK,
  STATE_GAME_OVER
};

void startGame();
double setTimeLimitDifficulty();
bool playRound();
void handleGameOver();
void generateSequence();


#endif
