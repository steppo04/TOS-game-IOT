#ifndef OUTPUT_H
#define OUTPUT_H

#include "config.h"
#include "input.h"

void initHardware();
void lcdInit();
void showWelcomeMessage();
void pulseLedS();
void showGoodMessage();
void showSequenceOnLCD();
void showLevel();

#endif