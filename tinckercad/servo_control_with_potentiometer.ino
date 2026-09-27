#include<Servo.h>
int pos=0;
int pm=A0;
int pmv;
int ang;
Servo s;

void setup()
{
  pinMode(pm,INPUT);
  s.attach(6);
}

void loop()
{
  pmv=analogRead(pm);
  ang=map(pmv,0,1023,0,180);
  s.write(ang);
}