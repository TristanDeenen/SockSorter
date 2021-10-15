/** Main class using facade design pattern. All implementation is given in the Main.
 *  
 */
#include "Color_Sensor.h"
#include "IR_Sensor.h"
//#include "SockComparer.h"
#include "SockScanner.h"
//#include ""

//Define pins on Arduino. Might be changed later
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#define irPin 69 // TODO CHANGE

void setup() {
  Serial.begin(9600);
  setupColorSensor(S0, S1, S2, S3, sensorOut);
  pinMode (irPin, INPUT);
}

 void loop(){
 readRedFrequency(S2, S3, sensorOut);
 readGreenFrequency(S2, S3, sensorOut);
 readBlueFrequency(S2, S3, sensorOut);

 Serial.println("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
 int x[] = {1, 2, 3};
 int y[3] = {};
 readRGB(y, S2, S3, sensorOut);
 Serial.println(String(y[0]) + y[1] + y[2] + "BELANGRIJK");
 //int arr[] = readRGB(S2, S3, sensorOut);
 //Serial.println(arr[0] + arr[1] + arr[2] + "BELANGRIJK");

 //Main loop after setup is finished
 //Check for a sock
 if sockUnderSensor(irPin){
   //Turn rollerband

   //Get measurements
 }

 }
