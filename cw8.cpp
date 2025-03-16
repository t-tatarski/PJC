// C++ code
//
#include "Adafruit_LiquidCrystal.h"

Adafruit_LiquidCrystal lcd(0);


const int upButton = A0;    // Przycisk "Góra"
const int downButton = A1;  // Przycisk "Dół"
const int selectButton = A2;// Przycisk "Wybierz"

int menuItem = 0;           // Numer wybranego elementu menu
const int menuSize = 3;     // Liczba elementów menu

String menuItems[menuSize] = {
  "programy 1",
  "ustawienia 2",
  "serwis 3"
};

void setup() {
  lcd.begin(16, 2);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  Serial.begin(9600);
  showMenu();
}

void loop() {
  if (digitalRead(upButton) == LOW) {
    menuItem = (menuItem - 1 + menuSize) % menuSize; // Przejście do góry
    showMenu();
    delay(200);
  }

  if (digitalRead(downButton) == LOW) {
    menuItem = (menuItem + 1) % menuSize; // Przejście w dół
    showMenu();
    delay(400);
  }

  if (digitalRead(selectButton) == LOW) {
    Serial.print("Wybrano: ");
    Serial.println(menuItems[menuItem]); // Wyświetlenie wyboru w monitorze szeregowym
    delay(500);
  }
}

void showMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MENU:");
  lcd.setCursor(0, 1);
  lcd.print("> " + menuItems[menuItem]); // Strzałka wskazuje aktualny wybór
}
