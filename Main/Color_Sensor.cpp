#include "Color_Sensor.h"

int readRedFrequency(int S2, int S3, int sensorOut){
  int frequency = 0;
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remapping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 20,177,255,0);
  return frequency;
}
