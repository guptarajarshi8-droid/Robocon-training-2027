#include <Adafruit_LiquidCrystal.h>

 


  const int trig=12;
  const int trig_L=11;
  const int echo_C=9;
  const int echo_L=13;
  const int echo_R=1;
  long duration;
  int distance;
  const int pot=A0;
  const int en1=3;
  const int in1=2;
  const int in2=4;
  const int en2=10;
  const int in3=0;
  const int in4=8;
  const int en3=10;
  const int in5=5;
  const int in6=7;

//Ultrasonic sensor 
class Ultrasonic 
{
  int trig, echo;
public:
  Ultrasonic(int t, int e) : trig(t), echo(e) {}
  void begin() 
  { 
    pinMode(trig, OUTPUT); pinMode(echo, INPUT); 
  }
  int cm()
  {
    digitalWrite(trig, LOW); 
    delayMicroseconds(2);
    digitalWrite(trig, HIGH); delayMicroseconds(10);
    digitalWrite(trig, LOW);
    int duration = pulseIn(echo, HIGH);
    return (duration == 0) ? 400 : (int)(duration * 0.0343 / 2);
  }
};

// One motor channel on the L293D 
class Motor {
  int en, a, b;
  bool pwm;                          
public:
  Motor(int e, int a_, int b_, bool p) : en(e), a(a_), b(b_), pwm(p) {}
  void begin()
  { 
    pinMode(en, OUTPUT); pinMode(a, OUTPUT); pinMode(b, OUTPUT); 
  }
  void run(int speed)
  {                    // -255 .. 255
    digitalWrite(a, speed > 0);
    digitalWrite(b, speed < 0);
    if (pwm) 
      analogWrite(en, abs(speed));
    else     
      digitalWrite(en, speed != 0);
  }
  void stop() { run(0); }
};

//LCD 
class Display {
  Adafruit_LiquidCrystal lcd;
  unsigned long last = 0;
public:
  Display() : lcd(0) {}                    
  void begin() { lcd.begin(16, 2); }
  void show(int l, int c, int r, int spd, const char *state) 
  {
    if (millis() - last < 250) return;     // avoid flicker
    last = millis();
    lcd.setCursor(0, 0);
    lcd.print("L"); lcd.print(l); lcd.print(" C"); lcd.print(c);
    lcd.print(" R"); lcd.print(r); lcd.print("  ");
    lcd.setCursor(0, 1);
    lcd.print("S:"); lcd.print(spd); lcd.print(" "); lcd.print(state); lcd.print("    ");
  }
};

// Car
class Car 
{
  Motor &rear, &fl, &fr;
  Ultrasonic &sl, &sc, &sr;
  Display &disp;

  const int STOP_CM = 30;                  // centre closer than this -> reverse and turn
  const int SLOW_CM = 60;                  // centre closer than this -> slow and steer away
  const int SIDE_CM = 40;                  // side closer than this  -> steer away
  const int STEER_PWM = 200;

  int l, c, r, spd = 0;

  void steerLeft()    
  {
    fl.run(-STEER_PWM); 
    fr.run(STEER_PWM); 
  }
  void steerRight()    
  { 
    fl.run(STEER_PWM);  
    fr.run(-STEER_PWM); 
  
  }
  void steerStraight() 
  { 
    fl.stop(); 
    fr.stop(); 
  }

public:
  Car(Motor &rm, Motor &lm, Motor &rtm, Ultrasonic &a, Ultrasonic &b, Ultrasonic &d, Display &ds)
    : rear(rm), fl(lm), fr(rtm), sl(a), sc(b), sr(d), disp(ds) {}

  void update() {
    spd = map(analogRead(pot), 0, 1023, 0, 255);   // pot = rear motor speed
    l = sl.cm();
    c = sc.cm();
    r = sr.cm();

    if (l < STOP_CM && c < STOP_CM && r < STOP_CM) 
    {                              // blocked ahead
      disp.show(l, c, r, spd, "STUCK");
      rear.stop();
      if (c < STOP_CM) 
     {                              // blocked all side
      steerStraight();
      disp.show(l, c, r, spd, "REVERSE");
      rear.run(-spd);
      delay(400);
      rear.stop();
     
     }
                           
      else if (l < r)   // turn toward the clearer side
        steerLeft(); 
      else 
      {
        steerRight();
        disp.show(l, c, r, spd, l<r ? "TURN L" : "TURN R");
        rear.run(spd);
        delay(500);
        steerStraight();
      }
    }
    else if (l < SIDE_CM || r < SIDE_CM || c < SLOW_CM) 
    {   // something close: steer away, slow down
      if (l < r) 
      { 
        steerRight(); 
        disp.show(l, c, r, spd, "TURN R");
      }
      else       
      { 
        steerLeft();  
        disp.show(l, c, r, spd, "TURN L"); 
      }
      rear.run(spd / 2);
    }
    
    else 
    {                                          // clear
      steerStraight();
      rear.run(spd);
      disp.show(l, c, r, spd, "CLEAR");
    }
  }
};

// ---------- Globals ----------
Ultrasonic sonarL(trig_L, echo_L), sonarC(trig, echo_C), sonarR(trig,echo_R);
Motor rearMotor(en1, in1, in2, true);
Motor frontLeft(en2, in3, in4, true);
Motor frontRight(en3, in5, in6,true);
Display display;
Car car(rearMotor, frontLeft, frontRight, sonarL, sonarC, sonarR, display);

void setup()
{
  sonarL.begin(); sonarC.begin(); sonarR.begin();
  rearMotor.begin(); frontLeft.begin(); frontRight.begin();
  display.begin();
}

void loop() 
{
  car.update();
}

