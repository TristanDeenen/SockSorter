#include "Rollerband_servo.h"

void rollerbandToggle(bool rollerbandStop){
  int rollerband_speed = 0;

  myservo.write(rollerband_speed);
}
