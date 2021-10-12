#ifndef SOCK_SCANNER_H
#define SOCK_SCANNER_H
#include <Arduino.h>

int[] readRGB(int S2, int S3, int sensorOut);
void readIR()();
void createSockID(int[] rgb, int todo);
int getSockID();

#endif
