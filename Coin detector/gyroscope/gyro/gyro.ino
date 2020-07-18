#include <Wire.h> 

const int MPU_ADDR = 0x68; 
 
int16_t accelerometer_x, accelerometer_y, accelerometer_z;

char tmp_str[7]; 



void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR); 
  Wire.write(0x6B);
  Wire.write(0); 
  Wire.endTransmission(true);
}
void loop() {
   Serial.println(gyro_read());
   delay(100);
}
int gyro_read(){
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false); 
  Wire.requestFrom(MPU_ADDR, 6, true); 
  

  accelerometer_x = Wire.read()<<8 | Wire.read(); 
  accelerometer_y = Wire.read()<<8 | Wire.read();
  accelerometer_z = Wire.read()<<8 | Wire.read();
  
  return map(accelerometer_x,-16000,18000,-90,90);
}

