#include "IR_Sensor.h"

//WARNING, now prints values for IR, comment out per function to disable!

bool sockUnderSensor(int irSensorPin) {
  int statusSensor = digitalRead (irSensorPin);  // 1 means no object in front, 0 means object in front
  Serial.println(statusSensor);
  delay(200);                                   // delay to stabilize the sensor
  if (statusSensor == 1) {
    return false;
  } else {
    return true;
  }
}
