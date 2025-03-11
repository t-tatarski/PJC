#include <Adafruit_LiquidCrystal.h>

// C++ code
// LDC library methodes
/*
begin	KEYWORD2
clear	KEYWORD2
home	KEYWORD2
print	KEYWORD2
setCursor	KEYWORD2
cursor	KEYWORD2
noCursor	KEYWORD2
blink	KEYWORD2
noBlink	KEYWORD2
display	KEYWORD2
noDisplay	KEYWORD2
autoscroll	KEYWORD2
noAutoscroll	KEYWORD2
leftToRight	KEYWORD2
rightToLeft	KEYWORD2
scrollDisplayLeft	KEYWORD2
scrollDisplayRight	KEYWORD2
createChar	KEYWORD2
setBacklight	KEYWORD2
  */
Adafruit_LiquidCrystal lcd1(0);
void setup()
{
  //ustawienie kursora 
  lcd1.begin(16,2);
  lcd1.setBacklight(HIGH);
  lcd1.print("hello!");
  lcd1.setCursor(0,1);
  lcd1.print("bastards!");
  delay(3000);
  lcd1.clear();
  //podswietlanie slabe
  lcd1.setBacklight(LOW);
  lcd1.print("i'm going to bed");
  lcd1.setCursor(1,0);
  //migajacy kursor
  lcd1.blink();
  delay(3000);
  lcd1.noBlink();
}

void loop()
{
}
