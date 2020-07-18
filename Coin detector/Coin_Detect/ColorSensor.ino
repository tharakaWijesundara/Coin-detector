void ColorSensor()
{


  //Serial.read();

  counter = 0;
  sumgreen = 0;
  sumred = 0;
  sumblue = 0;
  sumwhite = 0;


  while (counter < 11)
  {

    int allArray[3] = {};

    //int allArray[3]={};
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);

    // Reading the output frequency
    redFrequency = pulseIn(sensorOut, LOW);
    //redFrequency=map(frequency
    // Printing the RED (R) value
    Serial.print("R = ");
    Serial.print(redFrequency - redCorr);
    allArray[0] = redFrequency - redCorr;
    delay(100);

    // Setting GREEN (G) filtered photodiodes to be read
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);

    // Reading the output frequency
    greenFrequency = pulseIn(sensorOut, LOW);

    // Printing the GREEN (G) value
    Serial.print(" G = ");

    Serial.print(greenFrequency - greenCorr);
    allArray[1] = greenFrequency - greenCorr;
    delay(100);

    // Setting BLUE (B) filtered photodiodes to be read
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);

    // Reading the output frequency
    blueFrequency = pulseIn(sensorOut, LOW);

    // Printing the BLUE (B) value
    Serial.print(" B = ");
    Serial.println(blueFrequency - blueCorr);
    allArray[2] = blueFrequency - blueCorr;
    delay(100);
    //delay(1000);

    minimumVal = minimum(allArray[0], allArray[1], allArray[2]);
    if (minimumVal == 0) {
      sumwhite ++;
      counter++;

    }
    else {
      index1 = index(minimumVal, allArray);
      Serial.print(index1);
      if (index1 == 0) {
        sumred++;
      }
      else if (index1 == 1) {
        sumgreen ++;
      }
      else {
        sumblue++;
      }
      counter++;
      //Serial.print("bbbbbbbbbbb");
    }

  }

  //Serial.print(sumblue);
  if (sumwhite >= 5) {
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    Serial.println("white");
    delay(2000);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
  }

  else if (sumred > sumgreen && sumred > sumblue) {
    color_val+=5;
    Serial.println(" RED ");
    Serial.print(" Red ");
    //digitalWrite(11,LOW);
    //digitalWrite(12,LOW);
    delay(50);
    digitalWrite(8,HIGH);
    delay(2000);
    digitalWrite(8,LOW);
    delay(100);


  }
  else if (sumgreen > sumred && sumgreen > sumblue) {
    Serial.println(" GREEN ");
    color_val+=3;
    //Serial.print(" Red ");
    //digitalWrite(9,LOW);
    //digitalWrite(11,LOW);
    delay(50);
    digitalWrite(9,HIGH);
    delay(2000);
    digitalWrite(9,LOW);
    delay(100);

  }
  else {
    Serial.println(" BLUE ");
    color_val+=2;
    //Serial.print(" Red ");
    //digitalWrite(10,LOW);
    //digitalWrite(11,LOW);

    //delay(50);
    digitalWrite(10, HIGH);
    delay(2000);
    digitalWrite(10, LOW);
    delay(100);




  }


}
int minimum(int red, int green, int blue)
{
  if (red < 30 && green < 30 && blue < 30) {

    return 0;
  }
  else if ( red > 300 && green > 300 && blue > 300) {
    return green;

  }
  else if (red < green && red < blue) {
    return red;

  }

  else {
    return blue;
  }

}
int index(int x, int Array[]) {
  for (int i = 0; 3; i++) {
    if (Array[i] == x) {
      return i;

    }
  }
}

void armTurn(){
  baseRev.turn(15, 25);
  delay(200);
  leftUp.turn(50, 25);
  delay(300);
  rightUp.turn(60,25);
  delay(500);
  leftUp.turn(120, 25);
  delay(300);
  leftUp.turn(10, 25);
  delay(300);
  rightUp.turn(75,25);
  delay(100);
  //turn over colorsensor
  
  baseRev.turn(105, 25);
  ColorSensor();
  delay(100);
 
  
  //leftUp.turn(5, 25);
  //delay(100);
  rightUp.turn(170,25);
  baseRev.turn(180, 25);
  //emtying into baskets
  leftUp.turn(5,25);
  delay(200);
  magnetMechanism.turn(120,25);
  delay(500);
  magnetMechanism.turn(10,25);
  delay(100);
  baseRev.turn(105, 25);
  delay(100);
}

