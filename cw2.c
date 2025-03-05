
// C++ code
// arduino proj. 2
int piny[]={2,3,4,5,6,7,8,9};
int pinylength;
int speed=100;
void setup()
{
  Serial.begin(9600);
  pinylength=sizeof(piny)/sizeof(piny[0]);
  for(int i=0; i<pinylength; i++){ 
  pinMode(piny[i], OUTPUT);
  }
}

void loop()
{
  
  for(int i=0; i<pinylength; i++){
  digitalWrite(piny[i], HIGH);
  delay(speed); // Wait for 200 millisecond(s)
  digitalWrite(piny[i], LOW);
  //delay(100);
  }
  speed=analogRead(5);
  for(int i=pinylength; i>0; i--){
  digitalWrite(piny[i], HIGH);
  delay(speed); // Wait for 200 millisecond(s)
  digitalWrite(piny[i], LOW);
  //delay(100);
  }
  
  
  
}
