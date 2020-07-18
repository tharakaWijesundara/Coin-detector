#include <Servo.h>
Servo s;
void setup() {
  // put your setup code here, to run once:
s.attach(27);
}

void loop() {
  // put your main code here, to run repeatedly:
s.write(10);
}
