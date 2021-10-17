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

bool sockComparer(int *ar, int measurements){
  //even more epic comparison algorithm that compares socks with imput the sockDB
  int i = 0;
  int cosineSimilarities[measurements];

  while(i < measurements){
    cosineSimilarities[i] = cosineSimilarity()
  }
}

/*sockDB = ar[[bins][measurements][3]]
= {{[255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200], [255, 0, 200]}, 
{[], [], [], [], [], [], [], [], [], []}, 
{[], [], [], [], [], [], [], [], [], []}, 
{[], [], [], [], [], [], [], [], [], []}, 
{[], [], [], [], [], [], [], [], [], []}} */

