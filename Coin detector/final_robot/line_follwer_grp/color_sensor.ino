char color_func() {
  char color[15];
  for (int j = 0; j < 15; j++) {
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
    //    Serial.print("R = ");
    //    Serial.print(map(redFrequency, 27, 197, 0, 150));

    col_arr[0] = map(redFrequency, 27, 197, 0, 150);

    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);

    //for (int i = 0; i < 10; i++) {
    greenFrequency = pulseIn(sensorOut, LOW);
    //    }
    //    greenFrequency /= 10;
    //    Serial.print(" G = ");
    //    Serial.print(map(greenFrequency, 27, 190, 0, 150));

    col_arr[1] = map(greenFrequency, 27, 190, 0, 150);


    //  Serial.print(" G = ");
    //  Serial.print(greenFrequency);

    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);

    // for (int i = 0; i < 10; i++) {
    blueFrequency = pulseIn(sensorOut, LOW);
    //    }
    //    blueFrequency /= 10;
    //    Serial.print(" B = ");
    //    Serial.println(map(blueFrequency, 20, 145, 0, 150));
    col_arr[2] = map(blueFrequency, 20, 145, 0, 150);



    if ((col_arr[0] < 100 && col_arr[1] < 100) || ( col_arr[2] < 100 && col_arr[1] < 100) || (col_arr[0] < 100 && col_arr[2] < 100)) {
      color[j] = 'w';
    } else if ((col_arr[0] > 110 && col_arr[1] > 110) || (col_arr[2] > 110 && col_arr[0] > 110) || (col_arr[2] > 110 && col_arr[1] > 110)) {
      color[j] = 'k';
    } else if (col_arr[0] < col_arr[1] && col_arr[0] < col_arr[2]) {
      color[j] = 'r';
    } else if (col_arr[1] < col_arr[0] && col_arr[1] < col_arr[2]) {
      color[j] = 'g';
    } else if (col_arr[2] < col_arr[1] && col_arr[2] < col_arr[0]) {
      color[j] = 'b';
    }
  }
  char detected_col = detect_color(color);
  return detected_col;
}
void color_line() {
  char color = color_func();
  while ((color == 'w') || (color == 'k') )  {
    //Serial.println('s');
    read_sensors();
    color = color_func();
    motor_drive('L', 80);
    motor_drive('R', 80);
    delay(10);
  }
  //  while (1) {
  //    read_sensors();
  //    if (line_state() != 2) {
  //      moving(1, 100);
  //      delay(50);
  //    } else {
  //      moving(5, 0);
  //      delay(100);
  //      return;
  //    }
  //  }
  color = 'r';
  Serial.println(color);
  Serial.println('u');
  delay(200);
  while (line_state() != 3) {
    moving(4, 120);
    delay(20);
  }
  moving(5, 0);
  delay(100);
  if (color == 'r') {
    moving(1, 200);
    delay(570);
    moving(3, 250);
    delay(480);
    moving(1, 200);
    delay(700);
    moving(2, 250);
    delay(420);
    moving(1, 200);
    delay(800);
    moving(5, 0);
    delay(500);
    Serial.println('l');
    delay(1500);
    Serial.println('u');
    delay(1500);
    moving(2, 250);
    delay(400);
    moving(1, 200);
    delay(750);
    moving(3, 250);
    delay(500);
    moving(5, 0);
    delay(500);
    //    moving(1, 200);
    //    delay(150);
    return;
  }
  else if (color == 'g') {
    moving(1, 200);
    delay(1000);
    moving(5, 0);
    delay(500);
    Serial.println('l');
    delay(500);
    moving(1, 200);
    delay(1000);
  }
  else if (color == 'b') {
    moving(1, 200);
    delay(570);
    moving(2, 250);
    delay(500);
    moving(1, 200);
    delay(650);
    moving(3, 250);
    delay(550);
    moving(1, 200);
    delay(800);
    moving(3, 250);
    delay(550);
    moving(1, 200);
    delay(750);
    moving(2, 250);
    delay(400);
  }
  //  while (1) {
  //    moving(5, 0);
  //    delay(500);
  //  }

}
char detect_color(char arr[15]) {
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

//void coin_box() {
//  color_line();
//}



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
//  //for (int i = 0; i < 10; i++) {
//  redFrequency = pulseIn(sensorOut, LOW);
//  //}
//  //redFrequency /= 10;
//  //    Serial.print("R = ");
//  //    Serial.print(map(redFrequency, 27, 197, 0, 150));
//
//  col_arr[0] = map(redFrequency, 27, 197, 0, 150);
//
//  digitalWrite(S2, HIGH);
//  digitalWrite(S3, HIGH);
//
//  //for (int i = 0; i < 10; i++) {
//  greenFrequency = pulseIn(sensorOut, LOW);
//  //    }
//  //    greenFrequency /= 10;
//  //    Serial.print(" G = ");
//  //    Serial.print(map(greenFrequency, 27, 190, 0, 150));
//
//  col_arr[1] = map(greenFrequency, 27, 190, 0, 150);
//
//
//  //  Serial.print(" G = ");
//  //  Serial.print(greenFrequency);
//
//  digitalWrite(S2, LOW);
//  digitalWrite(S3, HIGH);
//
//  // for (int i = 0; i < 10; i++) {
//  blueFrequency = pulseIn(sensorOut, LOW);
//  //    }
//  //    blueFrequency /= 10;
//  //    Serial.print(" B = ");
//  //    Serial.println(map(blueFrequency, 20, 145, 0, 150));
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

