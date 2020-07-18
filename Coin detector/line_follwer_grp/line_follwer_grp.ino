#include <Servo.h>
Servo water, arm_mag, arm_lift;

//Right_Motor
#define enA 7;
#define in1 6;
#define in2 5;

//Left_Motor
#define enB 2;
#define in3 3;
#define in4 4;

int value[16];
int def_speed = 225; //def_speed<=motor_val<=255-def_speed

//maze follow
int deviation;
float kp = 2.1, kd = 1.7, ki = 0.005;
float ing = 0;
float previous_prp = 0;


void setup() {
  Serial.begin(9600);
  for (int pin = 34; pin <= 49; pin++) {
    pinMode(pin, INPUT);
  }

  for (int pin = 2; pin <= 7; pin++) {
    pinMode(pin, OUTPUT);
  }
  water.attach(10);
  arm_mag.attach(9);
  arm_lift.attach(11);

  //arm_mag.write(0);
  //arm_lift.write(0);
  delay(500);
}

void loop() {

  read_sensors();

  //line_fol();
  for (int i = 1; i < 15; i++) {
    Serial.print(value[i]);
  }
  Serial.println(' ');




}


















