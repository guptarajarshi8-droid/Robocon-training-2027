#include<Servo.h>
int pos=0;
int ang;
Servo s;

void setup()
{
  s.attach(6);
  Serial.begin(9600);
  Serial.print("Enter an angle:");
}
void loop()
{
  if(Serial.available()>0)
  {
  
 
    ang = Serial.parseInt();

    if (ang < 0 || ang > 180) 
    {
      Serial.println("Please enter an angle between 0 and 180.");
      return;
    }
    s.write(ang);
  
  Serial.print(ang);
  Serial.println();
  Serial.print("Enter an angle:");
  }
}