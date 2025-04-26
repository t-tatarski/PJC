#include <BluetoothSerial.h> // Biblioteka Bluetooth Serial
#include "DHT.h"             // Biblioteka do czujnika DHT

// Definicje
#define DHTPIN 5            // Pin, do którego podłączony jest DHT22 (GPIO4)
#define DHTTYPE DHT22        // Typ czujnika

// Obiekty
DHT dht(DHTPIN, DHTTYPE);
BluetoothSerial SerialBT;    // Obiekt do komunikacji Bluetooth

void setup() {
  Serial.begin(115200);      // Port szeregowy do debugowania
  dht.begin();               // Inicjalizacja czujnika
  SerialBT.begin("ESP32_TempSensor"); // Nazwa urządzenia Bluetooth
  Serial.println("uruchomiony BT, czekam na połączenie...");
}

void loop() {
  float temperature = dht.readTemperature(); // Odczyt temperatury (domyślnie w °C)

  if (isnan(temperature)) {
    Serial.println("Nieudany odczyt z czujnika");
    return;
  }

  // Wysyłanie danych na port szeregowy
  Serial.println(" *C");

  // Wysyłanie danych przez Bluetooth
  SerialBT.print("Temperatura: ");
  SerialBT.print(temperature);
  SerialBT.println(" *C");

  delay(5000); // Czekaj 2 sekundy przed kolejnym odczytem
}
