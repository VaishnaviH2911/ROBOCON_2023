#define IR_SENSOR_RIGHT 12
#define IR_SENSOR_MIDDLE 11
#define IR_SENSOR_LEFT 10

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

  pinMode(IR_SENSOR_RIGHT,INPUT);
  pinMode(IR_SENSOR_MIDDLE,INPUT);
  pinMode(IR_SENSOR_LEFT,INPUT);

}

void loop() 
{
  int rightIRSensorValue=digitalRead(IR_SENSOR_RIGHT);
  int middleIRSensorValue=digitalRead(IR_SENSOR_MIDDLE);
  int leftIRSensorValue=digitalRead(IR_SENSOR_LEFT);

  if (rightIRSensorValue==LOW && middleIRSensorValue==LOW && leftIRSensorValue==LOW)
  {
    forward();
    Serial.println("0 0 0 (forward)"); 
  }
  if (rightIRSensorValue==LOW && middleIRSensorValue==LOW && leftIRSensorValue==HIGH)
  {
    left();
    Serial.println("0 0 1 (left)");
  }
  if (rightIRSensorValue==LOW && middleIRSensorValue==HIGH && leftIRSensorValue==LOW)
  {
    forward();
    Serial.println("0 1 0 (forward)");
  }















  
  if (rightIRSensorValue==LOW && middleIRSensorValue==HIGH && leftIRSensorValue==HIGH)
  {
    left();
    Serial.println("0 1 1 (left)");
  }
  if (rightIRSensorValue==HIGH && middleIRSensorValue==LOW && leftIRSensorValue==LOW)
  {
    right();
    Serial.println("1 0 0 (right)");

  }
  if (rightIRSensorValue==HIGH && middleIRSensorValue==LOW && leftIRSensorValue==HIGH)
  {
    forward();
    Serial.println("1 0 1 (forward)");
  }
  if (rightIRSensorValue==HIGH && middleIRSensorValue==HIGH && leftIRSensorValue==LOW)
  {
    right();
    Serial.println("1 1 0 (right)");
  }
  if (rightIRSensorValue==HIGH && middleIRSensorValue==HIGH && leftIRSensorValue==HIGH)
  {
    forward();
    Serial.println("1 1 1 (forward)");
  }

}

void forward()
{
  digitalWrite(leftMotorPin1,LOW);//motor 1
  digitalWrite(leftMotorPin2,HIGH);
  digitalWrite(rightMotorPin1,LOW);//motor 2
  digitalWrite(rightMotorPin2,HIGH);

  analogWrite(enableLeftMotor,100);
  analogWrite(enableRightMotor,100);

}
void left()
{
  digitalWrite(leftMotorPin1,HIGH);//Motor 1
  digitalWrite(leftMotorPin2,LOW);
  digitalWrite(rightMotorPin1,LOW);//motor 2
  digitalWrite(rightMotorPin2,HIGH);

  analogWrite(enableLeftMotor,250);
  
  analogWrite(enableRightMotor,250);

}
void right()
{
  digitalWrite(leftMotorPin1,LOW);//MOtor 1
  digitalWrite(leftMotorPin2,HIGH);
  digitalWrite(rightMotorPin1,HIGH);//Motor 2
  digitalWrite(rightMotorPin2,LOW);

  analogWrite(enableLeftMotor,250);
  analogWrite(enableRightMotor,250);

}
void backward()
{
   digitalWrite(leftMotorPin1,HIGH);//Motor 1
  digitalWrite(leftMotorPin2,LOW);
  digitalWrite(rightMotorPin1,HIGH);//Motor 2
  digitalWrite(rightMotorPin2,LOW);

  analogWrite(enableLeftMotor,100);
  analogWrite(enableRightMotor,100);

}
void stop()
{
  digitalWrite(leftMotorPin1,LOW);//motor 1
  digitalWrite(leftMotorPin2,LOW);
  digitalWrite(rightMotorPin1,LOW);//motor 2
  digitalWrite(rightMotorPin2,LOW);

  analogWrite(enableLeftMotor,0);
  analogWrite(enableRightMotor,0);


}
