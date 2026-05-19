


```cpp

#include <Servo.h>         // Includes servo Library
Servo myServo; 

void setup()
{

  myServo.attach(11);  

}

void loop()
{
   for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    delay(15);
}
}

```
