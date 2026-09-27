int pm =A0;
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
  int pmv=analogRead(pm);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(en1,map(pmv,0,1023,0,255));
  digitalWrite(LED_BUILTIN,HIGH);
}