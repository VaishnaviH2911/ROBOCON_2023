#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
Cytron_PS2Shield ps2(2, 3);
 
int enA=9;
int in1=8;
int in2=7;

int enB=3;
int in3=2;
int in4=4;

int enC=11;
int in5=12;
int in6=13;

int enD=6;
int in7=5;
int in8=10;
void setup()
{
  ps2.begin(9600); 
  Serial.begin(9600);
  //right 1st motor
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  //right 2nd motor
  pinMode(enB,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  //left 1st motor
  pinMode(enC,OUTPUT);
  pinMode(in5,OUTPUT);
  pinMode(in6,OUTPUT);
  //left 2nd motor
  pinMode(enD,OUTPUT);
  pinMode(in7,OUTPUT);
  pinMode(in8,OUTPUT);
}

void loop()
{
  int m=ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS);

  int b=map(m,123,0,0,255);//forward
  int c=map(m,123,255,0,255);//backward

  if(m<123)
  {
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enA,b);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB,b);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
  analogWrite(enC,b);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH);
  analogWrite(enD,b);
  
  Serial.println("Forward");
  //Serial.println(m);
  }
  else if(m>123)
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(enA,c);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enB,c);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  analogWrite(enC,c);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);
  analogWrite(enD,c);
  
  Serial.println("Backward");
  Serial.println(m);
  }
  else if(m==123)
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  analogWrite(enA,0);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(enB,0);
  digitalWrite(in5,LOW);
  digitalWrite(in6,LOW);
  analogWrite(enC,0);
  digitalWrite(in,7LOW);
  digitalWrite(in8,LOW);
  analogWrite(enD,0);
  Serial.println("stop");
  }
}
