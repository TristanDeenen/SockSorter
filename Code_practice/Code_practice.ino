#include "Support.h"
#include "Extra.h"

int x = 5;

void setup() {
  Serial.begin(9600);
  Serial.print("This is the setup");
}

void loop() {
  printExtra();
  delay(500);
  Serial.print("This is the loop");
  delay(500);
}
