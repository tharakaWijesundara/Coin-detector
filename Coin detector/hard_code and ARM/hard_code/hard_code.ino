#include <Servo.h>
Servo water, arm_mag, arm_lift;

//Right_Motor
#define enA 7;
#define in1 6;
#define in2 5;

//Left_Motor
#define enB 2;
#define in3 3;
#define in4 4;

void setup() {
  // put your setup code here, to run once:
  for (int pin = 2; pin <= 7; pin++) {
    pinMode(pin, OUTPUT);
  }
  water.attach(10);
  arm_mag.attach(9);
  arm_lift.attach(11);

  arm_lift.write(10);
  arm_mag.write(5);
  delay(5000);

}

void loop() {
  // put your main code here, to run repeatedly:
  // moving(1,200);
  // delay(2500);
  // moving(3,200);
  // delay(400);
  // moving(1,200);
  // delay(500);
  arm_lift.write(150);
  delay(800);
  moving(1, 135);
  delay(1000);
  moving(5, 0);
  delay(100);
  for (int i = 135; i > 121; i--) {
    arm_lift.write(i);
    delay(5);
  }
  moving(1, 135);
  delay(2000);
  moving(5, 0);
  delay(100);
  arm_lift.write(135);
  delay(500);
  arm_mag.write(90);
  delay(200);
  moving(1, 135);
  delay(1000);
  moving(5, 0);
  delay(100);
  while (true) {

  }




}

void moving(int n, int speedVal) {
  switch (n) {
    case 1://forward
      motor_drive('L', speedVal);
      motor_drive('R',  speedVal);
      break;
    case 2://turn_Right
      motor_drive('L', speedVal);
      motor_drive('R', -speedVal);
      break;
    case 3://turn_Left
      motor_drive('L', -speedVal);
      motor_drive('R',  speedVal);
      break;
    case 4://backward
      motor_drive('L',  -speedVal);
      motor_drive('R', -speedVal);
      break;
    case 5://stop
      motor_drive('L', 0);
      motor_drive('R', 0);
      break;
  }
}
void motor_drive(char motor, int spd) {
  int spd_pin;
  int dir1;
  int dir2;

  if (motor == 'R') {
    spd_pin = enA;
    dir1 = in1;
    dir2 = in2;
  }
  else if (motor == 'L') {
    spd_pin = enB;
    dir1 = in3;
    dir2 = in4;
  }
  else {
    return;
  }

  if (spd == 0) {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
  }
  else if (spd < 0) {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
  }
  else if (spd > 0) {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
  }
  if (spd <= 0) {
    spd = -spd;
  } else {
    spd = spd;
  }
  analogWrite(spd_pin, spd);
}

void color_line() {

}

