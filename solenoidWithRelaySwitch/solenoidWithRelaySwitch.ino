/*Solenoid valves are control units which, when electrically energized or de-energized, either shut off or allow fluid flow. 
The actuator inside a solenoid valve takes the form of an electromagnet. 
When energized, a magnetic field builds up, which pulls a plunger or pivoted armature against the action of a spring.*/
const int RELAY_PIN = 3;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
}
void loop() {
  digitalWrite(RELAY_PIN, HIGH);
  delay(2000);
  digitalWrite(RELAY_PIN, LOW);
  delay(2000);
}
