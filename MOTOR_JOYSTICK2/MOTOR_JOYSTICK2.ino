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
int c;
int d;
int e;
int f;
int g;
int h;
int i;
int j;
int k;
int l;
Cytron_PS2Shield ps2(2, 3); // SoftwareSerial: Rx and Tx pin
//Cytron_PS2Shield ps2; // HardwareSerial, note: 
//int pwm=5;
//int dir=8;

void setup()
{
  //pinMode(5,OUTPUT);
  //pinMode(8,OUTPUT);
  ps2.begin(9600); // This baudrate must same with the jumper setting at PS2 shield
  Serial.begin(9600); // Set monitor baudrate to 9600
}

void loop()
{
    a=ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS);
    b=ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS);
    c=ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS);
    d=ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS);
    e=ps2.readButton(PS2_JOYSTICK_LEFT_UP);
    f=ps2.readButton(PS2_JOYSTICK_LEFT_DOWN);
    g=ps2.readButton(PS2_JOYSTICK_LEFT_LEFT);
    h=ps2.readButton(PS2_JOYSTICK_LEFT_RIGHT);
    i=ps2.readButton(PS2_JOYSTICK_RIGHT_UP);
    j=ps2.readButton(PS2_JOYSTICK_RIGHT_DOWN);
    k=ps2.readButton(PS2_JOYSTICK_RIGHT_LEFT);
    l=ps2.readButton(PS2_JOYSTICK_RIGHT_RIGHT);

  if(a==0)
  {
    Serial.println("JOYSTICK_LEFT_X_AXIS");
  }
  else if(b==0)
  {
    Serial.println("JOYSTICK_LEFT_Y_AXIS");
  }
  else if(c==0)
  {
    Serial.println("JOYSTICK_RIGHT_X_AXIS");
  }
  else if(d==0)
  {
    Serial.println("JOYSTICK_RIGHT_Y_AXIS");
  }
  else if(e==0)
  {
    Serial.println("PS2_JOYSTICK_LEFT_UP");
  }
  else if(f==0)
  {
    Serial.println("PS2_JOYSTICK_LEFT_DOWN");
  }
  else if(g==0)
  {
    Serial.println("PS2_JOYSTICK_LEFT_LEFT");
  }
  else if(h==0)
  {
    Serial.println("PS2_JOYSTICK_LEFT_RIGHT");
  }
  else if(i==0)
  {
    Serial.println("PS2_JOYSTICK_RIGHT_UP");
  }
  else if(j==0)
  {
    Serial.println("PS2_JOYSTICK_RIGHT_DOWN");
  }
  else if(k==0)
  {
    Serial.println("PS2_JOYSTICK_RIGHT_LEFT");
  }
  else if(l==0)
  {
    Serial.println("PS2_JOYSTICK_RIGHT_RIGHT");
  }
}
