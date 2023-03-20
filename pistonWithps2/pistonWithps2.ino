#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
int a;
int b;

Cytron_PS2Shield ps2(2, 3); 
int pwm=9;
void setup()
{
 ps2.begin(9600);
 Serial.begin(9600);
 pinMode(9,OUTPUT);
}

void loop()
{
  a=ps2.readButton(PS2_UP);
  b=ps2.readButton(PS2_DOWN);
  if(a==0)
  {
    forward();
  }
  else if(b==0)
  {
    backward();
  }
  else
  {   
    Stop();
  }
  
}
void forward()
{
  digitalWrite(pwm,200);
  Serial.println("Forward");
}
void backward()
{
  digitalWrite(pwm,200);
  Serial.println("Backward");
}
void Stop()
{
  digitalWrite(pwm,0);
  Serial.println("Stop");
}
