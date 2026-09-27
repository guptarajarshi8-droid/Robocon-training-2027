// C++ code
//
const int ledg=7;
const int trig=9;
const int echo=10;
  long duration;
  int distance;
  int brightness;
  void setup()
{
  pinMode(ledg,OUTPUT);
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
  if(distance<20&&distance>200)
    digitalWrite(ledg,LOW);
  else
  {
  brightness=map(distance,20,200,0,255);
  analogWrite(ledg,brightness);
  }
  
}