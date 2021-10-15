#ifndef SOCK_SCANNER_H
#define SOCK_SCANNER_H
#include <Arduino.h>

int readRGB(int *ar, int S2, int S3, int sensorOut);
bool readIR(int irSensorPin);
void createSockID(int *ar, int measurement);

#endif
