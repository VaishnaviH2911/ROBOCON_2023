volatile long temp, counter = 0;
const int R =3;
const int N = 1200;
const float pi = 3.14;
float distance = 0;
#define pin1=2;
#define pin2=3;
void setup() {
  Serial.begin (9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(0, ai0, RISING);
  attachInterrupt(1, ai1, RISING);
}

void loop() {
  // Send the value of counter
  if ( counter != temp ) {
    distance = ((2 * pi * R) / N) * counter;
    //Serial.println("Distance:in cm");
    //Serial.println (distance);
    Serial.println (counter);
    temp = counter;

  }
}
void ai0() {
  if (digitalRead(3) == LOW) {
    counter++;
  } else {
    counter--;
  }
}

void ai1() {
  if (digitalRead(2) == LOW) {
    counter--;
  } else {
    counter++;
  }
}
