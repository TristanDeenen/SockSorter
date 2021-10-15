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
#define rollerband_speed 75

void setup() {
  Serial.begin(9600);
  setupColorSensor(S0, S1, S2, S3, sensorOut);
  pinMode (irPin, INPUT);
  //TODO slightly inefficient solution, might change later
  rollerbandToggle(true); // WARNING FUNCTION INCORRECT: SPEED IS SET AT 0 AND TOGGLE FEATURE NOT IMPLEMENTED YET 
}

 // Main loop after setup is finished
 void loop(){

  //Check for a sock
  if sockUnderSensor(irPin){
    //Get measurements
    createSockID(); //TODO wait on implementation to specify function more
    compareSocks(); //TODO function does not exist yet

    // Move the correct bin into output position
   // moveBin();
   
 }

 }
