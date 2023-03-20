/*
This example shows how to read a joystick value on PS2 Controller.

Function:
  readButton(button); // Read button status, it will return corresponding data
                      // Digital button: 0 = pressed, 1 = released
                      // Analog button: return a value

  Digital button:
    PS2_SELECT
    PS2_JOYSTICK_LEFT
    PS2_JOYSTICK_RIGHT
    PS2_START
    PS2_UP
    PS2_RIGHT
    PS2_DOWN
    PS2_LEFT
    PS2_LEFT_2
    PS2_RIGHT_2
    PS2_LEFT_1
    PS2_RIGHT_1
    PS2_TRIANGLE
    PS2_CIRCLE
    PS2_CROSS
    PS2_SQUARE

  Analog button:
    PS2_JOYSTICK_LEFT_X_AXIS
    PS2_JOYSTICK_LEFT_Y_AXIS
    PS2_JOYSTICK_RIGHT_X_AXIS
    PS2_JOYSTICK_RIGHT_Y_AXIS
    PS2_JOYSTICK_LEFT_UP
    PS2_JOYSTICK_LEFT_DOWN
    PS2_JOYSTICK_LEFT_LEFT
    PS2_JOYSTICK_LEFT_RIGHT
    PS2_JOYSTICK_RIGHT_UP
    PS2_JOYSTICK_RIGHT_DOWN
    PS2_JOYSTICK_RIGHT_LEFT
    PS2_JOYSTICK_RIGHT_RIGHT


*/

#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>

Cytron_PS2Shield ps2(2, 3);
 
int ena=6;
int in1=4;
int in2=5;
void setup()
{
  ps2.begin(9600); 
  Serial.begin(9600);
  pinMode(ena,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
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
  analogWrite(ena,b);
  Serial.println("Forward");
  Serial.println(m);
  }
  else if(m>123)
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(ena,c);
  Serial.println("Backward");
  Serial.println(m);
  }
  else if(m==123)
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  analogWrite(ena,0);
  Serial.println("stop");
  }
}
