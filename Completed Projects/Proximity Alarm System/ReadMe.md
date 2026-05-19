**General Objective:**

Basically, combining an active buzzer, red, yellow, green LEDs, an ultra sonic sensor (USS) and an LCD1602 to create a small and compact proximity sensor that beeps depending on the proximity and displays it on the LCD and serial monitor. This is used in cars, cameras and many sensors to give the user visual and auditory information on how close they are to any other object. This program outputs the distance (cm used in the code) in the serial monitor and LCD display.


Components:
1. Arduino UNO R3
2. LCD1602
3. UltraSonic Sensor
4. 10k Potentiometer
5. 3 LEDs
6. 3 Resistors
7. Active Buzzer
8. Breadboard
9. An unholy amount of wires :)





Wires and where they go:
|   GND (Arduino)  | Negative (-) rail on breadboard |
|------------------|---------------------------------|
|   5V (Arduino)   | Positive (+) rail on breadboard |
|------------------|---------------------------------|
| Pin 13 (Arduino) | Green LED Power                 |
|------------------|---------------------------------|
| Pin 12 (Arduino) | Yellow LED Power                |
|------------------|---------------------------------|
| Pin 11 (Arduino) | Red LED Power                   |
|------------------|---------------------------------|
| Pin 10 (Arduino) | Echo pin (USS)                  |
|------------------|---------------------------------|
| Pin 9 (Arduino)  | Trigger Pin (USS)               |
|------------------|---------------------------------|
| Pin 8 (Arduino)  | Positive (+) Active Buzzer      |
|------------------|---------------------------------|
| Pin 7(Arduino)   | RS pin (LCD)                    |
|------------------|---------------------------------|
| Pin 6 (Arduino)  | E pin (LCD)                     |
|------------------|---------------------------------|
| Pin 5 (Arduino)  | D4 pin (LCD)                    |
|------------------|---------------------------------|
| Pin 4 (Arduino)  | D3 pin (LCD)                    |
|------------------|---------------------------------|
| Pin 3 (Arduino)  | D2 pin (LCD)                    |   
|------------------|---------------------------------|
| Pin 2 (Arduino)  | D1 pin (LCD)                    |  
|------------------|---------------------------------|


Warning System Logic:
Green Light: Distance is greater than 30 cm, green LED on, active buzzer off
Yellow Light: Distance is greater than 11 cm and less than 30, yellow LED on, active buzzer on incrementally
Red Light: Distance is less than 11 cm, red LED on, active buzzer on constantly


Libraries Used:
LiquidCrystal.h Library used for the LCD to function

Problems Encountered:
1. efnrveivn
2. vejnerv
3. ekjnvkejrnve
4. jervnkjernv
