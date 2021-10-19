/** Main class using facade design pattern. All implementation is given in the Main.
 *  
 */
#include "Color_Sensor.h"
#include "IR_Sensor.h"
//#include "SockComparer.h"
#include "SockScanner.h"
#include "Rollerband_servo.h"
#include <Servo.h>

//Define pins on Arduino. Might be changed later
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#define irPin 69 // TODO CHANGE
#define rollerband_servo_pin 420 // TODO CHANGE
#define rollerband_speed 75
#define bins 5
#define measurements 10
int sockDB[bins][measurements][3];


void setup() {
  Serial.begin(9600);
  setupColorSensor(S0, S1, S2, S3, sensorOut);
  pinMode (irPin, INPUT);
  
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
}

 // Main loop after setup is finished
 void loop(){

  //Check for a sock
  if (sockUnderSensor(irPin)){
    //Get measurements
    //createSockID(sockDB[0], measurements, S2, S3, sensorOut);
    //compareSocks(); //TODO function does not exist yet

    // Move the correct bin into output position
   // moveBin();
   
  }
  delay(250); //TODO finetune
 }
