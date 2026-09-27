const int trig=6;
const int echo=5;
int en1=3;
int in1=2;
int in2=4;
int en2=9;
int in3=8;
int in4=7;
long duration;
int distance;

void setup()
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(en1,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(en2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}
void loop()
{
  digitalWrite(trig,LOW);
  delay(.002);
  digitalWrite(trig,HIGH);
  delay(0.01);
  digitalWrite(trig,LOW);
  
  duration=pulseIn(echo,HIGH);
  distance= 0.0343*duration/2;
  
  if(distance >100)
  {
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(en1,5);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(en2,5);
  }
  else
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(en1,5);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(en2,5);
  }
  digitalWrite(LED_BUILTIN,HIGH);
}