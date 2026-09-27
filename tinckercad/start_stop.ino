// C++ code
//
const int ledg=7;
const int ledr=6;
const int trig=9;
const int echo=10;
  long duration;
  int distance;
  void setup()
{
  pinMode(ledg,OUTPUT);
  pinMode(ledr,OUTPUT);
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
  }
void loop()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  
  if(distance>50)
  {
    digitalWrite(ledg,HIGH);
    digitalWrite(ledr,LOW);
  }
  else if(distance<50)
  {
   digitalWrite(ledr,HIGH);
    digitalWrite(ledg,LOW);
  }
}