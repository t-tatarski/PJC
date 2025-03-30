#include <Wire.h>

void setup() {
    Serial.begin(9600);
    Wire.begin();
}

void loop() {
    byte error, adrs;
    
    Serial.println("scanning ..");
    
    for (adrs = 1; adrs < 127; adrs++) {
        Wire.beginTransmission(adrs);
        error = Wire.endTransmission();
        
        if (error == 0) {
            Serial.print("znalezione urządzenie na adresie 0x");
            Serial.println(adrs, HEX);
        }
    }
    
}
