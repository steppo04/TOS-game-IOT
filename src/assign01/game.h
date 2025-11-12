#ifndef GAME_H
#define GAME_H

#include "config.h"
#include "output.h"
#include "input.h"

/*Enum that describe the state of the game*/
enum GameState {
  STATE_IDLE,
  STATE_START,
  STATE_PLAYING,
  STATE_ROUND_OK,
  STATE_GAME_OVER
};

/*Initializes all the variables of the game to their initial state
and shows the "Go!" message*/
void startGame();

/*Set the factor F based on the value from the potentiometer*/
double setTimeLimitDifficulty();

/*Generates the random sequence*/
void generateSequence();

/*The main method that run whenever the round is playing
-it generates the sequence calling generateSequence() and shows it on the lcd
-during a timeLimit based on the setTimeLimitDifficulty() called in the startGame():
  -check if the correct buttons are pressed
  -decide if you win or not
-*/
bool playRound();

/*When you lose, this method is called:
-it turns on the led for 2 secs
-and it waits 10 secs before going back to the IDLE (Initial) state*/
void handleGameOver();


#endif
