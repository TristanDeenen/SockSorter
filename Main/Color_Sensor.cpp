#include "Color_Sensor.h"

//WARNING, now prints values for RGB, comment out per function to disable!

int readRedFrequency(int S2, int S3, int sensorOut){
  int frequency = 0;
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remapping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 20,177,255,0);
  Serial.print("R= ");//printing name
  Serial.print(red_frequency);//printing RED color frequency
  Serial.print("  ");
  return frequency;
}

int readGreenFrequency(int S2, int S3, int sensorOut){
  int frequency = 0;
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 30,250,255,0);
  Serial.print("G= ");//printing name
  Serial.print(green_frequency);//printing RED color frequency
  Serial.print("  ");
  return frequency;
}

int readBlueFrequency(int S2, int S3, int sensorOut){
  int frequency = 0;
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 35,200,255,0);
  Serial.print("B= ");//printing name
  Serial.print(blue_frequency);//printing RED color frequency
  Serial.println("  ");
  return frequency;
}
