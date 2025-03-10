// C++ code
//
// definicja pinów i zmiennej timebutton
int pindig=2;
long timebutton;
void setup()
{
  Serial.begin(9600);
  pinMode(pindig, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
 // metoda pulseIn
 timebutton = pulseIn(pindig, HIGH);	
  Serial.println(timebutton);
  if (timebutton >=160000){
   digitalWrite(13, HIGH);
  }else if(timebutton<1000){
   digitalWrite(13,LOW);
  }
}
   
