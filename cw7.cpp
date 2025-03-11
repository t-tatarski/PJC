#include <Adafruit_LiquidCrystal.h>

// C++ code
// LDC library
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
}

void loop()
{
}
