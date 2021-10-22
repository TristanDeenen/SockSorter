#include <Servo.h>

Servo servo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

void setup(){
  servo.attach(8);  // attaches the servo on pin 9 to the servo object
}

void loop(){

  servo.write(180);
  //tell servo to go either forwards or backwards by sending a value between 0 to 180
 
}
