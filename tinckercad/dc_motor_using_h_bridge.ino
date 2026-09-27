// C++ code
//
int en1=3;
int in1=2;
int in2=4;

void setup()
{
  pinMode(en1,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
}
void loop()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(en1,10);
}