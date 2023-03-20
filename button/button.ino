//setup pins
const int Button_Pin=8;
bool pressed=true;
void setup() 
{
//setup pinmodes
 Serial.begin(9600);
 pinMode(Button_Pin,INPUT_PULLUP);
}
void loop()
{
 bool currentState=digitalRead(Button_Pin);
 if(currentState==true)
 {
     Serial.println("button pressed");   
     delay(200);
 }
 else
 {
    Serial.println("button not pressed");
 }

}
