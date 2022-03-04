#include <LiquidCrystal.h>
#include "String.h"
#include "keypad.h"

int A = 3 , B = 2 ,C = 14 , D = 0 , C1 = 4, C2 = 5, C3 = 6;
int rs = 13 , e = 12 , d4 = 11 , d5 = 10 , d6 = 9 , d7 = 8;

Keypad keypad(A , B , C , D , C1 , C2 , C3);
LiquidCrystal lcd(rs , e , d4 , d5 , d6 , d7);

char k;
String str;

void setup(){
  Serial.begin(9600);
  lcd.begin(16 , 2);
  }

void loop(){
  k = keypad.listen();
  if(keypad.keyPressed() == true){
    if(str.length() >= 16)
      str.remove(0,1);
    str[str.length()] = '\0';
    str += k;
    Serial.println(str);
    delay(200);
  }
  Serial.println(k);
  lcd.setCursor(0 , 0);
  lcd.print("daniel kivuyo");
  lcd.setCursor(0 , 1);
  lcd.print(str);
}
