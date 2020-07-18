void main_wall() {
  read_sensors_w();
  if (((wall_dist[0] >= 40) && (wall_dist[2] >= 40)) || ((wall_dist[0] >= 30) && (wall_dist[2] < 30))) { //||((wall_dist[0] <= 20)&&(wall_dist[2] >= 20)&&(wall_dist[1] >= 30))
    junc++;
    int timeStartL = 0;
    while (timeStartL < 450 && wall_dist[1] > 8) {
      read_sensors_w();
      moving(1, def_speed_w);
      delay(10);
      timeStartL += 10;
    }
    break_func();
    moving(2, 230);
    delay(1250);
    break_func();
    moving(1, def_speed_w);
    delay(600);
  } else if ((wall_dist[0] < 40) && (wall_dist[2] >= 40) && (wall_dist[1] < 45)) {
    junc++;
    int timeStartR = 0;
    while (timeStartR < 450 && wall_dist[1] > 8) {
      read_sensors_w();
      moving(1, def_speed_w);
      delay(10);
      timeStartR += 10;
    }
    break_func();
    moving(3, 230);
    delay(1250);
    break_func();
    moving(1, def_speed_w);
    delay(550);
  } 
//  else if ((wall_dist[0] < 40) && (wall_dist[2] >= 40) && (wall_dist[1] > 45)) {
//    int timeStartF = 0;
//    //    moving(3, 150);
//    //    delay(40);
//    while (timeStartF < 750 && wall_dist[1] > 5) {
//      read_sensors_w();
//      moving(1, def_speed_w);
//      delay(10);
//      timeStartF += 10;
//    }
//  } 
  else if ((wall_dist[0] < 25) && (wall_dist[2] < 25) && (wall_dist[1] < 25)) {
    int timeStartU = 0;
    while (timeStartU < 500 && wall_dist[1] > 8) {
      read_sensors_w();
      moving(1, def_speed_w);
      delay(10);
      timeStartU += 10;
    }
    break_func();
    moving(3, 255);
    delay(1680);
    break_func();
  }
  else {
    wall_fol();
  }
  //  Serial.print(wall_dist[0]);
  //  Serial.print("  ");
  //  Serial.print(wall_dist[1]);
  //  Serial.print("  ");
  //  Serial.print(wall_dist[2]);
  //  Serial.println(' ');
  //     Serial.println(error_cal_w());
}

