#ifndef SOCK_COMPARER_H
#define SOCK_COMPARER_H
#include <Arduino.h>

double dotProduct(int vec1[], int vec2[]);
double vectorNorm(int vec[]);
double cosineSimilarity(int RGBValue1[], int RGBValue2[]);
double lengthSimilarity(int RGBValue1[], int RGBValue2[]);
int sockComparer(int *ar, int bins, int measurements);
double calculateAverage(double a[]);
int lastSockIDfinder(int ar[][10][3], int bins);
int findEmptyEntry(int ar[][10][3], int bins);
int sockMatcher(int lastSockID, double avgcosSimilarities[], double avgLengthSimilarities[], double tresholdCos, double tresholdLength);
//int sockComparer(int ar[][10][3], int bins, int measurements, int lastSockID);
void clearBin(int sockDB[][3], int measurements);
#endif
