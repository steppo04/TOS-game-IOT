#include "output.h"

LiquidCrystal_I2C lcd(0x27,20,4); 

int currIntensity = 0;
int fadeAmount = 5;
unsigned long lastPulseTime = 0;

void initHardware() {
  //Initialize led pin
  pinMode(LED_LS, OUTPUT);

  //Initialize button pins
  pinMode(BTN_B1, INPUT);
  pinMode(BTN_B2, INPUT);
  pinMode(BTN_B3, INPUT);
  pinMode(BTN_B4, INPUT);
}

void lcdInit() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,1);
}

void showWelcomeMessage() {
  lcd.clear();
  lcd.print("Welcome to TOS!!");
  lcd.setCursor(0,1);
  lcd.print("Press B1 to start...");
}

void pulseLedS() {
  if (millis() - lastPulseTime > LS_PULSE_DELAY) {
    analogWrite(LED_LS, currIntensity);  
    lastPulseTime = millis(); 
    currIntensity = currIntensity + fadeAmount;
    if (currIntensity == 0 || currIntensity == 255) {
      fadeAmount = -fadeAmount ; 
    }    
  }
}

void showGoodMessage() {
  lcd.clear();
  lcd.print("GOOD! Score: ");
  lcd.print(score);
  int startTime=millis(); 
  while(millis() - startTime < 4000) { /*wait*/ }
}

void showSequenceOnLCD() {
  lcd.clear();
  for (int i = 0; i < 4; i++) {
    lcd.print(sequence[i]);
  }
}

void showLevel() {
  lcd.setCursor(0,3);
  lcd.print("Level -> ");
  lcd.print(readDifficulty());
}