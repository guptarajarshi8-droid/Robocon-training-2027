
int en1=3;
int in1=2;
int in2=4;
int en2=9;
int in3=8;
int in4=7;
void setup()
{
  pinMode(en1,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(en2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}
void loop()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(en1,5);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(en2,10);
  digitalWrite(LED_BUILTIN,HIGH);
}