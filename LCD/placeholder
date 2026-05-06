4 bit LCD1602 (No I2C)

What is it ---> This element is a 16 character by 2 row character display. Looks like the screen of general calculators.

This specific LCD is a 16 x 2 (1602)  
                       --   _  -- _

Note: Can be Wired to Arduino Uno to display characters like a calculator would.
Note: D4 until D7 used because im making it a 4 bit mode. meaning only 4 pins needed, frees up 4 arduino pins for other things, compatible with "LiquidCrystal" library thats used to run LCD in 4 bit mode


How to wire:      LCD|Pin|   Arduino Pin                                                                              | What does it do?
                  ----------------------------------------------------------------------------------------------------------------------------------
                  LCD VSS  → GND                                                                                      | Ground
                  LCD VDD  → 5V                                                                                       | Power Source
                  LCD V0   → Middle pin of potentiometer (for contrast)  ---> Resistor 1 into GND, Resistor 2 into 5V | Controls Contrast
                  LCD RS   → Arduino pin 12                                                                           | Register Select (RS) -> Tells LCD if you are sending command or data
                  LCD RW   → GND                                                                                      | Read/Write, tied to ground
                  LCD E    → Arduino pin 11                                                                           | Triggers LCD to read data
                  LCD D4   → Arduino pin 5                                                                            | Actual Character Data
                  LCD D5   → Arduino pin 4                                                                            | //      //      //
                  LCD D6   → Arduino pin 3                                                                            | //      //      //
                  LCD D7   → Arduino pin 2                                                                            | //      //      //
                  LCD A    → 5V (backlight)                                                                           | Power source for back light
                  LCD K    → GND (backlight)                                                                          | Ground for back light


Wiring Warning: 
1. LCD VDD goes to 5V, VSS goes to GND — swapping these two will likely damage the LCD.
2. A must go to 5V, K to GND. Mixing these will burn out the backlight.
3. If RW pin not to ground, LCD behaves irratically

General Coding Commands:
lcd.clear();              // Clear the screen
lcd.setCursor(col, row);  // Move cursor (0-indexed)
lcd.print("text");        // Print a string
lcd.print(variable);      // Print a number or variable
lcd.scrollDisplayLeft();  // Scroll text left
lcd.blink();              // Blinking cursor
lcd.noBlink();            // Stop blinking cursor

Note: lcd.setCursor(col,row); is a much better way to update the character instead of using the lcd.clear(); because the clear command takes two milliseconds and is slow. results in flickering.
Note: lcd.setCursor(col,row); is similar to (x,y) coordinates. whatever is printed with lcd.print(); after setting the cursor will print in the cursor's current location.

                                                                                 -------16------- 
      Example in the LCD1602, A is the position: lcd.setCursor(0,0) -->   row 1 [A               ]
                                                                          row 2 [                ]

                                                 lcd.setCursor(5,0) -->   row 1 [     A          ]
                                                                          row 2 [                ]


                                                lcd.setCursor(15,1) -->   row 1 [                ]
                                                                          row 2 [              A ]







Simple Project Ideas To Fully Understand It:
1. build a voltage reader circuit and let it print on the LCD
