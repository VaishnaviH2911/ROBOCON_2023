//ir connection
int i;
int s1=2;
int s2=3;
int s3=4;

int s4=5;
int s5=6;
int s6=7;
int s7=8;
int s8=9;

//motor driver connection
int IN1=A0;//LEFT MOTOR
int IN2=A1;
int IN3=A2;//RIGHT MOTOR
int IN4=A3;

int EN1=10;
int EN2=11;

void setup()
{
  //sensor pins
  for(i=2;i<=9;i++)
  {
    pinMode(i,INPUT);
  }
  //left motor
  pinMode(EN1,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  //RIGHT MOTOR
  pinMode(EN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  //reading sensor array values
  s1=digitalRead(2);
  s2=digitalRead(3);
  s3=digitalRead(4);
  s4=digitalRead(5);
  s5=digitalRead(6);
  s6=digitalRead(7);
  s7=digitalRead(8);
  s8=digitalRead(9);
  //forward
  if(s1==0 && s2==0 && s3==0 && s4==1 && s5==1 && s6==0 && s7==0)
  {
    forward();
  }
  //right
  if(s1==0 && s2==0 && s3==0 && s4==0 && s5==0 && s6==1 && s7==1 && s8==1 || s1==0 && s2==0 && s3==0 && s4==0 && s5==0 s6==1 && s7==1 s8==0 || s1==0 && s2==0 && s3==0 && s4==0 && s5==0 s6==1 s7==1 && s8==1)
  {
    right();
  }
  //left
  if(s1==1 && s2==1 && s3==1 && s4==0 && s5==0 && s6==0 && s7==0 && s8==0 || s1==1 && s2==1 s3==0 && s4==0 && s5==0 && s6==0 && s7==0 && s8==0 || s1==0 && s2==1 && s3==1 && s4==0 && s5==0 && s6==0 && s7==0 && s8==0 )
  {
    left();
  } 
  if(s1==0 && s2==0 && s3==0 && s4==0 && s5==0 && s6==0 && s7==0 && s8==0)
  {
    Stop();
  }
}
void forward()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(EN1,100);
    analogWrite(EN2,100);
    Serial.println("forward");
}
void right()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
    analogWrite(EN1,100);
    analogWrite(EN2,50);
    Serial.println("right");
}
void left()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(EN1,50);
    analogWrite(EN2,100);
    Serial.println("left");
}
void Stop()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(EN1,0);
  analogWrite(EN2,0);
  Serial.println("stop");
}
