#ifndef SOCK_COMPARER_H
#define SOCK_COMPARER_H
#include <Arduino.h>

int dotProduct(int vec1[], int vec2[]);
int vectorNorm(int vec[]);
int cosineSimilarity(int RGBValue1[], int RGBValue2[]);
<<<<<<< Updated upstream
int sockComparer(int *ar, int bins, int measurements)
double calculateAverage(int a[]);
int lastSockIDfinder(int *ar);
int sockMatcher(int lastSockID, int avgcosSimilarities, int treshold);
=======
int sockComparer(int *ar, int bins, int measurements);
double calculateAverage(int a[], int n);
>>>>>>> Stashed changes

#endif
