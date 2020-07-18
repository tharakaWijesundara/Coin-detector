long distance(int side) { // 1-Left    2-Front    3-Right
  long duration = 0;
  long cm = 0;
  long dis = 0;
  if (side == 1) {
    digitalWrite(trigPinL, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinL, LOW);

    duration = pulseIn(echoPinL, HIGH, 1000000);
    cm = (duration / 2) / 29.1;

  } else if (side == 3) {
    digitalWrite(trigPinR, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinR, LOW);

    duration = pulseIn(echoPinR, HIGH, 1000000);
    cm = (duration / 2) / 29.1;

  } else {

    digitalWrite(trigPinF, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinF, LOW);

    duration = pulseIn(echoPinF, HIGH, 1000000);
    cm = (duration / 2) / 29.1;

  }
  return cm;


}


void read_sensors() {

  for (int i = 1; i <= 3; i++) {
    wall_dist[i - 1] = distance(i);
  }
}




