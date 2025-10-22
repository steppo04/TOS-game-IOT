#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/* === Pin definitions === */
#define LED_L1 2
#define LED_L2 3
#define LED_L3 4
#define LED_L4 5
#define LED_LS 6

#define BTN_B1 7
#define BTN_B2 8
#define BTN_B3 9
#define BTN_B4 10

#define POT_PIN A0

/* === Game parameters === */
#define BASE_T1 5000   // ms - initial time limit
#define LS_PULSE_DELAY 20
#define LS_PULSE_STEP 5

/* === LCD configuration === */
extern LiquidCrystal_I2C lcd;

#endif
