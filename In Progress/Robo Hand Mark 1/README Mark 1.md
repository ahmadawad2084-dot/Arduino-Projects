# RoboArm — Mark 1.0
 
An EMG-controlled robotic hand prototype and proof of concept. A MyoWare 2.0 muscle sensor reads forearm muscle activity, and an Arduino translates that signal into servo motion, curling three fingers of a 3D-printable/CAD hand.
 
**Status:** ✅ Mark 1.0 working proof of concept — full signal chain validated (sensor → Arduino → servos + LEDs) on breadboard.
 
---
 
## MyoWare Sensor

I had to solder wires to the GND, VIN, ENV ports in the sensor.
 
![image alt](https://github.com/ahmadawad2084-dot/Arduino-Projects/blob/60268b83777da6c21611be512d4a83f258237377/In%20Progress/Robo%20Hand%20Mark%201/MyoWare%20Sensor.jpeg)
 
---
 
## Overview
 
Mark 1.0 is a breadboard proof-of-concept: 3 fingers (thumb, index, middle), each driven by its own servo, all moving together in response to a single EMG signal from the forearm. Mark 2.0 is planned as a cleaner, more capable follow-up build.
 
A single MyoWare sensor can't meaningfully isolate individual finger movement — surface EMG on the forearm picks up overlapping flexor muscle groups. Mark 1.0 deliberately drives all three servos with the same mapped angle rather than attempting (unreliable) per-finger isolation from one sensor.
 
---
 
## Components
 
| Component | Notes |
|---|---|
| Elegoo Uno R3 | Arduino-compatible microcontroller |
| MyoWare 2.0 Muscle Sensor | EMG signal acquisition |
| Electrode pads (x3) | MID / END / REF, 3.5mm snap connectors |
| MS18 Servo Motors (x3) | Thumb, index, middle finger |
| 4×AA battery pack (6V) | Dedicated servo power, separate from Arduino |
| LEDs (x3) + 330Ω resistors | Status indicators: Signal Detected, Servo Moving, Power On |
| 2 Breadboards + jumper wires | Sensor wires put on second breadboard for ease of access and movement |
 
---
 
## Wiring
 
### Power rails
 
| Rail | Source | Connects to |
|---|---|---|
| GND | Arduino GND | Battery (–), all servo grounds, MyoWare GND, LED cathodes |
| 6V | Battery (+) | Servo V+ lines only; 100µF cap in parallel across this + GND at battery entry point |
| 3.3V | Arduino onboard 3.3V pin | MyoWare VIN only |
| LEDs | Arduino digital pins directly | Not a shared rail — each LED + resistor wired straight to its own control pin |
 
**Common ground is critical:** Arduino GND, battery negative, all three servo grounds, MyoWare GND, and LED cathodes all tie back to one shared ground. Without a common reference, the Arduino's analog read of the MyoWare signal is meaningless.
 
### Pin assignments
 
| Function | Pin | Mode |
|---|---|---|
| MyoWare ENV | A0 | Analog input |
| MyoWare VIN | 3.3V | Power |
| MyoWare GND | GND | Power |
| Servo — Thumb | D11 | Digital output (PWM) |
| Servo — Index | D10 | Digital output (PWM) |
| Servo — Middle | D9 | Digital output (PWM) |
| LED — Signal Detected | D4 | Digital output |
| LED — Servo Moving | D5 | Digital output |
| LED — Power On | D6 | Digital output |
 
---
 
## Electrode placement
 
Target muscle: forearm flexors (controls finger/wrist flexion).
 
- **MID** electrode: middle of the muscle body
- **END** electrode: 1–3 cm from MID, in line with the muscle's length
- **REF** (reference/ground) electrode: over a bony, electrically quiet landmark (wrist or elbow area)
Clean the skin with an alcohol wipe before placing pads. Snap electrodes to the sensor *before* sticking them to skin, not after (avoids bruising from snap pressure).
 
**Working placement (Mark 1.0):** all three electrodes on the forearm, positioned closer to the elbow. Confirmed working — full range of servo motion achieved from a relaxed-to-flexed range at this placement.
 
---
 
## Code
 
Full sketch: [`RoboArm_M1.ino`](./RoboArm_M1.ino)
 
**Signal flow:**
1. `analogRead(A0)` reads the raw MyoWare ENV signal (0–1023)
2. `constrain()` clamps it to a calibrated baseline–max window
3. `map()` rescales that value onto a safe servo angle range
4. All three servos receive the same mapped angle via `.write()`
5. LED logic runs independently off the same readings — Signal Detected (threshold check), Servo Moving (change-detection with a small deadband), Power On (set once in `setup()`)
**Calibration values used (Mark 1.0, current placement):**
```cpp
EMG_BASELINE     = 0
EMG_MAX          = 900    // tune via Serial Monitor for your own arm/placement
SIGNAL_THRESHOLD = 100
SERVO_MIN_ANGLE  = 30
SERVO_MAX_ANGLE  = 150
```
These are specific to individual arm/electrode placement — recalibrate via Serial Monitor (9600 baud) any time the sensor is repositioned.
 
---
 
## Known limitations
 
- All three fingers move together at the same angle — one EMG channel can't isolate individual finger control on the forearm's overlapping flexor muscles.
- Calibration (`EMG_MAX`, threshold) is placement- and person-specific; needs re-tuning if the sensor moves or a different person wears it.
- Breadboard build only — not yet mounted to the CAD hand.
---
 
## Next steps
 
- Mount electronics to the CAD hand model
- Refine CAD model in Onshape (Extrude, Revolve, Sweep, Loft, Thicken)
- Build a custom PCB to allow for a cleaner presentation 
- Mark 2.0: cleaner build, possibly multi-channel EMG for more independent finger control
  
---
 
## Tools used and to be used
 
- **CAD:** Onshape (primary), FreeCAD (offline backup)
- **Firmware:** Arduino IDE, `Servo.h`
- **Prototyping:** Breadboard, jumper wires, Tinkercad Circuits (wiring diagrams)
- **Soldering:** KEPIOG 80W digital iron, Electrisol SN60/PB40 leaded solder, Spurtar silicone mat
