# 4-bit LCD1602 (No I2C)

## What is it?
A 16 character by 2 row character display. Looks like the screen of general calculators.  
This specific LCD is a 16 x 2 (1602).

Can be wired to Arduino Uno to display characters like a calculator would.  
D4–D7 used for 4-bit mode — only 4 pins needed, frees up 4 Arduino pins, compatible with the `LiquidCrystal` library.

---

## How to Wire

```
LCD Pin  → Arduino Pin                                          | What does it do?
------------------------------------------------------------------------------------------------------------------------------------
LCD VSS  → GND                                                  | Ground
LCD VDD  → 5V                                                   | Power Source
LCD V0   → Middle pin of potentiometer                          | Controls Contrast (Resistor 1 → GND, Resistor 2 → 5V)
LCD RS   → Arduino pin 12                                       | Register Select — tells LCD if sending command or data
LCD RW   → GND                                                  | Read/Write, tied to ground
LCD E    → Arduino pin 11                                       | Triggers LCD to read data
LCD D4   → Arduino pin 5                                        | Actual Character Data
LCD D5   → Arduino pin 4                                        | Actual Character Data
LCD D6   → Arduino pin 3                                        | Actual Character Data
LCD D7   → Arduino pin 2                                        | Actual Character Data
LCD A    → 5V                                                   | Power source for backlight
LCD K    → GND                                                  | Ground for backlight
```

### ⚠️ Wiring Warnings
1. VDD → 5V, VSS → GND — swapping these will likely damage the LCD.
2. A → 5V, K → GND — mixing these will burn out the backlight.
3. RW must go to GND or the LCD behaves erratically.

---

## Setup — LiquidCrystal Object

Must be declared **above** `void setup()`:

```cpp
//               (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11,  5,  4,  3,  2);
```

---

## General Coding Commands

```cpp
// In void setup():
lcd.begin(16, 2);         // Start the LCD (like Serial.begin())

// In void loop():
lcd.clear();              // Clear the screen (slow — 2ms, causes flicker)
lcd.setCursor(col, row);  // Move cursor — 0-indexed
lcd.print("text");        // Print a string
lcd.print(variable);      // Print a number or variable
lcd.scrollDisplayLeft();  // Scroll text left
lcd.blink();              // Blinking cursor
lcd.noBlink();            // Stop blinking cursor
```

> **Tip:** Prefer `lcd.setCursor()` over `lcd.clear()` when updating values.  
> `lcd.clear()` takes 2ms and causes flickering. `setCursor` just moves the cursor and overwrites in place.

---

## setCursor Visual Reference

`lcd.setCursor(col, row)` works like (x, y) coordinates.  
Whatever is printed after will appear at that position.

```
                              -------16-------
lcd.setCursor(0,0)  →  row 1 [A               ]
                       row 2 [                ]

lcd.setCursor(5,0)  →  row 1 [     A          ]
                       row 2 [                ]

lcd.setCursor(15,1) →  row 1 [                ]
                       row 2 [               A]
```

---

## Simple Project Ideas
1. Build a voltage reader circuit and display the reading on the LCD.
