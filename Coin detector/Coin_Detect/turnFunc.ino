void turningR(int l, int c, int r) {
  if (((l == 0) || (l == 1)) && r == 0 && ((c == 0) || (c == 1))) {
    moving(1, 180);
    delay(200);
    moving(2, 255);
    delay(1000);
    Serial.println("*S");

  } else  if (l == 0 && r == 1 && c == 1) {
    moving(1, 180);
    delay(250);
    moving(3, 250);
    delay(1000);
    Serial.println("*S");
  } else  if (l == 0 && r == 1 && c == 0) {
    moving(1, 120);
    delay(10);
    //Serial.println('F');
    Serial.println("*S");
  } else if (c == 2) {
    no_of_sqrs++;
    //Serial.println("SQ");
    if (no_of_sqrs != 3) {
      float time1 = millis();
      float timeDif;
      while (timeDif <= 2000) {
        moving(3, 255);
        delay(5);
        timeDif = millis() - time1;
        //Serial.println('S');
      }
      Serial.println("*Q");
      moving(1, 150);
      delay(500);
    } else {
      moving(1, 150);
      delay(300);
      while (value[0] == 0 || value[9] == 0) {
        read_sensors();
        //Serial.println("DLF");
        moving(1, 100);
        delay(5);
      }
    }
  }
}

void turningL(int l, int c, int r) {
  if ((l == 0)  && ((r == 0) || (r == 1)) && ((c == 0) || (c == 1))) {
    moving(1, 180);
    delay(350);
    moving(3, 255);
    delay(800);
    Serial.println("*S");

  } else  if (l == 1 && r == 0 && c == 1) {
    moving(1, 180);
    delay(350);
    moving(2, 255);
    delay(850);
    Serial.println("*S");
  } else  if (l == 1 && r == 0 && c == 0) {
    moving(1, 120);
    delay(10);
    //Serial.println('F');
    Serial.println("*S");
  } else if (c == 2) {
    no_of_sqrs++;
    //Serial.println("SQ");
    if (no_of_sqrs != 3) {
      float time1 = millis();
      float timeDif;
      while (timeDif <= 1500) {
        moving(3, 255);
        delay(5);
        timeDif = millis() - time1;
        //Serial.println('S');
      }
      Serial.println("*Q");
      moving(1, 150);
      delay(500);
    } else {
      moving(1, 150);
      delay(300);
      while (value[0] == 0 || value[9] == 0) {
        read_sensors();
        //Serial.println("DLF");
        moving(1, 100);
        delay(5);
      }
    }
  }
}
