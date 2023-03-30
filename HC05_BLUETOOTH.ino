#include<SoftwareSerial.h>

/* Create object named bt of the class SoftwareSerial */
SoftwareSerial bt(2, 3); /* (Rx,Tx) */
int state;
int state2;
int flag = 0;
int a = 10;
void setup() {
  bt.begin(9600); /* Define baud rate for software serial communication */
  Serial.begin(9600); /* Define baud rate for serial communication */

}

void loop() {

  //      if (bt.available()) /* If data is available on serial port */
  //      {
  //       Serial.println(bt.read()); /* Print character received on to the serial monitor */
  //      }

  //    if (Serial.available()) /* If data is available on serial port */
  //    {
  //      int c=Serial.parseInt();
  //      Serial.print(c);
  //     bt.print(c); /* Print character received on to the serial monitor */
  //    }
  //      c=Serial.parseInt();
  //      Serial.println(c);
  //      bt.write(c); /* Print character received on to the serial monitor */
  //    state=Serial.parseInt();
  //    if(state!=0){
  //    state2=state;
  //    }
  //    Serial.println(state2);
  //    bt.write(state2);
  //  for (int i = 0; i <= 10000; i++)
  //  {
  //    bt.write(i);
  //    delay(400);
  //  }



  // if (bt.available())
  // flag = bt.read();
  // if (flag==1)
  // {
  //
  //   Serial.println("LED On");
  // }
  // else if (flag == 0)
  // {
  //
  //   Serial.println("LED Off");
  // }

     bt.println(a);

//  if (bt.available()) /* If data is available on serial port */
//  {
//    bt.println("hello world"); /* Print character received on to the serial monitor */
//  }



}
