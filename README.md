# key_pad
this is an Arduino library made to make it simple for you to interact with the keypad module. To use it is very simple as its role is to simplify everything.

NOTE
>> Every column should remain connected to the ground with pull-down 10kΩ resistors.

# how to install

**1. open command prompt**

Open Run
```win+r```

write
```cmd```

click enter

**2. navigate to Arduino/libraries folder**

**3. Download the library**

```bash
git clone https://github.com/danykivuyo/keypad.git
```

**4. Restart Arduino IDE**

# how to use

**1. include library**

```#include "keypad.h"```

**2. instantiate**

define pins used starting with rows followed by columns

```int A = 2 , B = 3 , C = 4 , D  = 5 , C1 = 6 , C2 = 7 , C3 = 8; //every pin to the connected digital pin```

```Keypad keypad(A , B , C , D , C1 , C2 , C3);```

**3 Check if the key is pressed then do some shit**

```keypad.keyPressed() //returns true when any key is pressed```

**4 check exactly which key was pressed**

```keypad.listen(); //returns a pressed charracter```
