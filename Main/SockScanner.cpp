#include "Sockscanner.h"
#include "Color_Sensor.h"

int[] readRGB(int S2, int S3, int sensorOut) {
  //TODO
  // Declaring array for the RGB value
  int RGBValue[3];

  // Using the color sensor to get values for the frequency
  RGBValue[0] = readRedFrequency(S2, S3, sensorOut);
  RGBValue[1] = readGreenFrequency(S2, S3, sensorOut); 
  RGBValue[2] = readBlueFrequency(S2, S3, sensorOut);

  return RGBValue;
}

bool readIR() {
  //TODO

  return SockUnderSensor;  
}

// TODO Need to decide which data type sock-id will be for function type
// TODO Input todo should be IR sensor
void createSockID(int[] rgb, int todo) {
  //TODO
}

// TODO Object type sockID to be decided, int placeholder
int getSockID() {
  return sockID;
}
