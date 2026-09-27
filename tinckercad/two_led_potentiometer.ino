// C++ code
//
const int ledg=3;
const int ledr=5;
const int pm=A0;
int pmv;
void setup()
{
  pinMode(ledg,OUTPUT);
  pinMode(ledr,OUTPUT);
  pinMode(pm,INPUT);
  Serial.begin(9600);
}
void loop()
{
  pmv=analogRead(pm);
  analogWrite(ledg,map(pmv,0,1023,0,255));
  analogWrite(ledr,map(pmv,0,1023,255,0));            
}