int ir=7;
int x;
void setup() 
{
    Serial.begin(9600);
    pinMode(7,INPUT);
    pinMode(13,OUTPUT);
}
void loop()
{
    x=digitalRead(ir);
    Serial.println(x);
    delay(100);
    if(x==1)
    {
      digitalWrite(13,LOW);
    }
    else
    {
      digitalWrite(13,HIGH);
    }
}
