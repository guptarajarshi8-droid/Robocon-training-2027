// C++ code
//
int pm = A0;
int mot=5;
int led=9;
int value=0;
const int tric =11;
const int echo =10;
long duration=0;
int distance;
  void setup()
{
  pinMode(pm,INPUT);
  pinMode(led,OUTPUT);
  pinMode(mot,OUTPUT);
  pinMode(tric,OUTPUT);
  pinMode(echo,INPUT);
    Serial.begin(9600);
  }
void loop()
{
  digitalWrite(tric,LOW);
  delayMicroseconds(2);
  digitalWrite(tric,HIGH);
  delayMicroseconds(10);
  digitalWrite(tric,LOW);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  
   value= analogRead(pm);
  // Serial.print("value:");
   //Serial.println(value);
  Serial.println(distance);
   //out = map(value,0,1023,0,255);
  if(distance>40)
  {
   digitalWrite(led,HIGH);
   analogWrite(mot,map(value,0,1023,0,255));
  }
  else if(distance<40)
  {
    digitalWrite(led,LOW);
    digitalWrite(mot,LOW);
  }
}