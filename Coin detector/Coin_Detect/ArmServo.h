#include <Servo.h>

class ArmServo {
  public:
    float currentAngle;
    Servo servo;
    int pin;

    ArmServo(int x);
    void attach();
    void turn(float angle, float del);
    void turnWithPartner(ArmServo partner, float angle, float del);
};
