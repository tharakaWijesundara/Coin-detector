void moving(int n, int speedVal) {
  switch (n) {
    case 1://forward
      motor_drive('L', speedVal+20);
      motor_drive('R',  speedVal);
      break;
    case 2://turn_Left
      motor_drive('L', -speedVal);
      motor_drive('R', speedVal);
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
int error_cal() {
  int val_left = 0;
  int val_right = 0;

  read_sensors();
  val_left = wall_dist[0] * (-1);
  val_right = wall_dist[2];
  if (val_left < -20) {
    val_left = -20;
  }
  if (val_right > 20) {
    val_right = 20;
  }
  return 9 * (val_right + val_left);
  delay(10);
}


