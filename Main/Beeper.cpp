#include "Beeper.h"

void beeper(int count){
  for(int i= 0;i<count;i++){
     digitalWrite(buzzer,LOW);
    delay(delay_time_buzzer);
    digitalWrite(buzzer,HIGH);
    delay(delay_time_buzzer);
  }
}