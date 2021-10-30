/** This file takes the input from the RGB-scanner
and outs the data into a sock-id. Then it outputs the id.*/

#include "Sockscanner.h"
#include "Color_Sensor.h"
#include "IR_Sensor.h"
#include "Rollerband_servo.h"


int readRGB(int ar[], int S2, int S3, int sensorOut) {
  ar[0] = readRedFrequency(S2, S3, sensorOut);
  delay(100);
  ar[1] = readGreenFrequency(S2, S3, sensorOut); 
  delay(100);
  ar[2] = readBlueFrequency(S2, S3, sensorOut);
  
  delay(100);
}

void createSockID(int ar[][3], int measurements, int S2, int S3, int sensorOut) {
  int i = 0;
  Serial.println("Measuring color..." );
  while(i < measurements){
    int RGBavg[5][3];
    
    for (int x = 0; x < 1; x++){
      
      readRGB(RGBavg[x], S2, S3, sensorOut);
    }

    int r = 0;
    int g = 0;
    int b = 0;
    for (int j = 0; j < 1; j++) {
      r += RGBavg[j][0];
      g += RGBavg[j][1];
      b += RGBavg[j][2];
    }
    ar[i][0] = r / 5;
    ar[i][1] = g / 5;
    ar[i][2] = b / 5; 

    i++;  
  }
}
