# key_pad
this is an arduino library made for making simple for you to interact with the keypad module. To use it is very simple as its role is to siimplify everything.




# how to use

*1. include library

```#include "keypad.h"```

*2. instatiate

define pins used starting with rows followed by columns

```int A = 2 , B = 3 , C = 4 , D  = 5 , C1 = 6 , C2 = 7 , C3 = 8; //every pin to the connected digital pin```

```Keypad keypad(A , B , C , D , C1 , C2 , C3);```

*3 check if key is pressed then do some shit

```keypad.keyPressed() //returns true when any key is pressed```

*4 check exactly which key was pressed

```keypad.listen(); //returns a pressed charracter```
