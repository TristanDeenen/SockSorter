#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H
#include <Arduino.h>

void setupColorSensor(int S0, int S1, int S2, int S3, int sensorOut);
int readRedFrequency(int S2, int S3, int sensorOut);
int readBlueFrequency(int S2, int S3, int sensorOut);
int readGreenFrequency(int S2, int S3, int sensorOut);

#endif
