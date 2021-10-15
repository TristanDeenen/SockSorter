/** This file takes the input from the RGB-scanner
and outs the data into a sock-id. Then it outputs the id.*/

#include "Sockscanner.h"
#include "Color_Sensor.h"
#include "IR_Sensor.h"
#include "Rollerband_servo.h"

int readRGB(int *ar, int S2, int S3, int sensorOut) {
  ar[0] = readRedFrequency(S2, S3, sensorOut);
  ar[1] = readGreenFrequency(S2, S3, sensorOut); 
  ar[2] = readBlueFrequency(S2, S3, sensorOut);
}

void createSockID(int *ar, int measurements, int rollerbandSpeed, int S2, int S3, int sensorOut) {
  rollerbandStart(rollerbandSpeed);
  while(i < measurements){
    readRGB(ar[i], int S2, int S3, int sensorOut);
  }
  rollerbandStop();
}
