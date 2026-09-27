// C++ code
//
const int ledg=9;
const int ledy=10;
const int ledr=11;
const int pm=A0;
int pvalue=0;

void setup()
{
  pinMode(ledg,OUTPUT);
  pinMode(ledy,OUTPUT);
  pinMode(ledr,OUTPUT);
  pinMode(pm,INPUT);
  Serial.begin(9600);
}
void loop()
{
  
  pvalue=analogRead(pm);
  Serial.print("Potentiometer value:");
  Serial.println(pvalue);
 
  if(pvalue<=340)
  {
     digitalWrite(ledy,LOW);
     digitalWrite(ledr,LOW);
    Serial.println("Current LED: GREEN");
    analogWrite(ledg,map(pvalue,0,340,0,255));
    delay(500);
  }
  else if(pvalue>340&&pvalue<=680)
  {
     digitalWrite(ledg,LOW);
     digitalWrite(ledr,LOW);
    Serial.println("Current LED: YELLOW");
  analogWrite(ledy,map(pvalue,341,640,0,255));
    delay(500);
  }
  else if(pvalue>680)
  {
     digitalWrite(ledy,LOW);
     digitalWrite(ledg,LOW);
     Serial.println("Current LED: RED");
    analogWrite(ledr,map(pvalue,681,1023,0,255));
    delay(500);
  }
}