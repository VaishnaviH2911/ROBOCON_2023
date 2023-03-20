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

int a;//up
int b;//down
int c;//left
int d;//right
int e;
int f;
int g;
int h;
int i;
int j;
int k;
int l;
int m;
int n;
int o;
int p;
int q;
int r;
int s;
int t;

Cytron_PS2Shield ps2(2, 3); // SoftwareSerial: Rx and Tx pin
//Cytron_PS2Shield ps2; // HardwareSerial, note: 

void setup()
{
  ps2.begin(9600); // This baudrate must same with the jumper setting at PS2 shield
  Serial.begin(9600); // Set monitor baudrate to 9600
}

void loop()
{
  a=ps2.readButton(PS2_UP);
  b=ps2.readButton(PS2_DOWN);
  c=ps2.readButton(PS2_LEFT);
  d=ps2.readButton(PS2_RIGHT);
  e=ps2.readButton(PS2_SELECT);
  f=ps2.readButton(PS2_JOYSTICK_LEFT);
  g=ps2.readButton(PS2_JOYSTICK_RIGHT);
  h=ps2.readButton(PS2_START);
  //i=ps2.readButton(PS2_UP);
  //j=ps2.readButton(PS2_RIGHT);
  //k=ps2.readButton(PS2_DOWN);
  //l=ps2.readButton(PS2_LEFT);
  m=ps2.readButton(PS2_LEFT_2);
  n=ps2.readButton(PS2_RIGHT_2);
  o=ps2.readButton(PS2_LEFT_1);
  p=ps2.readButton(PS2_RIGHT_1);
  q=ps2.readButton(PS2_TRIANGLE);
  r=ps2.readButton(PS2_CIRCLE);
  s=ps2.readButton(PS2_CROSS);
  t=ps2.readButton(PS2_SQUARE);
  if(a==0)
  {
    Serial.println("Forward");
  }
  if(b==0)
  {
    Serial.println("Backward");
  }
  if(c==0)
  {
    Serial.println("Left");
  }
  if(d==0)
  {
    Serial.println("Right");
  }
  if(e==0)
  {
    Serial.println("Select");
  }
  if(f==0)
  {
    Serial.println("Joystick_left");
  }
  if(g==0)
  {
    Serial.println("Joystick right");
  }
  if(h==0)
  {
    Serial.println("start");
  }
  /*if(i==0)
  {
    Serial.println("up");
  }
  if(j==0)
  {
    Serial.println("right");
  }
  if(k==0)
  {
    Serial.println("Down");
  }
  if(l==0)
  {
    Serial.println("Left");
  }*/
  if(m==0)
  {
    Serial.println("left2");
  }
  if(n==0)
  {
    Serial.println("right2");
  }
  if(o==0)
  {
    Serial.println("Left1");
  }
  if(p==0)
  {
    Serial.println("Right1");
  }
  if(q==0)
  {
    Serial.println("Triangle");
  }
  if(r==0)
  {
    Serial.println("Circle");
  }
  if(s==0)
  {
    Serial.println("cross");
  }
  if(t==0)
  {
    Serial.println("Square");
  }
}
