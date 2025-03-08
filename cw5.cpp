// C++ code
//
int pindig=2;
void setup()
{
  Serial.begin(9600);
  pinMode(pindig, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
 bool stan=digitalRead(pindig);
  if (stan==HIGH){
    Serial.println("high");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    
  }
  else
  {
    Serial.println("low");
     digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }
  
}
