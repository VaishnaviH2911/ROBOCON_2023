/*
This example shows how to retrieve a button status on PS2 Controller.

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

Product page:
  Cytron PS2 Shield: http://www.cytron.com.my/p-shield-ps2
  PS2 Controller: http://www.cytron.com.my/p-ps-gp-1
  CT-UNO: http://www.cytron.com.my/p-ct-uno

Original written by:
            Cytron Technologies

Modified:
  29/06/15  Idris, Cytron Technologies
*/

#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
int a;
int b;

Cytron_PS2Shield ps2(2, 3); // SoftwareSerial: Rx and Tx pin
//Cytron_PS2Shield ps2; // HardwareSerial
int pwm=5;
int dir=8;
void setup()
{
 ps2.begin(9600);
 Serial.begin(9600);
 pinMode(5,OUTPUT);
 pinMode(8,OUTPUT); 
}

void loop()
{
  a=a=ps2.readButton(PS2_UP);
  b=b=ps2.readButton(PS2_DOWN);
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
  analogWrite(pwm,200);
  digitalWrite(dir,HIGH);
  Serial.println("Forward");
  //delay(1000);
}
void backward()
{
  analogWrite(pwm,200);
  digitalWrite(dir,LOW);
  Serial.println("Backward");
  //delay(1000);
}
void Stop()
{
  analogWrite(pwm,0);
  digitalWrite(dir,LOW);
  Serial.println("Stop");
}
