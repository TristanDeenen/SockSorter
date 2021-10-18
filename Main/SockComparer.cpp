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

int lastSockIDfinder(int *ar){
  //find last filled array, if only one array then return 0, otherwise returns the argument for sockMatcher, namely an array avgcosSimilarities
  int x = 0;
  while(x < bins){
    if(ar[x][0][0] != -1){  //Placeholder should be the same as defined in main file
      x++;
    } else{
      break;
    }
  }

  lastSockID = x - 1; //now it is the index of the last recorded sock id, this is important for the comparison

  if(lastSockID == -1){
    return NULL; //Value if the sock is the first sock scanned
  } else{
    return lastSockID;
  }
}

int sockComparer(int *ar, int bins, int measurements, int lastSockID){
  //even more epic comparison algorithm that compares socks with imput the sockDB

  int avgcosSimilarities[lastSockID - 1];

  int q = 0;
  while q < lastSockID{
    int cosSimilarities[measurements];
    int i = 0;
    while(i < measurements){
      cosineSimilarities[i] = cosineSimilarity(ar[lastSockID][i], ar[q][i]);
    }

    avgcosSimilarities[q] = calculateAverage(cosineSimilarities);
  }

  return avgcosSimilarities;
}

int sockMatcher(int lastSockID, int avgcosSimilarities, int treshold){
  int i = 0;
  int matchSockID = NULL;

  while(i < lastSockID && matchSockID == NULL){
    if(avgcosSimilarities[i] > treshold){
      matchSockID = i; 
    }
  }

  return matchSockID;
}

/*sockDB = ar[[bins][measurements][3]]
= {{[255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200]}, 
{[255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200]}, 
{[-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1]}, 
{[-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1]}, 
{[-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1], [-1, -1, -1]}} */

