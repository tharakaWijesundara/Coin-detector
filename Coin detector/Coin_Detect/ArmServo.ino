#include <Servo.h>

ArmServo::ArmServo(int x) {
  pin = x;
}

void ArmServo::attach() {
  servo.attach(pin);
  servo.write(0);
}

void ArmServo::turn(float angle, float del) {
  int incr = angle < currentAngle ? -1 : 1;
  for (; currentAngle != angle; currentAngle += incr) {
    servo.write(currentAngle);
    delay(del);
  }
}

void ArmServo::turnWithPartner(ArmServo partner, float angle, float del) {
  int incr = angle < currentAngle ? -1 : 1;
  for (; currentAngle != angle; currentAngle += incr) {
    servo.write(currentAngle);
    partner.servo.write(currentAngle);
    delay(del);
  }
}
