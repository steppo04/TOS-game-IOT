#ifndef INPUT_H
#define INPUT_H

#include "config.h"

/*Read inputs from the board, and it manages
the button's debounce.*/
void readInputs();

/*Return the pressed button, managing also the button's debounce*/
int getButtonPressed();

/*Check if the button connected to "pin" is pressed or not*/
bool buttonPressed(int pin);

/*It reads the value from the potentiometer and convers it
in a value mapped from 1 to 4 (levels)*/
int readDifficulty();

#endif