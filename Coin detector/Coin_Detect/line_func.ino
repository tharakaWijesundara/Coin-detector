void moving(int n, int speedVal) {
  switch (n) {
    case 1://forward
      motor_drive('L',  speedVal);
      motor_drive('R',  speedVal);
      break;
    case 2://turn_Right
      motor_drive('L',  speedVal);
      motor_drive('R', -speedVal);
      break;
    case 3://turn_Left
      motor_drive('L', -speedVal);
      motor_drive('R',  speedVal);
      break;
    case 4://backward
      motor_drive('L',  -speedVal);
      motor_drive('R',  -speedVal);
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
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
  }
  else if (spd > 0) {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
  }
  if (spd <= 0) {
    spd = -spd;
  } else {
    spd = spd;
  }
  analogWrite(spd_pin, spd);
}

void read_sensors() {
  for (int i = 0; i < 10; i++) {
    if ((i != 0) && (i != 9)) {
      value[i] = !(digitalRead(sensor_name[i]));
    }
    else {
      value[i] = !(digitalRead(sensor_name[i]));
    }
  }
}
int error_cal() {
  int val_left = 0;
  int val_right = 0;

  read_sensors();
  for (int i = 1; i < 5; i++) {
    val_left += value[i] * (i - 5) * 250;
  }
  for (int i = 5; i < 9; i++) {
    val_right += value[i] * (i - 4) * 250;
  }
  return (val_right + val_left);
}

int error_cal_d() {
  int val_left = 0;
  int val_right = 0;


  read_sensors();
  for (int i = 0; i < 5; i++) {
    val_left += value[i] * (i - 5) * 250;
  }
  for (int i = 5; i < 10; i++) {
    val_right += value[i] * (i - 4) * 250;
  }
  return (val_right + val_left);
}
void line_fol() {
  int PID_val_left;
  int PID_val_right;
  int motor_val;
  int prop = error_cal();
  Serial.println("*E" + String(prop) + "*");
  int deri = prop - previous_prp;
  ing = ing + prop;
  previous_prp = prop;

  motor_val = prop * kp + deri * kd + ing * ki;

  if (prop >= 0) {
    if ((def_speed + motor_val) >= 255) {
      PID_val_right = 255;
    } else {
      PID_val_right = def_speed + motor_val;
    }

    if ((def_speed - motor_val) <= -255) {
      PID_val_left = -255;
    } else {
      PID_val_left = def_speed - motor_val;
    }

  } else if (prop < 0) {

    if ((def_speed - motor_val) >= 255) {
      PID_val_left = 255;
    } else {
      PID_val_left = def_speed - motor_val;
    }

    if ((def_speed + motor_val) <= -255) {
      PID_val_right = -255;
    } else {
      PID_val_right = def_speed + motor_val;
    }
  }
  motor_drive('L', PID_val_left);
  motor_drive('R', PID_val_right);
  delay(10);

}
void dotted_follow() {
  int PID_val_left;
  int PID_val_right;
  int motor_val;
  int prop = error_cal_d();
  //Serial.println(prop);
  int deri = prop - previous_prp_d;
  ing_d = ing_d + prop;
  previous_prp_d = prop;


  motor_val = prop * kp_d + deri * kd_d + ing_d * ki_d;

  if (prop >= 0) {
    if ((def_speed_d + motor_val) >= 255) {
      PID_val_right = 255;
    } else {
      PID_val_right = def_speed_d  + motor_val;
    }

    if ((def_speed_d  - motor_val) <= -255) {
      PID_val_left = -255;
    } else {
      PID_val_left = def_speed_d  - motor_val;
    }

  } else if (prop < 0) {

    if ((def_speed_d  - motor_val) >= 255) {
      PID_val_left = 255;
    } else {
      PID_val_left = def_speed_d  - motor_val;
    }

    if ((def_speed_d  + motor_val) <= -255) {
      PID_val_right = -255;
    } else {
      PID_val_right = def_speed_d  + motor_val;
    }
  }
  motor_drive('L', PID_val_left);
  motor_drive('R', PID_val_right);
  delay(5);
  pre_error = prop;

}
void junctionMaze(char side) {
  int left_state = 1;
  int center_state = 1;  //1-white  0-line 2-square
  int right_state = 1;
  moving(5, 0);
  delay(20);


  while (value[0] == 1 && value[9] == 1) {
    read_sensors();
    if (value[0] == 0) {
      left_state = 0;
    }
    if (value[9] == 0) {
      right_state = 0;
    }

    moving(1, 120);
    delay(5);
  }

  float time1 = millis();
  float timeDif;
  while ((value[0] == 0 || value[9] == 0) && timeDif <= 250) {
    read_sensors();
    if (value[0] == 0) {
      left_state = 0;
    }
    if (value[9] == 0) {
      right_state = 0;
    }

    moving(1, 120);
    //Serial.println("2");
    //delay(5);

    timeDif = millis() - time1;
  }
  if ( value[1] == 0 && value[2] == 0 && value[3] == 0 && value[4] == 0 && value[5] == 0 && value[6] == 0 && value[7] == 0 && value[8] == 0 ) {
    center_state = 2;
  } else if ( value[1] == 0 || value[2] == 0 || value[3] == 0 || value[4] == 0 || value[5] == 0 || value[6] == 0 || value[7] == 0 || value[8] == 0 ) {
    center_state = 0;
  }
  if (side == 'L') {
    turningL(left_state, center_state, right_state);
  } else {
    turningR(left_state, center_state, right_state);
  }
}


void dotted_turn() {
  if (pre_error > 0) {
    while (value[0] == 1 && value[1] == 1 && value[2] == 1 && value[3] == 1 && value[4] == 1 && value[5] == 1 && value[6] == 1 && value[7] == 1 && value[8] == 1 && value[9] == 1) {
      read_sensors();
      //Serial.println("DL");
      moving(3, 250);
      delay(10);
      moving(1, 210);
      delay(6);
    }
  } else if (pre_error < 0) {
    while (value[0] == 1 && value[1] == 1 && value[2] == 1 && value[3] == 1 && value[4] == 1 && value[5] == 1 && value[6] == 1 && value[7] == 1 && value[8] == 1 && value[9] == 1) {
      read_sensors();
      //Serial.println("DR");
      moving(2, 250);
      delay(10);
      moving(1, 200);
      delay(6);
    }
  } else {
    moving(1, 200);
    delay(3);
  }
}
void serial() {
  while (!(Serial.available()));
  char c = Serial.read();

  if ( c == '0') {
    state = 0;
  } else if (c == 'P') {
    EEPROM.put(0, Serial.parseFloat());
  } else if (c == 'D') {
    EEPROM.put(20, Serial.parseFloat());
  } else if (c == 'I') {
    EEPROM.put(40, Serial.parseFloat());
  } else {
    state = 1;
  }
  kp = EEPROM.get(0, kp);
  kd = EEPROM.get(20, kd);
  ki = EEPROM.get(40, ki);

}


void stationary(int val) {
  Serial.println("SQUARE");
  read_sensors();
  while (value[1] == 1 && value[8] == 1) {
    read_sensors();
    line_fol();
  }
  if (val % 2 == 0) {
    squareFollow();
  } else {
    moving(1, 180);
    delay(500);
    moving(3, 255);
    delay(1000);

    while (value[0] == 1 && value[9] == 1) {
      read_sensors();
      line_fol();
    }
    moving(1, 180);
    delay(500);
    moving(2, 255);
    delay(1000);
    while (value[0] == 1 && value[9] == 1) {
      read_sensors();
      line_fol();
    }
    moving(1, 180);
    delay(500);
    moving(3, 255);
    delay(1000);
    while (value[1] == 0 ||
           value[2] == 0 ||
           value[3] == 0 ||
           value[4] == 0 ||
           value[5] == 0 ||
           value[6] == 0 ||
           value[7] == 0 ||
           value[8] == 0 ) {
      read_sensors();
      line_fol();
    }
    digitalWrite(11, HIGH);
  }

}
