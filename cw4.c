// C++ code
//
bool diodaset;
int countr=0;
int diodacount=0;
const int interval=900;
unsigned long prevMillis=0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}
void setLed()
{ 
  if ( millis()-prevMillis >= interval )
  {
     prevMillis=millis();
     countr++;
     Serial.println(countr);
  }
  if (countr-diodacount>=2){
       diodacount=countr;
       diodaset =! diodaset;
       Serial.print(diodaset);
    digitalWrite(LED_BUILTIN,diodaset); // dioda na plytce (L)
  }
    
}
void loop()
{
  setLed();
}
