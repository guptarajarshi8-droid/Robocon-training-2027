#include<Servo.h>
int pos=0;
Servo s;

void setup()
{
  s.attach(6);
}
void loop()
{
 for(pos=0;pos<=180;pos++)
  {
    s.write(pos);
    delay(15);
  }
  delay(1000);
  for(pos=180;pos>=0;pos--)
  {
    s.write(pos);
    delay(15);
  }
}