#include<Servo.h>
int pos=0;
int pm=A0;
int pmv;
int ang1,ang2;
Servo s1;
Servo s2;

void setup()
{
  pinMode(pm,INPUT);
  s1.attach(6);
  s2.attach(5);
}

void loop()
{
  pmv=analogRead(pm);
  ang1=map(pmv,0,1023,0,180);
  ang2=map(pmv,0,1023,180,0);
  s1.write(ang1);
  s2.write(ang2);
}