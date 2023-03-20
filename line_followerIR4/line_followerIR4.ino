//Motor one
#define ENA 3
#define IN1 4
#define IN2 5

//Motor two
#define IN3 7
#define IN4 6
#define ENB 9

void setup() {
  //Sensor pins
  pinMode(2,  INPUT);
  pinMode(8,  INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  //Motor one
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  //Motor two
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);

}
void loop() {
  bool rs = digitalRead(12);
  bool mrs = digitalRead(11);
  bool ms = digitalRead(10);
  bool mls = digitalRead(8);
  bool ls=digitalRead(2);

  if(ls==0 && mis==0 && ms==1 && mrs==0 && rs==0)
  {
    forward();
    Serial.println("Forward");
  }
  if(ls==1 && mls==1 && ms==1 && mrs==1 && rs==1)
  {
    forward();
    Serial.println("forward");
  }
  if((ls==1 || mls==1) && ms==1 && mrs==0 && rs==0)
  {
    left();
    Serial.println("left");
  }
  if((ls==0 && mls==0 && ms==1 && (mrs==1 || rs==1))
  {
    right();
    Serial.println("Right");
  }
  if(ls==0 && mls==0 && ms==o && mrs==0 && rs==0)
  {
    Stop();
    Serial.println("Stop");
  }
  if(ls==1 && mls==0 && ms==1 && mrs==0 && rs==0)
  {
    left();
    Serial.println("Left");
  }
  if(ls==0 && mls==0 && ms==1 && mrs==0 && rs==1)
  {
    right();
    Serial.println("Right");
  }
}

void forward() {
  analogWrite(3, 100);
  analogWrite(9, 100);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("forward");
}
void turnright() {
  analogWrite(3,100);
  analogWrite(9,0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("right");
}
void turnleft() {
  analogWrite(3,0);
  analogWrite(9,100);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("left");
}
void Stop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Stop");
}
