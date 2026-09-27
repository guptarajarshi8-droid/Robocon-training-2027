// C++ code
//
int sw =7;
int led=2;

  void setup()
{
  pinMode(sw,INPUT);
  pinMode(led,OUTPUT);
  }
void loop()
{
  bool s= digitalRead(sw);
   digitalWrite(led,s);
}