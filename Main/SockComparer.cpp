/** This file stores the sock-ids and couples them to a basket. It also compares sock-ids to see check if there is a match.
If there is a match, then it outputs the corresponding basket. */

#include "SockComparer.h"
#include "SockScanner.h"

double dotProduct(int vec1[], int vec2[]){
  //return dot product of an array
  int i = 0;
  double result = 0.0;

  while(i < 3){
  result += vec1[i] * vec2[i];
  i++;
  }
  
  return result;
}

double vectorNorm(int vec[]){
  //return Euclidian norm of an array
  double norm = sqrt(pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2));
  
  return norm;
}

double cosineSimilarity(int RGBValue1[], int RGBValue2[]){
  //epic comparison algorithm to compare RGB values
  double cosineSimilarity = dotProduct(RGBValue1, RGBValue2)/(vectorNorm(RGBValue1)*vectorNorm(RGBValue2))*1000.0;
  
  return cosineSimilarity;
}

double lengthSimilarity(int RGBValue1[], int RGBValue2[]){
  //epic comparison algorithm to compare RGB values
  double norm1 = vectorNorm(RGBValue1);
  double norm2 = vectorNorm(RGBValue2);
  double lengthSimilarity = 0.0;
  
  if (norm1 == min(norm1, norm2)){
    lengthSimilarity = (norm1/norm2)*1000;
  }
  else{
    lengthSimilarity = (norm2/norm1)*1000;
  }
  
  return lengthSimilarity;
}

double calculateAverage(double a[]){
  //find sum of array element
  double sum = 0.0;
  double b[10];
  for (int i=0; i<10; i++) {
    b[i] = a[i];
  }
  int i = 0;
  double n = sizeof(b)/sizeof(b[0]);
  while(i<n){
    sum += b[i];
    i++;
  }
  return sum/n;
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

//int sockComparer(int ar[][10][3], int bins, int measurements, int lastSockID){ //second parameter should be equal to measurements in main file
  //even more epic comparison algorithm that compares socks with imput the sockDB

int sockMatcher(int lastSockID, double avgcosSimilarities[], double avgLengthSimilarities[], double tresholdCos, double tresholdLength, int bins){
  int i = 0;
  int matchSockID = -1;
  Serial.println(lastSockID);
  Serial.println(matchSockID);
  
  while(i < bins && matchSockID == -1){
    if (i == lastSockID) {
      
    }else {
    Serial.println("Looking for match ");
    Serial.println(i);
    Serial.println("and");
    Serial.println(lastSockID);
    
    Serial.println("with average length similarity of");
    Serial.println(avgLengthSimilarities[i]);

    Serial.println("with average cosine similarity of");
    Serial.println(avgcosSimilarities[i]);
    
    if(avgcosSimilarities[i] > tresholdCos && avgLengthSimilarities[i] > tresholdLength){
      
      matchSockID = i;

      Serial.println("MatchsockID:");
      Serial.println(matchSockID);
    }
  }
    i++;
  }

  if(matchSockID == -1){
    Serial.println("No match");
  }
  else{
    Serial.println("Match");
  }
  return matchSockID;
}

void clearBin(int sockDB[][3], int measurements) {
  Serial.println("Clearing bin...");
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
