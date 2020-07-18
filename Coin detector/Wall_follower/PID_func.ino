void wall_fol() {
  int PID_val_left;
  int PID_val_right;
  int motor_val;
  int prop = error_cal();

  int deri = prop - previous_prp;
  ing = ing + prop;
  previous_prp = prop;

  motor_val = prop * kp + deri * kd + ing * ki;
  //Serial.println(motor_val);
  if (motor_val >= 0) {
    if ((def_speed + motor_val) >= 255) {
      PID_val_left = 255;
    } else {
      PID_val_left = def_speed + motor_val;
    }

    if ((def_speed - motor_val) <= -255) {
      PID_val_right = -255;
    } else {
      PID_val_right = def_speed - motor_val;
    }

  } else if (motor_val < 0) {

    if ((def_speed - motor_val) >= 255) {
      PID_val_right = 255;
    } else {
      PID_val_right = def_speed - motor_val;
    }

    if ((def_speed + motor_val) <= -255) {
      PID_val_left = -255;
    } else {
      PID_val_left = def_speed + motor_val;
    }
  }
  motor_drive('L', PID_val_left);
  motor_drive('R', PID_val_right);
  delay(25);
}
