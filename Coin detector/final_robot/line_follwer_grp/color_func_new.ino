char color_func_new() {
  int col_arr[3] = {0, 0, 0};
  int redFrequency = 0;
  int greenFrequency = 0;
  int blueFrequency = 0;

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redFrequency = pulseIn(sensorOut, LOW);
  //    Serial.print("R = ");
  //    Serial.print(map(redFrequency, 27, 197, 0, 150));

  col_arr[0] = map(redFrequency, red_low, red_high, 0, 200);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  greenFrequency = pulseIn(sensorOut, LOW);
  //    Serial.print(" G = ");
  //    Serial.print(map(greenFrequency, 27, 190, 0, 150));

  col_arr[1] = map(greenFrequency, green_low, green_high, 0, 200);


  //  Serial.print(" G = ");
  //  Serial.print(greenFrequency);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  blueFrequency = pulseIn(sensorOut, LOW);

  //    Serial.print(" B = ");
  //    Serial.println(map(blueFrequency, 20, 145, 0, 150));
  col_arr[2] = map(blueFrequency, blue_low, blue_high, 0, 200);



  if ((col_arr[0] < 50 && col_arr[1] < 50) || ( col_arr[2] < 50 && col_arr[1] < 50) || (col_arr[0] < 50 && col_arr[2] < 50)) {
    return ;
  } else if ((col_arr[0] > 110 && col_arr[1] > 110) || (col_arr[2] > 110 && col_arr[0] > 110) || (col_arr[2] > 110 && col_arr[1] > 110)) {
    return;
  } else if (col_arr[0] < col_arr[1] && col_arr[0] < col_arr[2]) {
    return 'r';
  } else if (col_arr[1] < col_arr[0] && col_arr[1] < col_arr[2]) {
    return 'g';
  } else if (col_arr[2] < col_arr[1] && col_arr[2] < col_arr[0]) {
    return 'b';
  }
}
void color_line_new() {
  char color_det_arr[30];
  char color;
  int time_fow_c = 0;
  int index = 0;
  while (time_fow_c <= 1000) {
    color = color_func_new();
    color_det_arr[index] = color;
    moving(1, 100);
    delay(50);
    time_fow_c += 50;
    index++;
  }
  //Serial.println('b');
  color = detect_color_new(color_det_arr);
  //color = 'g';
  Serial.println(color);

  while (line_state() != 3) {
    moving(4, 120);
    delay(20);
  }
  break_func();
  Serial.println('u');
  delay(900);
  if (color == 'r') {
    moving(1, 200);
    delay(400);
    moving(3, 250);
    delay(430);
    moving(1, 200);
    delay(600);
    moving(2, 250);
    delay(420);
    moving(1, 200);
    delay(900);
    break_func();
    Serial.println('l');
    delay(1500);
    Serial.println('f');
    delay(1500);
    moving(1, 200);
    delay(80);
    moving(2, 250);
    delay(400);
    moving(1, 200);
    delay(680);
    moving(3, 250);
    delay(450);
    break_func();
    //    moving(1, 200);
    //    delay(150);

  }
  else if (color == 'g') {
    moving(3, 200);
    delay(10);
    motor_drive('L', 200 + 25);
    motor_drive('R',  200);
    delay(2200);
    break_func();
    Serial.println('l');
    delay(1500);
    Serial.println('f');
    delay(1500);
    moving(1, 200);
    delay(600);
    break_func();
  }
  else if (color == 'b') {
    moving(1, 200);
    delay(400);
    break_func();
    moving(2, 250);
    delay(480);
    break_func();
    moving(1, 200);
    delay(800);
    break_func();
    moving(3, 250);
    delay(500);
    break_func();
    moving(1, 200);
    delay(680);
    break_func();
    Serial.println('l');
    delay(1500);
    Serial.println('f');
    delay(1500);
    moving(1, 200);
    delay(170);
    moving(3, 250);
    delay(380);
    break_func();
    moving(1, 200);
    delay(800);
    break_func();
    moving(2, 250);
    delay(430);
  }
  return;
}
char detect_color_new(char arr[30]) {
  int red = 0;
  int green = 0;
  int blue = 0;

  for (int i = 0; i < 30; i++) {
    if (arr[i] == 'b') {
      blue++;
    } else if (arr[i] == 'g') {
      green++;
    } else if (arr[i] == 'r') {
      red++;
    }
  }
  if ( red > green && red > blue) {
    return 'r';
  } else if (green > red && green > blue) {
    return 'g';
  } else if (blue > red && blue > green) {
    return 'b';
  }
}


