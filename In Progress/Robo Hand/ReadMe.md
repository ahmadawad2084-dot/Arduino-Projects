# 🖐️ EMG-Controlled Robotic Hand — Mark 1.0

> A proof-of-concept robotic hand controlled by forearm muscle signals using a MyoWare 2.0 EMG sensor and Arduino Uno.

---

## 📌 Project Overview

The goal of this project is to build a prototype robotic hand that reads electromyography (EMG) signals from the user's forearm muscles and translates them into servo motor movements — simulating finger motion in real time.

Mark 1.0 is intentionally kept simple. It is a breadboard-based proof of concept focused on validating the core signal chain:

**Muscle → EMG Sensor → Arduino → Servo Motors**

---

## ⚙️ How It Work

1. The **MyoWare 2.0 Muscle Sensor** is attached to the forearm using electrode pads
2. When muscles contract, the sensor outputs an analog voltage signal
3. The **Arduino Uno** reads that analog signal and maps it to a servo angle
4. The **servo motors** rotate based on the signal — simulating finger flexion and extension

---

## 🧰 Components

| Component | Quantity | Purpose |
|---|---|---|
| Arduino Uno (Elegoo R3) | 1 | Microcontroller — reads sensor, controls servos |
| MyoWare 2.0 Muscle Sensor | 1 | Reads EMG signals from forearm muscles |
| Electrode Pads | 3 | Connects MyoWare sensor to skin |
| MS18 Servo Motors | 3–5 | Moves the fingers |
| Breadboard | 1 | Prototyping platform — no soldering required |
| Jumper Wires | Assorted | Connects all components |
| USB Cable | 1 | Powers Arduino and MyoWare from laptop |
| 4xAA Battery Pack | 1 | Dedicated power for servo motors |
| 100µF Capacitor | 1 | Smooths servo power rail, prevents jitter |
| 10kΩ Resistors | 2–3 | Signal stability on MyoWare output |
| 330Ω Resistors | 2–3 | Current limiting for status LEDs |
| LEDs | 3–5 | Visual debug indicators |
| Push Button | 1 | Mode toggle / on-off control |

---

## ⚡ Power Setup

> ⚠️ **Important:** Servos and the MyoWare sensor must use **separate power sources** to avoid signal noise and Arduino resets.

| Component | Power Source |
|---|---|
| Arduino Uno | USB from laptop |
| MyoWare 2.0 Sensor | USB from laptop (via Arduino 3.3V pin) |
| Servo Motors (x3–5) | Dedicated 4xAA battery pack (6V) |

---



## 🚀 Getting Started

### 1. Wire the Circuit
Follow the wiring diagram in `/wiring/wiring_diagram.png`

### 2. Upload the Code
- Install the [Arduino IDE](https://www.arduino.cc/en/software)
- Open `code/mark1_emg_servo.ino`
- Select **Board:** Arduino Uno
- Select the correct **COM Port**
- Click **Upload**

### 3. Attach Electrode Pads
- Place **2 electrode pads** on the belly of your forearm muscle
- Place **1 electrode pad** on a bony reference point (e.g. back of elbow) as ground

### 4. Power Up
- Connect the 4xAA battery pack to the servo power rail on the breadboard
- Connect Arduino to laptop via USB
- Open Serial Monitor to observe the raw EMG signal values

---

## ⚠️ Warnings & Things to Double Check

- **Never power servos from the Arduino 5V pin** — drawing too much current will reset or damage the board
- **Check capacitor polarity** — the 100µF capacitor has a positive and negative leg; wrong orientation can damage it
- **MyoWare operates at 3.3V** — do not connect it to the Arduino's 5V rail
- **Electrode pad placement matters** — poor placement gives noisy or flat signal; reposition if readings are inconsistent
- **Keep servo wires away from sensor wires** — servo switching noise can interfere with the EMG signal

---

## 🗺️ Roadmap

### ✅ Mark 1.0 — Current (Proof of Concept)
- Breadboard build
- Single MyoWare sensor
- 3–5 servo motors
- Basic EMG → servo mapping

### 🔜 Mark 2.0 — Planned
- Custom PCB replacing breadboard
- Arduino Mega (more PWM pins)
- Multiple MyoWare sensors for gesture variety
- Stronger servos (MG996R)
- 3D printed hand and wide display base
- Regulated power supply
- OLED display for signal feedback
- Bluetooth wireless control (HC-05)

---

## 🛠️ Built With

- [Arduino IDE](https://www.arduino.cc/)
- [Onshape](https://www.onshape.com/) — CAD modeling
- [MyoWare 2.0](https://myoware.com/) — EMG sensor platform

---

## 📄 License

This project is open source and available for personal and educational use.
