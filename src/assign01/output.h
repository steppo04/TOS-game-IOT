#ifndef OUTPUT_H
#define OUTPUT_H

#include "config.h"
/*initialize leds and buttons*/
void initHardware();
/*initialize LCD*/
void lcdInit();
void showWelcomeMessage();
void turnOffAllLeds();
void setLed(int id, bool on);
void pulseLedS();
void enterDeepSleep();

#endif