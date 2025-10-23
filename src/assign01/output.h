#ifndef OUTPUT_H
#define OUTPUT_H

#include "config.h"
#include <avr/sleep.h>
#include <avr/interrupt.h>
/*initialize leds and buttons*/
void initHardware();
/*initialize LCD*/
void lcdInit();
void showWelcomeMessage();
void pulseLedS();
void enterDeepSleep();
void showGoodMessage();
void showSequenceOnLCD();

#endif