#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
#include <Servo.h>
Servo myservo;
Servo myservo1;

Cytron_PS2Shield ps2(2, 3); // SoftwareSerial: Rx and Tx pin

void setup()
{
 ps2.begin(9600);
 Serial.begin(9600);
 myservo.attach(9);
 myservo1.attach(11);
 pinMode(9,OUTPUT);
 pinMode(11,OUTPUT);
}

void loop()
{
  int m=ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS);
  int n=ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS);
  
  if(m<123)
  {
    int b=map(m,122,0,0,255);
    myservo.write(b);
    Serial.println("forward");
    Serial.println(b);
    
  }
  else if(m==123)
  {
    myservo.write(0);               
  }
  if(n<123)
  {
    int c=map(n,122,0,0,255);
    myservo1.write(c);
    Serial.println("forward");
    Serial.println(c);
  }
  else if(n==123)
  {
    myservo1.write(0);               
  }
  
}
