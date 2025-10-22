#include "output.h"

LiquidCrystal_I2C lcd(0x27,20,4); 

int brightness = 0;
int fadeAmount = 5;
unsigned long lastPulseTime = 0;

void initHardware() {
  //Initialize led pins
  pinMode(LED_L1, OUTPUT);
  pinMode(LED_L2, OUTPUT);
  pinMode(LED_L3, OUTPUT);
  pinMode(LED_L4, OUTPUT);
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

void turnOffAllLeds() {
  digitalWrite(LED_L1, LOW);
  digitalWrite(LED_L2, LOW);
  digitalWrite(LED_L3, LOW);
  digitalWrite(LED_L4, LOW);
}

void setLed(int id, bool on) {
  int pin = LED_L1 + (id - 1);
  digitalWrite(pin, on? HIGH : LOW);
}

void pulseLedS() {
  if (millis() - lastPulseTime > LS_PULSE_DELAY) {
    analogWrite(LED_PIN, currIntensity);   
    currIntensity = currIntensity + fadeAmount;
    if (currIntensity == 0 || currIntensity == 255) {
      fadeAmount = -fadeAmount ; 
    }    
  }

}

void enterDeepSleep() {

}