#include "Rollerband_servo.h"
#include <Servo.h>

void rollerbandInit(int servoPin, Servo myServo){
  myServo.attach(servoPin);
}

void rollerbandStart(int rollerband_speed, Servo myServo){
  myServo.write(rollerband_speed);
}

void rollerbandStop(, Servo myServo){
  myServo.write(90);
}
