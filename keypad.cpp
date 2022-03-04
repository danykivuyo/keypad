#include "Arduino.h"
#include "keypad.h"

Keypad::Keypad(int A , int B , int C , int D , int C1 , int C2 , int C3)
{
    Keypad::pinA = A;
    Keypad::pinB = B;
    Keypad::pinC = C;
    Keypad::pinD = D;
    Keypad::pinC1 = C1;
    Keypad::pinC2 = C2;
    Keypad::pinC3 = C3;
}

int Keypad::checkCol(){
    /*
        ################################
        #         The concept          #
        #                              #
        #  put all cols to input mode  #
        #  put all rows to high        #
        #  listen which col is high    #
        # return the col which is high #
        #                              #
        ################################
    */
    
    pinMode(pinA , OUTPUT);
    pinMode(pinB , OUTPUT);
    pinMode(pinC , OUTPUT);
    pinMode(pinD , OUTPUT);

    digitalWrite(pinA , HIGH);
    digitalWrite(pinB , HIGH);
    digitalWrite(pinC , HIGH);
    digitalWrite(pinD , HIGH);

    pinMode(pinC1 , INPUT);
    pinMode(pinC2 , INPUT);
    pinMode(pinC3 , INPUT);

    if(digitalRead(pinC1) == 1){
        Keypad::col = 0;
        digitalWrite(pinA , LOW);
        digitalWrite(pinB , LOW);
        digitalWrite(pinC , LOW);
        digitalWrite(pinD , LOW);
        return 0;
    }
    if(digitalRead(pinC2) == 1){
        Keypad::col = 1;
        digitalWrite(pinA , LOW);
        digitalWrite(pinB , LOW);
        digitalWrite(pinC , LOW);
        digitalWrite(pinD , LOW);
        return 1;
    }
    if(digitalRead(pinC3) == 1){
        Keypad::col = 2;
        digitalWrite(pinA , LOW);
        digitalWrite(pinB , LOW);
        digitalWrite(pinC , LOW);
        digitalWrite(pinD , LOW);
        return 2;
    }
}

int Keypad::checkRow(){
    /*
        # ###############################################
        #                 The concept                   #
        #                                               #
        #         put all cols to input mode            #
        #       put all rows to high one by one         #
        #         listen when any col is high           #
        # return the row which caused any col to behigh #
        #                                               #
        #################################################
    */
    
    pinMode(pinA , OUTPUT);
    pinMode(pinB , OUTPUT);
    pinMode(pinC , OUTPUT);
    pinMode(pinD , OUTPUT);

    digitalWrite(pinA , LOW);
    digitalWrite(pinB , LOW);
    digitalWrite(pinC , LOW);
    digitalWrite(pinD , LOW);

    pinMode(pinC1 , INPUT);
    pinMode(pinC2 , INPUT);
    pinMode(pinC3 , INPUT);

    digitalWrite(pinA , HIGH);
    if(digitalRead(pinC1) == 1 || digitalRead(pinC2) == 1 || digitalRead(pinC3) == 1){
        Keypad::row = 0;
        digitalWrite(pinA , LOW);
        return 0;
    }
    

    digitalWrite(pinB , HIGH);
    if(digitalRead(pinC1) == 1 || digitalRead(pinC2) == 1 || digitalRead(pinC3) == 1){
        Keypad::row = 1;
        digitalWrite(pinB , LOW);
        return 1;
    }
    

    digitalWrite(pinC , HIGH);
    if(digitalRead(pinC1) == 1 || digitalRead(pinC2) == 1 || digitalRead(pinC3) == 1){
        Keypad::row = 2;
        digitalWrite(pinC , LOW);
        return 2;
    }
    

    digitalWrite(pinD , HIGH);
    if(digitalRead(pinC1) == 1 || digitalRead(pinC2) == 1 || digitalRead(pinC3) == 1){
        Keypad::row = 3;
        digitalWrite(pinD , LOW);
        return 3;
    }
    

}

bool Keypad::keyPressed(){
    pinMode(pinA , OUTPUT);
    pinMode(pinB , OUTPUT);
    pinMode(pinC , OUTPUT);
    pinMode(pinD , OUTPUT);

    digitalWrite(pinA , HIGH);
    digitalWrite(pinB , HIGH);
    digitalWrite(pinC , HIGH);
    digitalWrite(pinD , HIGH);

    pinMode(pinC1 , INPUT);
    pinMode(pinC2 , INPUT);
    pinMode(pinC3 , INPUT);

    if(digitalRead(pinC1) == 1 || digitalRead(pinC2) == 1 || digitalRead(pinC3) == 1){
        digitalWrite(pinA , LOW);
        digitalWrite(pinB , LOW);
        digitalWrite(pinC , LOW);
        digitalWrite(pinD , LOW);
        return true;
    }

    digitalWrite(pinA , LOW);
    digitalWrite(pinB , LOW);
    digitalWrite(pinC , LOW);
    digitalWrite(pinD , LOW);
    return false;
}

char Keypad::listen(){
    Keypad::col = checkCol();
    Keypad::row = checkRow();
    Keypad::key = keys[row][col];
    return Keypad::key;
}
