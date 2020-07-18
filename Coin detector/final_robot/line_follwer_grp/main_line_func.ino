void left_turn() {
  moving(1, def_speed);
  delay(50);
  moving(2, 250);
  delay(600);
}

void right_turn() {
  moving(1, def_speed);
  delay(150);

  moving(3, 250);
  delay(750);

}

void serial_print() {
  for (int i = 1; i < 15; i++) {
    Serial.print(value[i]);
  }
  Serial.println(' ');
}

