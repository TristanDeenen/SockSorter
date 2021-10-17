#include "Support.h"
#include "Extra.h"

int x = 5;

void setup() {
  Serial.begin(9600);
  Serial.print("This is the setup");
  int sockDB[5][10][3];
}

  void fillArray(int arr[][][], int bins, int measurements) {
   for(int i = 0; i < bins; i++) {
    for(int j = 0; j < measurements; j++) {
      for(int k = 0; k < 3; k++) {
        arr
      }
    }
   }
 }

void loop() {
  //printExtra();
  //delay(500);
  //Serial.print("This is the loop");
  //delay(500);
}
