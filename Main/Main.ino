/** Main class using facade design pattern. All implementation is given in the Main.
 *  
 */
#include "Color_Sensor.h"
#include "IR_Sensor.h"
#include "SockComparer.h"
#include "SockScanner.h"
#include "Rollerband_servo.h"
#include "Beeper.h"
#include <Servo.h>

//Define pins on Arduino
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
#define buzzerPin 22
#define irPin 23
#define rollerband_servo_pin 8
#define rollerband_speed 70
#define bins 5
#define measurements 10
#define tresholdCos 500
#define tresholdLength 500
#define delay_time_buzzer 1000
int sockDB[bins][measurements][3];


void setup() {
  Serial.begin(9600);
  setupColorSensor(S0, S1, S2, S3, sensorOut);
  pinMode(irPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin,HIGH);
  
  Servo myServo;
 rollerbandInit(rollerband_servo_pin, myServo);
  rollerbandStart(rollerband_speed, myServo);

  for(int i = 0; i < bins; i++) {
    for(int j = 0; j < measurements; j++) {
      for(int k = 0; k < 3; k++) {
        sockDB[i][j][k] =  -1000;       
      }
    }
  }
}

 // Main loop after setup is finished
 void loop(){
  
  //Check for a sock
  if (sockUnderSensor(irPin)){
    delay(500);
    //Get measurements
    int newID = findEmptyEntry(sockDB, bins);
    createSockID(sockDB[newID], measurements, S2, S3, sensorOut);

    // int newID = lastSockIDfinder(sockDB, bins); //TODO not correct way of finding new sockID entry
    //int avgcosSimilarities = sockComparer(sockDB, bins, measurements, newID);

    double avgcosSimilarities[bins];
    double avglengthSimilarities[bins];
  
    for (int i = 0; i < bins; i++){
      avgcosSimilarities[i] = 0;
      avglengthSimilarities[i] = 0;
    }

    int q = 0; // bins
    while(q < bins){
      double cosSimilarities[measurements];
      double lengthSimilarities[measurements];
      
      int i = 0;
      while(i < measurements){
        cosSimilarities[i] = cosineSimilarity(sockDB[newID][i], sockDB[q][i]);
        lengthSimilarities[i] = lengthSimilarity(sockDB[newID][i], sockDB[q][i]);
              Serial.println("cossimilarity");
      Serial.println(cosSimilarities[i]);
        i++;
      }
      avgcosSimilarities[q] = calculateAverage(cosSimilarities);
      avglengthSimilarities[q] = calculateAverage(lengthSimilarities);
      /*Serial.println(q);
      Serial.println("avgcossimilarity");
      Serial.println(avgcosSimilarities[q]);
      Serial.println("avglengthsimilarity");
      Serial.println(avglengthSimilarities[q]);*/
      q++;
    }

    /*double a[2];
    for(int i = 0; i < 2; i++){
      a[i] = avgcosSimilarities[i];
    }

    for(int i = 0; i < 2; i++){
      Serial.println("nieuwe test ouleh");
      Serial.println(i);
      Serial.println("avgcossimilarity");
      Serial.println(avgcosSimilarities[i]);
      Serial.println("avglengthsimilarity");
      Serial.println(avglengthSimilarities[i]);
      
    }*/
    
    int matchSockID = sockMatcher(newID, avgcosSimilarities, avglengthSimilarities, tresholdCos, tresholdLength, bins);
    if (matchSockID != -1) {
      clearBin(sockDB[matchSockID], measurements);
      clearBin(sockDB[newID], measurements);
      beeper(buzzerPin, matchSockID + 1, delay_time_buzzer);
    } else {
      beeper(buzzerPin, newID + 1, delay_time_buzzer);
    }
  
    // Beep the correct bin
   Serial.println("beeper beep boop");
   Serial.println(matchSockID + 2);
   Serial.println(" matchSockID " );

 
   /*for(int i = 0; i < bins; i++) {
      for(int j = 0; j < measurements; j++) {
        for(int k = 0; k < 3; k++) {
          if (sockDB[i][j][k] != -1000) {
          Serial.println(sockDB[i][j][k]);        
          }
        }
      }
    Serial.print("NEW ENTRY");
    }*/
    delay(2000);  
  }
 }
