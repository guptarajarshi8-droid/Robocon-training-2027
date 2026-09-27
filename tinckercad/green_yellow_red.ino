// C++ code
//
int sw1 =2;
int sw2 =3;
int ledg=6;
int ledy=5;
int ledr=4;

  void setup()
{
  pinMode(sw1,INPUT);
    pinMode(sw2,INPUT);
    pinMode(ledg,OUTPUT);
  pinMode(ledy,OUTPUT);
    pinMode(ledr,OUTPUT);
  }
void loop()
{
  bool s1= digitalRead(sw1);
  bool s2= digitalRead(sw2);
  if(s1&&s2)
  {
   digitalWrite(ledg,HIGH);
    digitalWrite(ledr,LOW);
    digitalWrite(ledy,LOW);
  }
  else if(s1==0&&s2==1)
  {
    digitalWrite(ledr,HIGH);
    digitalWrite(ledg,LOW);
    digitalWrite(ledy,LOW);
  }
    else if(s2==0)
    {
    digitalWrite(ledy,HIGH);
      digitalWrite(ledr,LOW);
      digitalWrite(ledg,LOW);
    }
}