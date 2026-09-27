// C++ code
//
int ledPins[4] = {11, 10, 9, 6};

void setup() 
{
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) 
    {
      pinMode(ledPins[i],OUTPUT);
    }
  Serial.println("Enter a decimal number (0-15):");
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    int n = Serial.parseInt();


    if (n < 0 || n > 15) 
    {
      Serial.println("Please enter a number between 0 and 15.");
      return;
    }

    int bits[4]; 
    int ncopy = n;

    
    for (int i = 3; i >= 0; i--) 
    {
      bits[i] = ncopy% 2;
      ncopy = ncopy / 2;
    }
    
    for (int i = 0; i < 4; i++) 
    {
      digitalWrite(ledPins[i], bits[i] == 1 ? HIGH : LOW);
    }

    Serial.print(n);
    Serial.print(" in binary is: ");
    for (int i = 0; i < 4; i++)
    {
      Serial.print(bits[i]);
    }
    Serial.println();
  }
}