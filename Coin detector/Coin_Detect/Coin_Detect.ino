
//final
#include <EEPROM.h>
#define l_five A9
#define r_four A11
#define r_three A10
#define r_two A2
#define r_one A3

#define l_one A4
#define l_two A5
#define l_three A6
#define l_four A7
#define r_five A12


//Right_Motor
#define enA 7;
#define in1 6;
#define in2 5;

//Left_Motor
#define enB 2;
#define in3 4;
#define in4 3;

int state;
int color_val;
int value[10];
int sensor_name[10] = {l_five, l_four, l_three, l_two, l_one, r_one, r_two, r_three, r_four, r_five};
int def_speed = 150; //def_speed<=motor_val<=255-def_speed
//def_speed<255/2
//def_speed<125
//for error controling

//maze follow
float kp = 0.5, kd = 0.1, ki = 0;
//float kp, kd, ki;
float ing = 0;
float previous_prp = 0;
/////

//dotted_follow
float kp_d = 1.1, kd_d = 1.5, ki_d = 0.001;
float ing_d = 0;
float previous_prp_d = 0;
int pre_error;
/////
int def_speed_d = 120;

/////


/////
int no_of_sqrs = 0;


////color sensor

#include <Servo.h>
#include "ArmServo.h"

#define BASE_REV 27
#define UP_ARM_LEFT 28
#define UP_ARM_RIGHT 29
#define MAGNET_MECHANISM 30



#define S0 22
#define S1 23
#define S2 24
#define S3 25
#define sensorOut 26

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int blueCorr = 40;
int greenCorr = 50;
int redCorr = 60;
int counter = 0;
int sumred;
int sumgreen;
int sumblue;
int minimumVal;
int index1;
int sumwhite;


ArmServo baseRev(BASE_REV);
ArmServo leftUp(UP_ARM_LEFT);
ArmServo rightUp(UP_ARM_RIGHT);
ArmServo magnetMechanism(MAGNET_MECHANISM);


void setup() {
  Serial.begin(9600);
  pinMode(l_five, INPUT);
  pinMode(l_four, INPUT);
  pinMode(l_three, INPUT);
  pinMode(l_two, INPUT);
  pinMode(l_one, INPUT);

  pinMode(r_five, INPUT);
  pinMode(r_four, INPUT);
  pinMode(r_three, INPUT);
  pinMode(r_two, INPUT);
  pinMode(r_one, INPUT);

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  for (int pin = 2; pin <= 7; pin++) {
    pinMode(pin, OUTPUT);
  }
//  kp = EEPROM.get(0, kp);
//  kd = EEPROM.get(20, kd);
//  ki = EEPROM.get(40, ki);

  ////color sensor
  baseRev.attach();
  leftUp.attach();
  rightUp.attach();
  magnetMechanism.attach();
  
  //Start position
  baseRev.turn(95, 25);
  rightUp.turn(60, 25);
  delay(100);
  leftUp.turn(10, 25);
  delay(100);





  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);

  // Setting frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);

  // Begins serial communication
  Serial.begin(9600);
}

void loop() {
  read_sensors();
  Serial.println(("*P" + String(kp) + "*"));
  Serial.println(("*D" + String(kd) + "*"));
  Serial.println(("*I" + String(ki) + "*"));

  if (Serial.available()) {
    digitalWrite(12, HIGH);
    if (Serial.read() == '1') {
      state = 1;
      digitalWrite(13, HIGH);
      moving(1, 0);
    } else {
      state = 0;
      digitalWrite(13, LOW);
    }
  } else {
    digitalWrite(12, LOW);
  }
  if (state == 1) {
    serial();
  } else {
    //digitalWrite(13, LOW);
    if (no_of_sqrs != 3) {
      //Serial.println("MAZE");
      ////////Maze follow
      mazeFollow();
    } else {
      ///////Dotted_follow
      dotlineFollow();
//      digitalWrite(11, HIGH);
//      delay(100000);
    }
  }
}
