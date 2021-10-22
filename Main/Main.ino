/** Main class using facade design pattern. All implementation is given in the Main.
 *  
 */
#include "Color_Sensor.h"
#include "IR_Sensor.h"
#include "SockComparer.h"
#include "SockScanner.h"
#include "Rollerband_servo.h"
#include <Servo.h>

//Define pins on Arduino. Might be changed later
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#define irPin 23// TODO CHANGE
#define rollerband_servo_pin 420 // TODO CHANGE
#define rollerband_speed 75
#define bins 5
#define measurements 10
#define treshold 0.75
int sockDB[bins][measurements][3];


void setup() {
  Serial.begin(9600);
  setupColorSensor(S0, S1, S2, S3, sensorOut);
  pinMode(irPin, INPUT);
  
  Servo myServo;
  rollerbandInit(rollerband_servo_pin, myServo);
  rollerbandStart(rollerband_speed, myServo); //TODO slightly inefficient solution, might change later

  for(int i = 0; i < bins; i++) {
    for(int j = 0; j < measurements; j++) {
      for(int k = 0; k < 3; k++) {
        sockDB[i][j][k] = -1; //WARNING -1 PLACEHOLDER
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
    int lastID = lastSockIDfinder(sockDB, bins);
    int freshID = lastID + 1;
    
    createSockID(sockDB[freshID], measurements, S2, S3, sensorOut);

    int newID = lastSockIDfinder(sockDB, bins);
    Serial.println(newID);
    int avgcosSimilarities = sockComparer(sockDB, bins, measurements, newID);
    Serial.println("uuuuuuu");
    int matchSockID = sockMatcher(newID, avgcosSimilarities, treshold);
    Serial.println(matchSockID);

    // Move the correct bin into output position
   // moveBin() or beeper();
   Serial.println("yyyyyy");
   
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
