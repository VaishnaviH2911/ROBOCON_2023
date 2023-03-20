//M1
int pwm1=3;
int dir1=4;
////M2
//int pwm2=9;+
//int dir2=8;
void setup(){
  pinMode(pwm1,OUTPUT);
  pinMode(dir1,OUTPUT);
//  pinMode(pwm2,OUTPUT);
//  pinMode(dir2,OUTPUT);
  
}
void loop()
{
  //M1
  digitalWrite(dir1,HIGH);
  analogWrite(pwm1,250);
  delay(200);
  digitalWrite(dir1,LOW);
  analogWrite(pwm1,100);
  delay(200);
//  //M2
//  digitalWrite(dir2,HIGH);
//  analogWrite(pwm2,250);
//  delay(500);
//  digitalWrite(dir2,LOW);
//  analogWrite(pwm2,100);
//  delay(1000);
  
}
