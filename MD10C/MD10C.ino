int pwm=3;
int dir=4;
void setup(){
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}
void loop()
{
  digitalWrite(4,HIGH);
  analogWrite(3,100);
  delay(10000);
  digitalWrite(4,LOW);
  analogWrite(3,100);
  delay(10000);

 
}
