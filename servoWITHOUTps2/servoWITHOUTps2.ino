#include <Servo.h>
Servo myservo; // create servo object to control a servo
Servo myservo1;
void setup() {
  myservo.attach(9);
  myservo.attach(11);// (pin, min, max)
}
void loop()
{
  int i;
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
  for(i=1;i<180;i++)
  {
    myservo.write(i);  
  }
}
