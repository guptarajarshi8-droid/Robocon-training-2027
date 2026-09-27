// C++ code
//
int pm =6;
int led=2;

  void setup()
{
  pinMode(pm,INPUT);
  pinMode(led,OUTPUT);
    Serial.begin(9600);
  }
void loop()
{
  int s= analogRead(pm);
   analogWrite(led,s);
  Serial.println(s);
  Serial.println(map(s,0,1023,0,255));
}