// C++ code
//

#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

int BTN1=6;
int BTN2=5;
int BTN3=4;
int SPEAKERPIN=8;

void initSound(){
  tone(SPEAKERPIN,350,400);
  delay(200);
  tone(SPEAKERPIN,650,400);
  delay(200);
  tone(SPEAKERPIN,750,400);
  }

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
 
  lcd.print("ready...");
  pinMode(SPEAKERPIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
}

void loop()
{
  initSound();
  digitalWrite(LED_BUILTIN, HIGH);
  if (digitalRead(BTN1)==HIGH){
  Serial.print("button1"); }
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
