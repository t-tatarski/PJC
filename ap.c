// C++ code
// arduino proj. 1
int piny[]={2,3,4,5,6,7,8,9};
int pinylength;
void setup()
{
  pinylength=sizeof(piny)/sizeof(piny[0]);
  for(int i=0; i<pinylength; i++){ 
  pinMode(piny[i], OUTPUT);
  }
}

void loop()
{
  
  for(int i=0; i<pinylength; i++){
  digitalWrite(piny[i], HIGH);
  delay(100); // Wait for 200 millisecond(s)
  digitalWrite(piny[i], LOW);
  //delay(100);
  }
  for(int i=pinylength; i>0; i--){
  digitalWrite(piny[i], HIGH);
  delay(100); // Wait for 200 millisecond(s)
  digitalWrite(piny[i], LOW);
  //delay(100);
  }
  
  
  
}
