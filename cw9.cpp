#include "Adafruit_LEDBackpack.h"
// C++ code
// biblioteka do displayow siedmiosegmentowych
// 
Adafruit_7segment matrix = Adafruit_7segment();
void setup()
{
 matrix.begin(0x70);
}

void loop()
{
  matrix.print(10000, DEC);
  matrix.writeDisplay();
  delay(500);

  // print a hex number
  matrix.print("CODE");
  matrix.writeDisplay();
  delay(500);
  
}
