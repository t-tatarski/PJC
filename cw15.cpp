#include <SPI.h>
//main (master) 
void setup() {
  Serial.begin(9600);
  SPI.begin();
  pinMode(10, OUTPUT); 

void loop() {
  digitalWrite(10, LOW); // slave
  byte dataToSend = 79; // example value
  byte response = SPI.transfer(dataToSend);
  digitalWrite(10, HIGH); // 

  Serial.print("Wysłano: ");
  Serial.print(dataToSend);
  Serial.print(" | Otrzymano: ");
  Serial.println(response);

}
