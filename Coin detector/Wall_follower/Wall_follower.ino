
//Right_Motor
#define enA 7;
#define in1 6;
#define in2 5;

//Left_Motor
#define enB 2;
#define in3 3;
#define in4 4;


//Ultra_Sonic
#define trigPinL 31
#define echoPinL 30

#define trigPinR 53
#define echoPinR 52

#define trigPinF 32
#define echoPinF 33

int wall_dist[3] = {0, 0, 0};
int def_speed = 200;

float kp = 2.9, kd = 0.1, ki = 0;
float ing = 0;
float previous_prp = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("Start");
  for (int pin = 2; pin <= 7; pin++) {
    pinMode(pin, OUTPUT);
  }
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
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  read_sensors();
//  if (((wall_dist[0] >= 40) && (wall_dist[2] >= 40)) || ((wall_dist[0] >= 30) && (wall_dist[2] < 30))) { //||((wall_dist[0] <= 20)&&(wall_dist[2] >= 20)&&(wall_dist[1] >= 30))
//    int timeStartL = 0;
//    int timeL = 0;
//    while (timeStartL < 450 && wall_dist[1] > 8) {
//      read_sensors();
//      moving(1, def_speed);
//      delay(10);
//      timeStartL += 10;
//    }
//    moving(2, 230);
//    delay(1010);
//    moving(1, def_speed);
//    delay(450);
//  } else if ((wall_dist[0] < 40) && (wall_dist[2] >= 40) && (wall_dist[1] < 45)) {
//    int timeStartR = 0;
//    while (timeStartR < 450 && wall_dist[1] > 10) {
//      read_sensors();
//      moving(1, def_speed);
//      delay(10);
//      timeStartR += 10;
//    }
//    moving(3, 230);
//    delay(1000);
//    moving(1, def_speed);
//    delay(550);
//  } else if ((wall_dist[0] < 40) && (wall_dist[2] >= 40) && (wall_dist[1] > 45)) {
//    int timeStartF = 0;
//    //    moving(3, 150);
//    //    delay(40);
//    while (timeStartF < 750 && wall_dist[1] > 5) {
//      read_sensors();
//      moving(1, def_speed);
//      delay(10);
//      timeStartF += 10;
//    }
//  } else if ((wall_dist[0] < 25) && (wall_dist[2] < 25) && (wall_dist[1] < 25)) {
//    int timeStartU = 0;
//    while (timeStartU < 500 && wall_dist[1] > 8) {
//      read_sensors();
//      moving(1, def_speed);
//      delay(10);
//      timeStartU += 10;
//    }
//    moving(3, 255);
//    delay(1500);
//  }
//  else {
//    wall_fol();
//  }
      Serial.print(wall_dist[0]);
      Serial.print("  ");
      Serial.print(wall_dist[1]);
      Serial.print("  ");
      Serial.print(wall_dist[2]);
      Serial.println(' ');
         Serial.println(error_cal());
}
