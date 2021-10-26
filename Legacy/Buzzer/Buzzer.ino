const int buzzer = 22; //buzzer to arduino pin 9
int delay_time_buzzer = 500;
 
void setup(){
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
}

void loop(){

beeper(5);
delay(3000);
}

void beeper(int count){
  for(int i= 0;i<count;i++){
     digitalWrite(buzzer,LOW);
    delay(delay_time_buzzer);
    digitalWrite(buzzer,HIGH);
    delay(delay_time_buzzer);
  }

}
