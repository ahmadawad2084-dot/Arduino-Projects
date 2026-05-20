#include <LiquidCrystal.h>

int greenpin = 13;
int yellowpin = 12;
int redpin = 11;

int buzz = 8;

int bigdelay = 400;
int smalldelay = 100;

int echopin = 10;
int trigpin = 9;

int x1 = 8;
int y1 = 0;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);         

  pinMode(greenpin, OUTPUT);
  pinMode(yellowpin, OUTPUT);
  pinMode(redpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(smalldelay);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(smalldelay);
  digitalWrite(trigpin, LOW);
  delayMicroseconds(smalldelay * 5);

  lcd.setCursor(x1, y1);

  long duration = pulseIn(echopin, HIGH);

  float distancecm = duration / 58.0;

  Serial.println(distancecm);
  delay(bigdelay);
  lcd.print(distancecm);


if (distancecm <=10){
    digitalWrite(redpin, HIGH);
    digitalWrite(yellowpin, LOW);
    digitalWrite(greenpin, LOW);
    digitalWrite(buzz, HIGH);
   
}
  else if (distancecm >= 11 && distancecm <= 30){
    digitalWrite(redpin, LOW);
    digitalWrite(yellowpin, HIGH);
    digitalWrite(greenpin, LOW); 
     digitalWrite(buzz, LOW);
    delay(smalldelay);   
    digitalWrite(buzz, HIGH);
    }

    else {
      digitalWrite(redpin, LOW);
      digitalWrite(yellowpin, LOW);
      digitalWrite(greenpin, HIGH);
          digitalWrite(buzz, LOW);   


    }

}
