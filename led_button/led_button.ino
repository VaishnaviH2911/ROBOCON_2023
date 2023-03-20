const int x=8;
bool pressed=true;
void setup() 
{
 Serial.begin(9600);
 pinMode(7,OUTPUT);
 pinMode(8,INPUT);
}
void loop()
{
  bool currentstate=digitalRead(x);
  if(currentstate==true)
  {
    Serial.println("pressed");
    digitalWrite(7,HIGH);
    //delay(2000);
  }
  else
  {
    Serial.println("not presssed");
    digitalWrite(7,LOW);
    //delay(2000);
  }
}
