int enA=9;
int in1=8;
int in2=7;
void setup()
{
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
}
void loop() 
{
  //forward
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enA,150);
  delay(3000);
  //backward
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(enA,150);
  delay(3000);
}
