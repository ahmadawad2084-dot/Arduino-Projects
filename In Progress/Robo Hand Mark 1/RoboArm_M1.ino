/*
  RoboArm Mark 1.0 — EMG-Controlled Robotic Hand
  MyoWare 2.0 -> Arduino Uno (Elegoo) -> 3x MS18 Servos + 3x Status LEDs

  Signal flow:
    MyoWare ENV (A0, analog input)
      -> analogRead()
      -> map() to servo angle range
      -> Servo.write() on all 3 fingers
    Status LEDs give visual feedback on power / signal / motion
*/

#include <Servo.h>

// ---------- Pin assignments ----------
const int EMG_PIN = A0;      // MyoWare ENV output -> Arduino analog input

const int SERVO_THUMB_PIN  = 11;  // PWM
const int SERVO_INDEX_PIN  = 10;  // PWM
const int SERVO_MIDDLE_PIN = 9;   // PWM

const int LED_SIGNAL_PIN = 4;  // "Signal Detected"
const int LED_SERVO_PIN  = 5;  // "Servo Moving"
const int LED_POWER_PIN  = 6;  // "Power On"

// ---------- Servo objects (one per physical servo) ----------
Servo thumbServo;
Servo indexServo;
Servo middleServo;

// ---------- Tunable calibration values ----------
// Raw analogRead() range is 0-1023. Adjust these after you watch
// real EMG values in the Serial Monitor (relaxed vs. flexed).
const int EMG_BASELINE  = 0;     // raw value when muscle is relaxed
const int EMG_MAX       = 900;   // raw value at a strong flex (calibrated for current placement)
const int SIGNAL_THRESHOLD = 100; // above this = "signal detected" LED on

// Servo angle range — start conservative, widen once you confirm
// the fingers don't jam or over-rotate at the extremes.
const int SERVO_MIN_ANGLE = 30;
const int SERVO_MAX_ANGLE = 150;

// Used to detect "servo moving" for the LED
int lastAngle = SERVO_MIN_ANGLE;
const int MOVEMENT_DEADBAND = 3; // ignore tiny jitter, degrees

void setup() {
  Serial.begin(9600); // for calibration/debugging — read live EMG values here

  // Servo min/max are the pulse-width range in microseconds (not degrees).
  // 544/2400 are the Arduino default values — check the MS18 datasheet
  // and adjust if your servos buzz or don't reach full range.
  thumbServo.attach(SERVO_THUMB_PIN, 544, 2400);
  indexServo.attach(SERVO_INDEX_PIN, 544, 2400);
  middleServo.attach(SERVO_MIDDLE_PIN, 544, 2400);

  pinMode(LED_SIGNAL_PIN, OUTPUT);
  pinMode(LED_SERVO_PIN, OUTPUT);
  pinMode(LED_POWER_PIN, OUTPUT);

  digitalWrite(LED_POWER_PIN, HIGH); // stays on once powered — confirms setup ran
}

void loop() {
  // 1. Read raw EMG signal
  int rawEMG = analogRead(EMG_PIN);

  // 2. Translate EMG reading into a servo angle
  //    constrain() first so a spike beyond EMG_MAX doesn't map outside range
  int clampedEMG = constrain(rawEMG, EMG_BASELINE, EMG_MAX);
  int angle = map(clampedEMG, EMG_BASELINE, EMG_MAX, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE);

  // 3. Drive all three fingers together with the same mapped angle
  thumbServo.write(angle);
  indexServo.write(angle);
  middleServo.write(angle);

  // 4. LED: Signal Detected — on when flex is above threshold
  digitalWrite(LED_SIGNAL_PIN, rawEMG > SIGNAL_THRESHOLD ? HIGH : LOW);

  // 5. LED: Servo Moving — on when angle changed meaningfully since last loop
  if (abs(angle - lastAngle) > MOVEMENT_DEADBAND) {
    digitalWrite(LED_SERVO_PIN, HIGH);
  } else {
    digitalWrite(LED_SERVO_PIN, LOW);
  }
  lastAngle = angle;

  // Debug output — watch this in Serial Monitor to calibrate EMG_MAX
  Serial.print("raw EMG: ");
  Serial.print(rawEMG);
  Serial.print("  ->  angle: ");
  Serial.println(angle);

  delay(15); // small delay for signal + servo stability, not strictly required
}
