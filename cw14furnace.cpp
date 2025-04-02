#include <MAX6675.h>

// Definicje pinów
const int thermoDO = 4;
const int thermoCS = 5;
const int thermoCLK = 6;
const int relayPin = 7; // Sterowanie grzałką

// Inicjalizacja termopary
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

// Parametry programu wypalania
const float startTemp = 450.0;
const float targetTemp = 750.0;
const float holdTime = 60.0; // 1 minuta
const float coolingTargetTemp = 600.0;
const float rate = 60.0 / 60.0; // 60 stopni na minutę -> 1 stopień na sekundę

void setup() {
    Serial.begin(9600);
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, LOW);
    Serial.println("System start");
    delay(1000);
}

void loop() {
    float currentTemp = thermocouple.readCelsius();
    Serial.print("Current Temp: ");
    Serial.println(currentTemp);
    
    // Nagrzewanie
    while (currentTemp < targetTemp) {
        digitalWrite(relayPin, HIGH);
        delay(1000);
        currentTemp = thermocouple.readCelsius();
        Serial.print("Heating: ");
        Serial.println(currentTemp);
        
        if (currentTemp >= targetTemp) {
            break;
        }
    }
    digitalWrite(relayPin, LOW);
    
    // Utrzymanie temperatury
    Serial.println("Holding temperature");
    delay(holdTime * 1000);
    
    // Chłodzenie
    while (currentTemp > coolingTargetTemp) {
        digitalWrite(relayPin, LOW);
        delay(1000);
        currentTemp = thermocouple.readCelsius();
        Serial.print("Cooling: ");
        Serial.println(currentTemp);
        
        if (currentTemp <= coolingTargetTemp) {
            break;
        }
    }
    
    Serial.println("Process complete");
    while (1); // Zatrzymanie programu
}
