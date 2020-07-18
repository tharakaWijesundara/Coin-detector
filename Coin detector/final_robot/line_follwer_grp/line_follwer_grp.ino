#include <Wire.h>
#include <Servo.h>
Servo water_arm;

//Left_Motor
#define enA 7;
#define in1 6;
#define in2 5;

//Right_Motor
#define enB 2;
#define in3 3;
#define in4 4;

//color sensor
#define S0 8
#define S1 9
#define S2 10
#define S3 11
#define sensorOut 12

//color values
int red_high = 250;
int red_low = 40;

int green_low = 35;
int green_high = 220;

int blue_low = 20;
int blue_high = 180;
//

int value[16];
int def_speed = 90; //def_speed<=motor_val<=255-def_speed    220

//maze follow
int deviation;
//float kp = 1.2, kd = 1, ki = 0.01;          //float kp = 1.2, kd = 1, ki = 0.01;
float kp = 1.5, kd = 1.6, ki = 0;
float ing = 0;
float previous_prp = 0;

//wall

//Ultra_Sonic
#define trigPinL 31
#define echoPinL 30

#define trigPinR 53
#define echoPinR 52

#define trigPinF 32
#define echoPinF 33

int wall_dist[3] = {0, 0, 0};
int def_speed_w = 180;

float kp_w = 2.5, kd_w = 0.1, ki_w = 0;
float ing_w = 0;
float previous_prp_w = 0;

//wall junc state should be zero
int wall = 0;//1
int junc = 0;//2
//

int state = 3;//4

//gyro
const int MPU_ADDR = 0x68;

int16_t accelerometer_x, accelerometer_y, accelerometer_z;
int gyros_read = 0;
void setup() {
  Serial.begin(9600);
  water_arm.attach(27);
  //color_sensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
  digitalWrite(26, LOW);
  //

  for (int pin = 34; pin <= 49; pin++) {
    pinMode(pin, INPUT);
  }


  for (int pin = 2; pin <= 7; pin++) {
    pinMode(pin, OUTPUT);
  }
  //wall
  pinMode(echoPinR, INPUT);
  pinMode(echoPinL, INPUT);
  pinMode(echoPinF, INPUT);

  pinMode(trigPinR, OUTPUT);
  pinMode(trigPinL, OUTPUT);
  pinMode(trigPinF, OUTPUT);

  digitalWrite(trigPinL, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPinR, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPinF, LOW);
  delayMicroseconds(5);

  //gyro
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  water_arm.write(45);
  delay(2500);
}

void loop() {
  read_sensors();
  //int line = line_state();
  if (line_state() == 1 && state == 0) {
    moving(2, 185);
    delay(30);
    moving(1, 120);
    delay(500);
    break_func();
    Serial.println('c');
    delay(900);
    moving(1, 150);
    delay(350);
    break_func();
    //Serial.println('p');
    kp = 1.4, kd = 1.6, ki = 0.01;
    color_line_new();
    state++;
    //Serial.println('p');
    return;

  } else if (line_state() == 4 && wall == 2) {
    break_func();
    moving(1, 150);
    delay(600);
    break_func();
    while (1) {
      moving(5, 0);
      delay(1000);
    }

  } else if (value[14] == 0 && value[13] == 0 && value[12] == 0 && value[11] == 0 && value[10] == 0 && value[9] == 0 && value[8] == 0) {
    //    int line;
    //    moving(1, def_speed);
    //    delay(100);
    //
    //    line = line_state();
    //    if (line == 2) {
    //Serial.println('p');
    right_turn();
    //}

  } else if (value[1] == 0 && value[2] == 0 && value[3] == 0 && value[4] == 0 && value[5] == 0 && value[6] == 0 && value[7] == 0 ) {
    moving(1, def_speed);
    delay(100);
    int line = line_state();
    if (line == 2) {
      //Serial.println('y');
      left_turn();
    }
  }
  else if (line_state() == 2 && wall == 1) {
    break_func();
    moving(4, 150);
    delay(250);
    break_func();
    delay(1000);
    water_arm.write(90);
    //digitalWrite(26, HIGH);
    delay(5000);
    //digitalWrite(26, LOW);
    water_arm.write(0);
    delay(1000);
    int line = line_state();
    moving(3, 255);
    delay(1600);

  } else if (line_state() == 4 && wall == 1) {
    break_func();
    right_turn();
    wall = 2;
  }  else if (line_state() == 2 && state == 1) {
    state++;
    motor_drive('L', 250);
    motor_drive('R',  250);
    delay(500);

  } else if (line_state() == 2 && state == 2) {
    state++;
  } else if (line_state() == 2 && state == 3) {
    state++;
    int def_speed = 80;
    moving(1, 80);
    delay(400);
//    moving(1,0);
//    delay(400);
  } else if (line_state() == 2 && state == 4) {
    Serial.println('g');
    break_func();
    moving(4, 200);
    delay(500);
    moving(1, 100);
    delay(100);
    break_func();
    water_arm.write(0);
    while (wall == 0) {
      read_sensors();
      main_wall();
      if (junc > 1 && line_state() != 2) {
        Serial.println('p');
        wall = 1;
        break;
      }
    }
    return;

  } else {
    line_fol();
  }

}

















