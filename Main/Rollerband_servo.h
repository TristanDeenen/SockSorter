#ifndef ROLLERBAND_SERVO_H
#define ROLLERBAND_SERVO_H
#include <Arduino.h>

void rollerbandInit(int servoPin);
void rollerbandStart(int rollerband_speed);
void rollerbandStop();

#endif
