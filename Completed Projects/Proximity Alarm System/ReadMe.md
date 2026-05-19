# Ultrasonic Proximity Warning System
### Arduino UNO R3 — Project Documentation

---

## General Overview

This project combines an ultrasonic sensor, active buzzer, three LEDs, and an LCD1602 display to create a compact proximity warning system. The system continuously measures the distance between the sensor and any object in front of it, displaying the result on both the LCD screen and the Serial Monitor. Depending on how close the object is, the system responds with visual (LED color) and auditory (buzzer) warnings.

This type of system has real-world applications in reverse parking sensors in cars, camera autofocus systems, and industrial object detection.

---

## Components

| # | Component | Quantity |
|---|-----------|----------|
| 1 | Arduino UNO R3 | 1 |
| 2 | LCD1602 Display | 1 |
| 3 | HC-SR04 Ultrasonic Sensor | 1 |
| 4 | 10kΩ Potentiometer (LCD contrast) | 1 |
| 5 | LEDs (Red, Yellow, Green) | 3 |
| 6 | 220Ω Resistors (one per LED) | 3 |
| 7 | Active Buzzer | 1 |
| 8 | Breadboard | 1 |
| 9 | Jumper Wires | Several |

---

## Wiring

### Power Rails
| Arduino | Breadboard |
|---------|------------|
| 5V | Positive (+) rail |
| GND | Negative (−) rail |

### LEDs
> Each LED has a 220Ω resistor on its positive leg to limit current.

| Arduino Pin | Component |
|-------------|-----------|
| Pin 13 | Green LED (positive leg via 220Ω resistor) |
| Pin 12 | Yellow LED (positive leg via 220Ω resistor) |
| Pin 11 | Red LED (positive leg via 220Ω resistor) |
| GND rail | All LED negative legs |

### Ultrasonic Sensor (HC-SR04)
| Arduino / Rail | HC-SR04 Pin |
|----------------|-------------|
| 5V rail | VCC |
| GND rail | GND |
| Pin 10 | Echo |
| Pin 9 | Trig |

### Active Buzzer
| Arduino / Rail | Buzzer Pin |
|----------------|------------|
| Pin 8 | Positive (+) |
| GND rail | Negative (−) |

### LCD1602
| Arduino / Rail | LCD Pin |
|----------------|---------|
| 5V rail | VCC (Pin 2) |
| GND rail | GND (Pin 1) |
| Potentiometer wiper | V0 — Contrast (Pin 3) |
| Pin 7 | RS (Pin 4) |
| GND rail | RW (Pin 5) — tied to GND for write mode |
| Pin 6 | E — Enable (Pin 6) |
| Pin 5 | D4 (Pin 11) |
| Pin 4 | D5 (Pin 12) |
| Pin 3 | D6 (Pin 13) |
| Pin 2 | D7 (Pin 14) |
| 5V via 220Ω resistor | Backlight Anode — A (Pin 15) |
| GND rail | Backlight Cathode — K (Pin 16) |

### Potentiometer (LCD Contrast)
| Connection | Potentiometer Leg |
|------------|-------------------|
| 5V rail | Left outer leg |
| GND rail | Right outer leg |
| LCD V0 (Pin 3) | Middle wiper leg |

---

## Warning System Logic

| Zone | Distance | LED | Buzzer |
|------|----------|-----|--------|
| 🟢 Safe | Greater than 30 cm | Green ON | OFF |
| 🟡 Caution | 11 cm – 30 cm | Yellow ON | Periodic beeping |
| 🔴 Danger | Less than or equal to 10 cm | Red ON | Constant beeping |

The distance is also printed in real time to both the **Serial Monitor** and the **LCD display**.

---

## Libraries Used

| Library | Purpose |
|---------|---------|
| `LiquidCrystal.h` | Controls the LCD1602 display. Built into Arduino IDE — no installation required. |

> The HC-SR04 ultrasonic sensor does not require a library. It operates using built-in Arduino functions (`digitalWrite`, `pulseIn`, `delayMicroseconds`).

---

## Problems Encountered

1. *(To be filled in)*
2. *(To be filled in)*
3. *(To be filled in)*
4. *(To be filled in)*

---

*Documentation by Ahmad Awad*
