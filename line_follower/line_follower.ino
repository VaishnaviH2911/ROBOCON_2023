//#define motor_speed=70;
void setup() 
{
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(4,OUTPUT);//left motor m1
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);//right motor m2
  pinMode(7,OUTPUT);
  pinMode(3,OUTPUT);//M1
  pinMode(9,OUTPUT);//M2
}

void loop() 
{
  int ls=digitalRead(10);
  int rs=digitalRead(11);

  if(ls==LOW && rs==LOW)//motor wil stop working
  {
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    analogWrite(3,0);
    analogWrite(9,0);
  }
  if(ls==LOW && rs==HIGH)//LEFT TURN
  {
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    analogWrite(3,70);
    analogWrite(9,30);
  }
  if(ls==HIGH && rs==LOW)//RIGHT TURN
  {
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    analogWrite(3,30);
    analogWrite(9,70);
  }
  if(ls==HIGH && rs==HIGH)//FORWAED
  {
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    analogWrite(3,70);
    analogWrite(9,70);
  }
  
}
