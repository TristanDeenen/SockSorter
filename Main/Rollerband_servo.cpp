#include "Rollerband_servo.h"
#include <Servo.h>

void rollerbandInit(int servoPin){
  Servo myservo;
  myservo.attach(servoPin);
}

void rollerbandStart(int rollerband_speed){
  myservo.write(rollerband_speed);
}

void rollerbandStop(){
  myservo.write(90);
}
