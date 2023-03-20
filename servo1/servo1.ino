#include <Servo.h>
Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(9,600,2300);  // (pin, min, max)
}

/*void loop() {
  myservo.write(0);  // tell servo to go to a particular angle
  delay(1000);
  myservo.write(90);            
  myservo.write(135);              
  myservo.write(180);              
  delay(1500);                             
} OR*/
void loop()
{
  int i;
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
  for(i=1;i<180;i++)
  //for(i=1;i>179;i--)
  {
    myservo.write(i);
    //delay(1000);  
  }
}
