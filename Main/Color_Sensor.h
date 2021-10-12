#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H
#include <Arduino.h>

int readRedFrequency(int S2, int S3, int sensorOut);
int readBlueFrequency(int S2, int S3, int sensorOut);
int readGreenFrequency(int S2, int S3, int sensorOut);

#endif
