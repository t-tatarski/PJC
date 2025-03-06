// C++ code
//
int tablica[]={8,9,10};
int tablen;
void setup()
{
  Serial.begin(9600);
  tablen=sizeof(tablica)/sizeof(tablica[0]);
    pinMode(tablica[0], OUTPUT);
    pinMode(tablica[1], OUTPUT);
    pinMode(tablica[2], OUTPUT);
  //pinMode(4, INPUT_PULLUP);
}

void loop()
{
  for (int i=0; i<tablen; i++)
  {
  digitalWrite(tablica[i], HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(tablica[i], LOW);
  delay(500); // Wait for 1000 millisecond(s)
  }
}
