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
  delay(500);
}

void showSequenceOnLCD() {
  lcd.clear();
  for (int i = 0; i < 4; i++) {
    lcd.print(sequence[i]);
  }
}

void wakeUp() {}

void enterDeepSleep() {
  analogWrite(LED_LS, 0);
  lcd.clear();
  lcd.noBacklight();

  delay(100);

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);

  attachInterrupt(digitalPinToInterrupt(BTN_B1), wakeUp, LOW);

  sleep_enable();

  //noInterrupts();
  //interrupts();
  sleep_mode();

  sleep_disable();

  detachInterrupt(digitalPinToInterrupt(BTN_B1));

  lcd.backlight();
  lcd.clear();
  showWelcomeMessage();
}