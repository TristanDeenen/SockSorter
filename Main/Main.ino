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

//Define pins on Arduino. Might be changed later
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#define buzzerPin 2
#define irPin 23// TODO CHANGE
#define rollerband_servo_pin 8 // TODO CHANGE
#define rollerband_speed 75
#define bins 5
#define measurements 10
#define treshold 0.75
#define delay_time_buzzer 1
int sockDB[bins][measurements][3];


void setup() {
  Serial.begin(9600);
  setupColorSensor(S0, S1, S2, S3, sensorOut);
  pinMode(irPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Servo myServo;
  rollerbandInit(rollerband_servo_pin, myServo);
  rollerbandStart(rollerband_speed, myServo); //TODO slightly inefficient solution, might change later

  for(int i = 0; i < bins; i++) {
    for(int j = 0; j < measurements; j++) {
      for(int k = 0; k < 3; k++) {
        sockDB[i][j][k] =   000;
        Serial.println(sockDB[i][j][k]);        
      }
    }
  }

  delay(10000);
  Serial.println("xxxxxx");
}

 // Main loop after setup is finished
 void loop(){
  
  //Check for a sock
  if (sockUnderSensor(irPin)){
    //Get measurements
    int newID = findEmptyEntry(sockDB, bins);

    //rollerbandStop(myServo);
    //rollerbandStart(rollerband_speed, myServo);
    
    createSockID(sockDB[newID], measurements, S2, S3, sensorOut);

    // int newID = lastSockIDfinder(sockDB, bins); //TODO not correct way of finding new sockID entry
    int avgcosSimilarities = sockComparer(sockDB, bins, measurements, newID);
    int matchSockID = sockMatcher(newID, avgcosSimilarities, treshold);
    if (matchSockID != NULL) {
      clearBin(sockDB[matchSockID], measurements);
      clearBin(sockDB[newID], measurements);
    }

    // Move the correct bin into output position
   // moveBin() or beeper();
   Serial.println("yyyyyy");
   beeper(buzzerPin, matchSockID, delay_time_buzzer);
 
       for(int i = 0; i < bins; i++) {
        for(int j = 0; j < measurements; j++) {
          for(int k = 0; k < 3; k++) {
            Serial.println(sockDB[i][j][k]);        
          }
        }
      }
      
   delay(10000);  
  }
  delay(250); //TODO finetune
 }
