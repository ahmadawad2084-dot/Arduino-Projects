#include <LiquidCrystal.h>
//Loop counter
int v = 5;

//X and Y coordinates
int x1 = 8;
int y1 = 0;

int x2 = 0;
int y2 = 0;

//Delay
int dl = 1000;

//General variable
int XP = 0;



// (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);  // 16 columns, 2 rows
  lcd.setCursor(x2, y2);
    lcd.print("Timer: ");
}

void loop() {

  //for (v==0; x<= 5; x++)
  while (v < 100)

  {
    lcd.setCursor(x1, y1);
    lcd.print(XP);
    XP++;
    delay(dl);
  }
}


