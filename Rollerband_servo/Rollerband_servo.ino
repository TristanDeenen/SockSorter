#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

void setup() {
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
}

void loop() {

    myservo.write(0);              //tell servo to go either forwards or backwards by sending a value between 0 to 180
 
}
