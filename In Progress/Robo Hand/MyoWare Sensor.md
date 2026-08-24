# MyoWare 2.0 Muscle Sensor (EMG) - Direct Wiring Guide

This guide covers how to interface the **MyoWare 2.0 Muscle Sensor** directly with an Arduino board using direct soldering, bypassing the ecosystem shield connectors (saves money).

---

## 📌 Pinout Reference

Although the MyoWare 2.0 sensor exposes 8 through-hole pins, a basic analog readout only requires **3 pins**:

| Pin | Name | Type | Description | Connection |
| :--- | :--- | :--- | :--- | :--- |
| **6** | `VIN` | Power | Board power supply (3.3V – 5V) | Arduino `5V` or `3.3V` |
| **7** | `GND` | Ground | Circuit ground | Arduino `GND` |
| **8** | `ENV` | Output | Envelope signal (smoothed EMG signal) | Arduino Analog Pin (`A0`) |

### Optional Advanced Pins
* **`RAW`**: Direct, amplified AC muscle signal (for custom digital signal processing).
* **`RECT`**: Full-wave rectified signal prior to envelope smoothing.
* **`REF` / `MID` / `END`**: External electrode contacts (only used when bypassing the built-in snap pads).

---

## 🛠️ Hardware Setup

### Required Materials
* MyoWare 2.0 Muscle Sensor
* Arduino Board (Uno, Nano, ESP32, etc.)
* 3x Male-to-Female Jumper Wires
* Soldering Iron & Solder
* Biomedical Sensor Pads (Electrodes)

### Assembly Instructions
1. **Prepare Wires:** Cut the **female** end off three jumper wires, strip roughly 3–5 mm of insulation, and twist/tin the exposed copper ends.
2. **Solder Connections:** Solder the stripped wire ends to the **`VIN`**, **`GND`**, and **`ENV`** through-holes on the MyoWare board.
3. **Connect to Microcontroller:** Insert the remaining **male** pins into your Arduino or breadboard:
   - `VIN` ➔ `5V` (or `3.3V`)
   - `GND` ➔ `GND`
   - `ENV` ➔ `A0`

---

## 💻 Arduino Code Example

Upload this sketch to monitor muscle contraction levels via the **Serial Plotter** (`Ctrl + Shift + L` in Arduino IDE).

```cpp
// MyoWare 2.0 Direct Wiring Test Sketch

const int EMG_PIN = A0; // Signal pin connected to ENV

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Read analog value from muscle sensor (0 - 1023)
  int sensorValue = analogRead(EMG_PIN);

  // Output sensor value for Serial Plotter visual graph
  Serial.println(sensorValue);

  // Short delay for reading stability
  delay(1);
}
