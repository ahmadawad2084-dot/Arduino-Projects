
# Ultra Sonic Sensor - (HC-SR04) 

## What is it?
The HC-SR04 is the most common ultrasonic sensor used with Arduino. It measures distance by emitting ultrasonic sound waves and timing how long the echo takes to return.

No need for any libraries 

BTW Ultra Sonic Sensor --> USS

---

## How to Wire

```
USS Pin    → Arduino Pin                                                |  What does it do?
------------------------------------------------------------------------------------------------------------------------------------
USS GND    → GND                                                        | Ground
USS VCC    → 5V                                                         | Power Source
USS Trig   → Any digital pin other than 0,1 (Can use analog if needed)  | Triggers the USS to send a signal 
USS Echo   → Any digital pin other than 0,1 (Can use analog if needed)  | Triggers the USS to recieve a signal
```

### ⚠️ Wiring Warnings
1. The USS needs 5 volts, any lower and it wont operate properly.
2. Trig pin must be set to OUTPUT, Echo pin set to INPUT, switching them is common and results in USS not working but wont give an error message.
3. RW must go to GND or the LCD behaves erratically.

---

## Setup — General Logic of Using Ultra Sonic Sensor

1. Pulse sent to trig 
2. USS sends ultrasonic waves
3. Echo is on HIGH until emmited waves travel back to sensor (returns duration it was on HIGH)
4. Use distance formulas to convert values into usable measurments
5. Use serial monitor to print out findings

```cpp
// Setting the duration variable
  long duration = pulseIn(echopin, HIGH); //long is a class for variables, like int, float, ect... difference is that it holds more bytes of data in it than an int

// In centimeters
float distanceCm = duration / 58.0;

// In inches
float distanceInch = duration / 148.0;

// Physics-based formula (more precise)
float distanceCm = (duration * 0.0343) / 2;
//                   speed of sound   / 2 for round trip
```

## Setup — Setting USS Parameters 

Above void setup();
1. Set variables for echo and trig pin
2. Set variables for delay

Under void setup();
1. Start serial monitor
2. Set I/O pins

Under void loop();
1. digital write the trig LOW and add a delay (for the trigger delays use delayMicroseconds(); )
2. digital write the trig HIGH and add a delay
3. digital write the trig LOW and add a delay

4. make the variable of duration to be equal the echopin on HIGH
5. make distance calculation based on formulas above
6. Serial.print(); the result
7. :)
   
```cpp
void setup() {
  Serial.begin(9600);       //Started serial monitor
  pinMode(echopin, INPUT);  //Set pin 10 (echopin) to input
  pinMode(trigpin, OUTPUT); //Set pin 9 (trigpin) to output
}

void loop() {
  digitalWrite(trigpin, LOW);  //Setting the trigger off when we begin
  delayMicroseconds(smallDelay);
  digitalWrite(trigpin, HIGH);  //Setting the trigger on
  delayMicroseconds(smallDelay);
  digitalWrite(trigpin, LOW);  //Setting the trigger off when we begin
  delayMicroseconds(smallDelay * 5);
  
//Reading the Echo's duration
  long duration = pulseIn(echopin, HIGH); //long is a class for variables, like int, float, ect... difference is that it holds more bytes of data in it than an int

//Calculation
  float distance = duration / 58.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
```


## General Coding Commands

```cpp

// In void loop():
pin.Mode();              // Used to define whether a pin is an INPUT or OUTPUT (I/O)
digital.Write();         // Used to set a digital pin on the arduino board to either HIGH or LOW
analog.Write();          // Used to set an analog pin on the arduino board to either HIGH or LOW
delay();                 // Delay (very self explanatory)
delayMicroseconds();     // Delay in microseconds (also very self explanatory)
pulseIn();               // Used to set the echo pin either HIGH or LOW (Only used to set to high, since the sensor is on loop, no need to turn off) 
```



