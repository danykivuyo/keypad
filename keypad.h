#ifndef KEYPAD
#define KEYPAD

#include "Arduino.h"

class Keypad
{
private:
    char rows[4] , cols[3];
    int pinA , pinB , pinC , pinD , pinC1 , pinC2 , pinC3;
    int col , row;
    char keys[4][3] = {
        {'1' , '2' , '3'},
        {'4' , '5' , '6'},
        {'7' , '8' , '9'},
        {'*' , '0' , '#'},
    };
    char key;
public:
    Keypad(int A , int B , int C , int D , int C1 , int C2 , int C3);
    int checkRow();
    int checkCol();
    char listen();
    bool keyPressed();
};


#endif