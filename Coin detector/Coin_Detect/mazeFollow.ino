void mazeFollow() {
  read_sensors();
  if ((value[1] == 0 && value[2] == 0 && value[3] == 0) || (value[6] == 0 && value[7] == 0 && value[8] == 0)) {
    junctionMaze('L');
  } else if (value[0] == 1 && value[1] == 1 && value[2] == 1 && value[3] == 1 && value[4] == 1 && value[5] == 1 && value[6] == 1 && value[7] == 1 && value[8] == 1 && value[9] == 1) {
    //Serial.println("ARM_TURN");
    moving(1,0);
    delay(100);
    armTurn();
    //Serial.println("ARM_TURN");
    while (value[4] == 1) {
      read_sensors();
      moving(3, 255);
      delay(5);
    }
  }  else {
    line_fol();
  }
}

void dotlineFollow() {
  if (value[0] == 1 && value[1] == 1 && value[2] == 1 && value[3] == 1 && value[4] == 1 && value[5] == 1 && value[6] == 1 && value[7] == 1 && value[8] == 1 && value[9] == 1 ) {
    dotted_turn();

  } else if ( value[3] == 0 && value[4] == 0 && value[5] == 0 && value[6] == 0) {
    while (value[1] == 0 || value[8] == 0) {
      read_sensors();
      moving(1, 200);
      Serial.println("FOW");
      delay(20);
    }
    stationary(color_val);
  } else {
    dotted_follow();
    Serial.println('D');
  }
}
void squareFollow() {
  while (1) {
    read_sensors();
    if ((value[1] == 0 && value[2] == 0 && value[3] == 0) || (value[6] == 0 && value[7] == 0 && value[8] == 0)) {
      junctionMaze('R');
    } else if (value[0] == 1 && value[1] == 1 && value[2] == 1 && value[3] == 1 && value[4] == 1 && value[5] == 1 && value[6] == 1 && value[7] == 1 && value[8] == 1 && value[9] == 1) {
      digitalWrite(11, HIGH);
      delay(1000);
      break;
    }  else {
      line_fol();
    }
  }
}

