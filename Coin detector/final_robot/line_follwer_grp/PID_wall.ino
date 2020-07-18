void wall_fol() {
  int PID_val_left_w;
  int PID_val_right_w;
  int motor_val_w;
  int prop_w = error_cal_w();

  int deri_w = prop_w - previous_prp_w;
  ing_w = ing_w + prop_w;
  previous_prp = prop_w;

  motor_val_w = prop_w * kp_w + deri_w * kd_w + ing_w * ki_w;
  //Serial.println(motor_val_w);
  if (motor_val_w >= 0) {
    if ((def_speed_w + motor_val_w) >= 255) {
      PID_val_left_w = 255;
    } else {
      PID_val_left_w = def_speed_w + motor_val_w;
    }

    if ((def_speed_w - motor_val_w) <= -255) {
      PID_val_right_w = -255;
    } else {
      PID_val_right_w = def_speed_w - motor_val_w;
    }

  } else if (motor_val_w < 0) {

    if ((def_speed_w - motor_val_w) >= 255) {
      PID_val_right_w = 255;
    } else {
      PID_val_right_w = def_speed_w - motor_val_w;
    }

    if ((def_speed_w + motor_val_w) <= -255) {
      PID_val_left_w = -255;
    } else {
      PID_val_left_w = def_speed_w + motor_val_w;
    }
  }
  motor_drive('L', PID_val_left_w);
  motor_drive('R', PID_val_right_w);
  delay(10);
}

int error_cal_w() {
  int val_left = 0;
  int val_right = 0;

  read_sensors_w();
  val_left = wall_dist[0] * (-1);
  val_right = wall_dist[2];
  if (val_left < -10) {
    val_left = -10;
  }
  if (val_right > 10) {
    val_right = 10;
  }
  return 9 * (val_right + val_left);
  delay(10);
}


