#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
#include <Servo.h>
Servo myservo;

Cytron_PS2Shield ps2(2, 3); // SoftwareSerial: Rx and Tx pin

void setup()
{
 ps2.begin(9600);
 Serial.begin(9600);
 myservo.attach(9,600,2300);
 pinMode(9,OUTPUT);
}

void loop()
{
  int i;
  int m=ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS);
  
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
  
}
