char color_func() {
  int redFrequency = 0;
  int greenFrequency = 0;
  int blueFrequency = 0;

  int col_arr[3] = {0, 0, 0};

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  //for (int i = 0; i < 10; i++) {
  redFrequency = pulseIn(sensorOut, LOW);
  //}
  //redFrequency /= 10;
  Serial.print("R = ");
  Serial.print(map(redFrequency, red_low, red_high, 0, 200));

  col_arr[0] = map(redFrequency, red_low, red_high, 0, 200);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  //for (int i = 0; i < 10; i++) {
  greenFrequency = pulseIn(sensorOut, LOW);
  //    }
  //    greenFrequency /= 10;
  Serial.print(" G = ");
  Serial.print(map(greenFrequency, green_low, green_high, 0, 200));

  col_arr[1] = map(greenFrequency, green_low, green_high, 0, 200);


  //  Serial.print(" G = ");
  //  Serial.print(greenFrequency);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  // for (int i = 0; i < 10; i++) {
  blueFrequency = pulseIn(sensorOut, LOW);
  //    }
  //    blueFrequency /= 10;
  Serial.print(" B = ");
  Serial.println(map(blueFrequency, blue_low, blue_high, 0, 200));
  col_arr[2] = map(blueFrequency, blue_low, blue_high, 0, 200);


//high r=250 g=220 b=180    black
//low r=45 g=30 b=25     white
  if ((col_arr[0] < 50 && col_arr[1] < 50) || ( col_arr[2] < 50 && col_arr[1] < 50) || (col_arr[0] < 50 && col_arr[2] < 50)) {//col_arr[0] < 90 && col_arr[1] < 90 && col_arr[2] < 90
    return 'w';
  } else if (col_arr[0] > 150 && col_arr[1] > 150 && col_arr[2] > 150) {
    return 'k';
  } else if (col_arr[0] < col_arr[1] && col_arr[0] < col_arr[2]) {
    return 'r';
  } else if (col_arr[1] < col_arr[0] && col_arr[1] < col_arr[2]) {
    return 'g';
  } else if (col_arr[2] < col_arr[1] && col_arr[2] < col_arr[0]) {
    return 'b';
  }
}


char detect_color(char arr[10]) {
  //Serial.println("arr");
  int black = 0;
  int red = 0;
  int white = 0;
  int green = 0;
  int blue = 0;

  for (int i = 0; i < 15; i++) {
    if (arr[i] == 'w') {
      white++;
    } else if (arr[i] == 'k') {
      black++;
    } else if (arr[i] == 'b') {
      blue++;
    } else if (arr[i] == 'g') {
      green++;
    } else if (arr[i] == 'r') {
      red++;
    }
  }
  if (black > red && black > white && black > green && black > blue) {
    return 'k';
  } else if (white > red && white > black && white > green && white > blue) {
    return 'w';
  } else if (red > black && red > white && red > green && red > blue) {
    return 'r';
  } else if (green > red && green > white && green > black && green > blue) {
    return 'g';
  } else if (blue > red && blue > white && blue > black && blue > green) {
    return 'b';
  }
}
//char color_func() {
//  int redFrequency = 0;
//  int greenFrequency = 0;
//  int blueFrequency = 0;
//
//  int col_arr[3] = {0, 0, 0};
//
//  digitalWrite(S2, LOW);
//  digitalWrite(S3, LOW);
//
//  redFrequency = pulseIn(sensorOut, LOW);
//
//  col_arr[0] = map(redFrequency, 27, 197, 0, 150);
//
//  digitalWrite(S2, HIGH);
//  digitalWrite(S3, HIGH);
//
//  greenFrequency = pulseIn(sensorOut, LOW);
//
//
//  col_arr[1] = map(greenFrequency, 27, 190, 0, 150);
//
//
//  digitalWrite(S2, LOW);
//  digitalWrite(S3, HIGH);
//
//  blueFrequency = pulseIn(sensorOut, LOW);
//
//  col_arr[2] = map(blueFrequency, 20, 145, 0, 150);
//
//  if (col_arr[0] < 90 && col_arr[1] < 90 && col_arr[2] < 90) {
//    return 'w';
//  } else if (col_arr[0] > 120 && col_arr[1] > 120 && col_arr[2] > 120) {
//    return 'k';
//  } else if (col_arr[0] < col_arr[1] && col_arr[0] < col_arr[2]) {
//    return 'r';
//  } else if (col_arr[1] < col_arr[0] && col_arr[1] < col_arr[2]) {
//    return 'g';
//  } else if (col_arr[2] < col_arr[1] && col_arr[2] < col_arr[0]) {
//    return 'b';
//  }
//}
