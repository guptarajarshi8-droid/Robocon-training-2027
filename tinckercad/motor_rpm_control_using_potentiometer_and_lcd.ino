#include <Adafruit_LiquidCrystal.h>
int pm =A0;
int en1=3;
int in1=2;
int in2=4;
int rpm;
Adafruit_LiquidCrystal lcd_1(0);
void setup()
{
  pinMode(en1,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  lcd_1.begin(16, 2);

  lcd_1.print("Hello World");
  delay(1000);
  lcd_1.clear();
}
void loop()
{
  lcd_1.setBacklight(1);
  int pmv=analogRead(pm);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(en1,map(pmv,0,1023,0,255));
  rpm=map(pmv,0,1023,0,10922);
  lcd_1.setCursor(0, 0);
  lcd_1.print("Potvalue:");
  lcd_1.print(pmv);
  lcd_1.print("    "); 
  lcd_1.setCursor(0, 1);
  lcd_1.print("RPM:");
  lcd_1.print(rpm);
  lcd_1.print("    "); 
  digitalWrite(LED_BUILTIN,HIGH);
}