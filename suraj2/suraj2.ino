#define IRR 12
#define IRM 11
#define IRL 10

//motor right
int enableRightMotor=9;
int rightMotorPin1=7;
int rightMotorPin2=6;

//left motor
int enableLeftMotor=3;
int leftMotorPin1=4;
int leftMotorPin2=5;

void setup() 
{
  Serial.begin(9600);
  pinMode(enableRightMotor,OUTPUT);
  pinMode(rightMotorPin1,OUTPUT);
  pinMode(rightMotorPin2,OUTPUT);
  pinMode(enableLeftMotor,OUTPUT);
  pinMode(leftMotorPin1,OUTPUT);
  pinMode(leftMotorPin2,OUTPUT);

  pinMode(IRR,INPUT);
  pinMode(IRM,INPUT);
  pinMode(IRL,INPUT);

}

void loop() 
{
  int rs=digitalRead(IRR);
  int ms=digitalRead(IRM);
  int ls=digitalRead(IRL);
  
  if(rs==LOW && ms==HIGH && LS==LOW)
  {
    forward();
    Serial.println("forward");
  }
  if(rs==

  
