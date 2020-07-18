#include <Servo.h>
Servo arm_mag, arm_lift, water_lift;
int init_arm_lift = 0;
void setup() {
  Serial.begin(9600);
  arm_mag.attach(10);
  arm_lift.attach(11);
  //water_lift.attach(A7);

  //arm_mag.write(0);
  arm_lift.write(init_arm_lift);


  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  arm_mag.write(0);
}

void loop() {

if (Serial.available()) {
  char input = Serial.read();
  if ( input == 'c') {
    for (int i = init_arm_lift; i <= 120; i++) {
      arm_lift.write(i);
      delay(4);
    }

  } else if (input == 'u') {
    for (int i = 120; i >= 60; i--) {
      arm_lift.write(i);
      delay(4);
    }
  } else if (input == 'l') {
    for (int i = 60; i <= 120; i++) {
      arm_lift.write(i);
      delay(4);
    }

  } else if (input == 'f') {
    for (int i = 60; i >= 0; i--) {
      arm_lift.write(i);
      delay(4);
    }
  } else if (input == 'r') {
    analogWrite(A2, 255);
    analogWrite(A1, 0);
    analogWrite(A0, 0);
  } else if (input == 'g') {
    analogWrite(A1, 255);
    analogWrite(A0, 0);
    analogWrite(A2, 0);
  } else if (input == 'b') {
    analogWrite(A0, 255);
    analogWrite(A1, 0);
    analogWrite(A2, 0);
  } else if (input == 'p') {
    analogWrite(A2, 255);
    analogWrite(A0, 255);
    analogWrite(A1, 0);
  } else if (input == 'y') {
    analogWrite(A2, 255);
    analogWrite(A1, 255);
    analogWrite(A0, 0);
  } while (Serial.available()) {
    Serial.read();
  }
}

}
