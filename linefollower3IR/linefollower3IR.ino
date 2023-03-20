//#define motor_speed=70;
void setup() 
{
  pinMode(10,INPUT);//right IR
  pinMode(12,INPUT);//left IR
  pinMode(11,INPUT);//Middle IR
  pinMode(4,OUTPUT);//left motor m1
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);//right motor m2
  pinMode(7,OUTPUT);
  pinMode(9,OUTPUT);//M2 en
  pinMode(3,OUTPUT);//M1 en
  Serial.begin(9600);
}

void loop() 
{
  int ls=digitalRead(10);
  int rs=digitalRead(12);
  int md=digitalRead(11);
  //if(ls==LOW && rs==LOW && md==LOW)//motor wil stop working
  //{
    //digitalWrite(4,LOW);
    //digitalWrite(5,LOW);
    //digitalWrite(6,LOW);
    //digitalWrite(7,LOW);
    //analogWrite(3,0);
    //analogWrite(9,0);
    //Serial.println("stop");
  //}
  if(ls==HIGH && md==HIGH && rs==LOW)//RIGHT TURN
  {
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    analogWrite(3,100);
    analogWrite(9,50);
    Serial.println("right");
  }
  else if(ls==HIGH && md==LOW && rs==LOW)//rIGHT TURN
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    analogWrite(3,100);
    analogWrite(9,0);
    Serial.println("right");
  }
  else if(ls==LOW && md==HIGH && rs==HIGH)//LEFT TURN
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    analogWrite(3,0);
    analogWrite(9,100);
    Serial.println("left");
  }
  else if(ls==LOW && md==LOW && rs==HIGH)//LEFT TURN
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    analogWrite(3,0);
    analogWrite(9,100);
    Serial.println("left");
  }
  else if(ls==HIGH && md==HIGH && rs==HIGH)//FORWAED
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    analogWrite(3,100);
    analogWrite(9,100);
    Serial.println("forward");
  }
 /* else if(ls==LOW && md==HIGH && rs==LOW)//FORWAED
  {
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    analogWrite(3,100);
    analogWrite(9,100);
    Serial.println("forward");
  }*/
//  else if(ls==LOW && md==HIGH && rs==HIGH)
//  {
//    digitalWrite(4,LOW);
//    digitalWrite(5,HIGH);
//    digitalWrite(6,LOW);
//    digitalWrite(7,HIGH);
//    analogWrite(3,100);
//    analogWrite(9,100);
//    Serial.println("SHARP RIGHT TURN");
//  }
}
