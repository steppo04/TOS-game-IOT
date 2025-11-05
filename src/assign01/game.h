#ifndef GAME_H
#define GAME_H

#include "config.h"

enum GameState {
  STATE_IDLE,
  STATE_START,
  STATE_PLAYING,
  STATE_ROUND_OK,
  STATE_GAME_OVER
};

/* === Game control functions === */
void startGame();
bool playRound();
bool isGameOver();
void handleGameOver();
void showGoodMessage();
void generateSequence();
void showSequenceOnLCD();

#endif
