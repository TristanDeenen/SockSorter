#ifndef SOCK_SCANNER_H
#define SOCK_SCANNER_H
#include <Arduino.h>

int readRGB(int *ar, int S2, int S3, int sensorOut);
void createSockID(int ar[][3], int measurements, int S2, int S3, int sensorOut);

#endif
