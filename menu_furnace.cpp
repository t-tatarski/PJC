#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BTN_UP 2
#define BTN_DOWN 3
#define BTN_OK 4

LiquidCrystal_I2C lcd(0x27, 16, 2);

int menuIndex = 0;
int submenuIndex = 0;
bool inSubMenu = false;

const char *menuItems[] = {"PROGRAMY", "SERWIS", "INFO", "RESET"};
const int menuSize = sizeof(menuItems) / sizeof(menuItems[0]);

const char *submenuItems[] = {"wash", "opaque", "dentin", "dentin2", "glaze", "cor with glaze"};
const int submenuSize = sizeof(submenuItems) / sizeof(submenuItems[0]);

void setup() {
    lcd.init();
    lcd.backlight();
    pinMode(BTN_UP, INPUT_PULLUP);
    pinMode(BTN_DOWN, INPUT_PULLUP);
    pinMode(BTN_OK, INPUT_PULLUP);
    displayMenu();
}

void loop() {
    if (digitalRead(BTN_UP) == LOW) {
        delay(200);
        if (inSubMenu) {
            submenuIndex = (submenuIndex - 1 + submenuSize) % submenuSize;
            displaySubMenu();
        } else {
            menuIndex = (menuIndex - 1 + menuSize) % menuSize;
            displayMenu();
        }
    }
    if (digitalRead(BTN_DOWN) == LOW) {
        delay(200);
        if (inSubMenu) {
            submenuIndex = (submenuIndex + 1) % submenuSize;
            displaySubMenu();
        } else {
            menuIndex = (menuIndex + 1) % menuSize;
            displayMenu();
        }
    }
    if (digitalRead(BTN_OK) == LOW) {
        delay(200);
        if (menuIndex == 0) {
            inSubMenu = true;
            submenuIndex = 0;
            displaySubMenu();
        }
    }
}

void displayMenu() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("> ");
    lcd.print(menuItems[menuIndex]);
}

void displaySubMenu() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("-> ");
    lcd.print(submenuItems[submenuIndex]);
}
