#ifndef ROLLERBAND_SERVO_H
#define ROLLERBAND_SERVO_H
#include <Arduino.h>
#include <Servo.h>

void rollerbandInit(int servoPin, Servo myServo);
void rollerbandStart(int rollerband_speed, Servo myServo);
void rollerbandStop(Servo myServo);

#endif
