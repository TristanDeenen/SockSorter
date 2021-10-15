/** This file takes the input from the RGB-scanner and the IR-scanner
and converts that data to a sock-id. Then it outputs the id.*/

#include "Sockscanner.h"
#include "Color_Sensor.h"
#include "IR_Sensor.h"
#include "Rollerband_servo.h"

int readRGB(int *ar, int S2, int S3, int sensorOut) {
  // Declaring array for the RGB value
  //int RGBValue[3];

  // Using the color sensor to get values for the frequency
  //RGBValue[0] = readRedFrequency(S2, S3, sensorOut);
  //RGBValue[1] = readGreenFrequency(S2, S3, sensorOut); 
  //RGBValue[2] = readBlueFrequency(S2, S3, sensorOut);

  ar[0] = readRedFrequency(S2, S3, sensorOut);
  ar[1] = readGreenFrequency(S2, S3, sensorOut); 
  ar[2] = readBlueFrequency(S2, S3, sensorOut);

  //return RGBValue;
}

// TODO Need to decide which data type sock-id will be for function type
// TODO Input todo should be IR sensor
void createSockID(int *ar, bool sockCheck, int measurements) {
  //TODO
  
  while(i < measurements){
    rollerbandToggle(sockCheck);
    readRGB(ar[0])
  }
  
}