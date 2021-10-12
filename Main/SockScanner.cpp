#include "Sockscanner.h"
#include "Color_Sensor.h"

int[] readRGB() {
  //TODO
  // Declaring array for the RGB value
  int RGBValue[3];

  // Using the color sensor to get values for the frequency
  RGBValue[0] = readRedFrequency();
  RGBValue[1] = readGreenFrequency(); 
  RGBValue[2] = readBlueFrequency();

  return RGBValue;
}

//TODO input type not clear yet
void readIR() {
  //TODO
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
