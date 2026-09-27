// C++ code
//
void setup()
{
  
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int input=Serial.parseInt();
  if(input==1)
  {  
    digitalWrite(11, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(11, LOW);
    delay(100); // Wait for 1000 millisecond(s)
  }
  else if(input==2)
  {
   digitalWrite(10,HIGH);
   delay(1000); // Wait for 1000 millisecond(s)
   digitalWrite(10,LOW);
   delay(100); // Wait for 1000 millisecond(s)
  }
    
  
}