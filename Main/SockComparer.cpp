/** This file stores the sock-ids and couples them to a basket. It also compares sock-ids to see check if there is a match.
If there is a match, then it outputs the corresponding basket. */

#include "SockComparer.h"
#include "SockScanner.h"

int dotProduct(int vec1[], int vec2[]){
  //return dot product of an array
  int i = 0;
  int result = NULL;

  while(i < 3){
  result += vec1[i] * vec2[i];
  i++;
  }

  return result;
}

int vectorNorm(int vec[]){
  //return Euclidian norm of an array
  return sqrt(pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2));
}

int cosineSimilarity(int RGBValue1[], int RGBValue2[]){
  //epic comparison algorithm to compare RGB values
  int cosineSimilarity = dotProduct(RGBValue1, RGBValue2)/(vectorNorm(RGBValue1)*vectorNorm(RGBValue2)); 
  return cosineSimilarity;
}

double calculateAverage(int a[]){
  //find sum of array element
  int sum = 0;
  int n = sizeof(a)/sizeof(a[0]);
  int i = 0;

  while(i<n){
    sum += a[i];
    i++;
  }

  return (double)sum/n;
}


 // Skips over empty entries in ar, correctly stops at last filled sockID
 // WARNING there could be empty entries in the entries before lastSockID
int lastSockIDfinder(int ar[][10][3], int bins){ //second parameter should be equal to measurements in main file

  int lastSockID = NULL; // Keeps track of last filled entry in ar 
  for (int x = 0; x < bins; x++){
    if(ar[x][0][0] != -1000){  //Placeholder should be the same as defined in main file
      lastSockID = x;
    }
  }
  if(lastSockID > bins){
    return NULL; //Edge case TODO
  }
  return lastSockID;
}

int findEmptyEntry(int ar[][10][3], int bins){ //second parameter should be equal to measurements in main file
  for (int i = 0; i < bins; i++) {
    if (ar[i][0][0]== -1000) {
      return i;
    }
  }
  return NULL; // Case if no empty slot if found
}

int sockComparer(int ar[][10][3], int bins, int measurements, int lastSockID){ //second parameter should be equal to measurements in main file
  //even more epic comparison algorithm that compares socks with imput the sockDB

  double avgcosSimilarities[lastSockID - 1];
  
  int q = 0; // bins
  while(q < lastSockID){
    int cosSimilarities[measurements];
    int i = 0;
    while(i < measurements){
      cosSimilarities[i] = cosineSimilarity(ar[lastSockID][i], ar[q][i]);
      i++;
    }
    
    avgcosSimilarities[q] = calculateAverage(cosSimilarities);
    q++;
  }

  return avgcosSimilarities;
}


int sockMatcher(int lastSockID, int avgcosSimilarities[], int treshold){
  int i = 0;
  int matchSockID = NULL;

  while(i < lastSockID && matchSockID == NULL){
    if(avgcosSimilarities[i] > treshold){
      matchSockID = i; 
    }
    i++;
  }
  return matchSockID;
}

void clearBin(int sockDB[][3], int measurements) {
  for (int i = 0; i < measurements; i++) {
    for (int j = 0; j < 3; j++) {
      sockDB[i][j] = -1000;
    }
  }
}

/*int sockDB = {{{255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}}, 
{{255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}, {255, 0, 200}}, 
{{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}}, 
{{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}}, 
{{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}}} */
