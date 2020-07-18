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
}

void loop() {
  // put your main code here, to run repeatedly:
moving(1,220);
delay(20);

  //


}

void moving(int n, int speedVal) {
  switch (n) {
    case 1://forward
      motor_drive('L', speedVal+20);
      motor_drive('R',  speedVal );
      break;
    case 2://turn_left
      motor_drive('L', -speedVal);
      motor_drive('R',  speedVal);
      break;
    case 3://turn_right
      motor_drive('L', speedVal);
      motor_drive('R', -speedVal);
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

  if (motor == 'L') {
    spd_pin = enA;
    dir1 = in1;
    dir2 = in2;
  }
  else if (motor == 'R') {
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
void go_r() {
  moving(1, 200);
  delay(450);
  moving(3, 250);
  delay(800);
  moving(1, 200);
  delay(700);
  moving(2, 250);
  delay(400);
  moving(1, 200);
  delay(900);
  moving(2, 250);
  delay(400);
  moving(1, 200);
  delay(650);
  moving(3, 250);
  delay(650);
}
void go_b() {
  moving(1, 200);
  delay(450);
  moving(2, 250);
  delay(400);
  moving(1, 200);
  delay(650);
  moving(3, 250);
  delay(700);
  moving(1, 200);
  delay(900);
  moving(3, 250);
  delay(550);
  moving(1, 200);
  delay(750);
  moving(2, 250);
  delay(400);
}
void go_g(){
  moving(1, 200);
  delay(2000);
}

