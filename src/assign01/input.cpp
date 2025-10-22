#include "input.h"

bool buttons[4]={false,false,false,false};

void readInputs() {
    buttons[0] = digitalread(BTN_B1) == LOW;
    buttons[1] = digitalread(BTN_B2) == LOW;
    buttons[2] = digitalread(BTN_B3) == LOW;
    buttons[3] = digitalread(BTN_B4) == LOW;
}

bool buttonPressed(int pin){
    return digitalread(pin) == LOW;
}

int getButtonPressed(){
    for (int i=0 ;i < 4,i++){
        if (buttons[i]) return i+1;
    }
    return 0;
}

int readDifficulty(){
    int potvalue=analogread(POT_PIN);
    return map(potvalue,0,1023,1,4)
}