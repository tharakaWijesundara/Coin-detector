

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

