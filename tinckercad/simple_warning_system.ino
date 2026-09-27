// C++ code
//
const int ledg=9;
const int ledy=10;
const int ledr=11;
const int trig=6;
const int echo=5;
const int pm=A0;
long duration;
int distance;
int pvalue;
float wdist,mpf;

void setup()
{
  pinMode(ledg,OUTPUT);
  pinMode(ledy,OUTPUT);
  pinMode(ledr,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(pm,INPUT);
  Serial.begin(9600);
  
}
float mapf(int v,float in1,float in2,float out1,float out2)
{
  mpf= (v-in1)*(out1-out2)/(in1-in2)+out1;
  return mpf;
}
void loop()
{
  digitalWrite(ledg,LOW);
  digitalWrite(ledy,LOW);
  digitalWrite(ledr,LOW);
  
  pvalue=analogRead(pm);
  wdist=mapf(pvalue,0.0,1023.0,10.0,50.0);
  //Serial.println(wdist);
  digitalWrite(trig,LOW);
    delay(.002);
  digitalWrite(trig,HIGH);
    delay(.01);
  digitalWrite(trig,LOW);
  
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  
  if(distance>wdist)
  {
    digitalWrite(ledg,HIGH);
    Serial.print("Distance measured by ultrasonic sensor:");
    Serial.print(distance);
    Serial.println("cm");
    Serial.print("Warning distance:");
    Serial.print(wdist);
    Serial.println("cm");
    Serial.println("Robo moving at full speed");
    Serial.println("The robot is at a safe distance.");
    delay(500);
  }
  else if(distance<wdist&&distance>(wdist/2))
  {
    digitalWrite(ledy,HIGH);
    Serial.print("Distance measured by ultrasonic sensor:");
    Serial.print(distance);
    Serial.println("cm");
    Serial.print("Warning distance:");
    Serial.print(wdist);
    Serial.println("cm");
    Serial.println("Robo moving at half speed");
    Serial.println("The robot is getting close to the obstacle.");
    delay(500);
  }
  else if(distance<=(wdist/2))
  {
    digitalWrite(ledr,HIGH);
    Serial.print("Distance measured by ultrasonic sensor:");
    Serial.print(distance);
    Serial.println("cm");
    Serial.print("Warning distance:");
    Serial.print(wdist);
    Serial.println("cm");
    Serial.println("Robo stopped");
    Serial.println("The robot is dangerously close to the obstacle.");
    delay(500);
  }
 
}