#ifndef OUTPUT_H
#define OUTPUT_H

#include "config.h"
#include "input.h"

/*Initializes the hardware components (buttons and pot) by setting the mode pin*/
void initHardware();

/*Initializes the lcd*/
void lcdInit();

/*Show the "Welcome to TOS - Press B1 to start" message on the lcd*/
void showWelcomeMessage();

/*Make the red led pulsing during the IDLE state*/
void pulseLedS();

/*Show the "GOOD! Score ..." message on the lcd*/
void showGoodMessage();

/*Show the sequence to turn on on the lcd*/
void showSequenceOnLCD();

/*Show the level on the potentiometer during the initial state
(with the welcome message)*/
void showLevel();

#endif