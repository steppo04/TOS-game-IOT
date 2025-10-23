#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/* Pin definitions */
#define LED_LS 6

#define BTN_B1 8
#define BTN_B2 9
#define BTN_B3 10
#define BTN_B4 11

#define POT_PIN A0

/* Game parameters */
#define BASE_T1 5000
#define LS_PULSE_DELAY 20
#define LS_PULSE_STEP 5

/* Global vars config. */

/* LCD configuration */
extern LiquidCrystal_I2C lcd;
/* Init. var score */
extern int score;
/* Init. sequence to show*/
extern int sequence[4];

#endif
