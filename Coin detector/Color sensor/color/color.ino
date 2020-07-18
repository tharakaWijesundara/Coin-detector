
#define S0 8
#define S1 9
#define S2 10
#define S3 11
#define sensorOut 12
int red_high=250;
int red_low=40;

int green_low=35;
int green_high=220;

int blue_low=20;
int blue_high=180;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);


  pinMode(sensorOut, INPUT);


  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
}

void loop() {
  char color = color_func();
  Serial.println(color);

}

//void color_line() {
//  int time_col = 0;
//  char arr[10];
//  int i = 0;
//  while (i < 20) {
//    char color = color_func();
//    if (color == 'b') {
//      arr[i] = 'b';
//    } else if (color == 'g') {
//      arr[i] = 'g';
//    } else if (color == 'r') {
//      arr[i] = 'r';
//    } else if (color == 'w') {
//      arr[i] = 'w';
//    } else if (color == 'k') {
//      arr[i] = 'k';
//    }
//    //Serial.println(time_col);
//    delay(75);
//    i += 1;
//  }
//  char det_col = detect_color(arr);
//  Serial.println(det_col);
//
//
//}
