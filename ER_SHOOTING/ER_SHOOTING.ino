#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>

Cytron_PS2Shield ps2(2, 3); 
//SHOOTING PISTON
int a;
int b;
//Motor connections
int enA=6;
int in1=4;
int in2=5;
//relay connection
const int RELAY_PIN1 = 9;
const int RELAY_PIN2= 10;

void setup()
{
 ps2.begin(9600);
 Serial.begin(9600);
 pinMode(RELAY_PIN1, OUTPUT);
 pinMode(RELAY_PIN2, OUTPUT);
// pinMode(9,OUTPUT);
// pinMode(6,OUTPUT);
 pinMode(enA,OUTPUT);
 pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 
}

void loop()
{
  //SHOOTING PISTON
  a=ps2.readButton(PS2_UP);
  b=ps2.readButton(PS2_DOWN);
  
  //for motor
  int m=ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS);
  int e=map(m,123,0,0,255);//forward
  int f=map(m,123,255,0,255);//backward

   if(m<123)
  {
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enA,e);
  Serial.println("Forward");
  }
  else if(m>123)
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(enA,f);
  Serial.println("Backward");
  }
   else if(m==123)
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  analogWrite(enA,0);
  Serial.println("stop");
  }
  
  //for piston
  if(a==0)
  {
    piston1();
  }
  else if(b==0)
  {
    piston2();
  }
  
}
void piston1()
{
  digitalWrite(RELAY_PIN1, HIGH);
  delay(1000);
  digitalWrite(RELAY_PIN1, LOW);
  //delay(1000);
  
}
void piston2()
{
  digitalWrite(RELAY_PIN2, HIGH);
  delay(1000);
  digitalWrite(RELAY_PIN2, LOW);
  //delay(1000);
}
