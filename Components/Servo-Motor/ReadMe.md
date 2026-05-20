# Servo Motor SG90

## What is it?
A servo motor is a rotary actuator that allows precise control of angular position. Unlike regular DC motors that spin continuously, a servo moves to a specific angle and holds it. It contains a DC motor, a gearbox, a position sensor (potentiometer), and control circuitry all in one package.

Compatible with the `Servo` library. Each Servo of this model has only three wires

---

## How to Wire

```
Servo Colour  → Arduino Pin                                 | What does it do?
------------------------------------------------------------------------------------------------------------------------------------
Servo Red                    → Power                        | 5V power Supply (Not in Arduino, Use External Power Source)
Servo Yellow, White, Orange  → Any PWM Pin (~)              | The pin that the arduino will control it by
Brown, Black                 → GND                          | GND in arduino

```

### ⚠️ General Warnings
1. Use an external power supply to not fry the arduino over time.
2. Make sure to include the library above void setup.

---

## Setup — Servo Object & Library

Both must be declared **above** `void setup()`:

```cpp
#include <Servo.h>

Servo myServo();
```

Note: I used myServo as the object, thats why all the commands are myServo.attach( ); or myServo.write( ); 
      All commands are the object name + the command (.attach    .write    .read)

## General Coding Commands

```cpp
// Global - Above void setup():
#include <Servo.h>         // Includes servo Library
Servo myServo;             // Declare servo object



// In void setup():
myServo.attach(pin);              // Tells the Arduino that the following pin is the PWM pin to control the servo
myServo.attach(pin, min, max)     // Custom pulse widths (µs)



// In void loop():
myServo.write(angle)                //Move to angle (0–180°)
myServo.writeMicroseconds(us)       //Move using raw pulse width (e.g. 1000–2000µs) for finer control
myServo.read()                      //Returns last written angle
myServo.detach()                    //Releases the pin (stops PWM signal)
```
