#include "Beeper.h"

void beeper(int buzzer, int count, int delay_time_buzzer){
  for(int i= 0;i<count;i++){
    digitalWrite(buzzer,LOW);
    delay(delay_time_buzzer);
    digitalWrite(buzzer,HIGH);
    delay(delay_time_buzzer);
  }
}
