int IRSensor = 2; // connect ir sensor to arduino pin 2




void setup() 
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
   Serial.begin(9600);
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);
  
//  if (statusSensor == 1){
//    Serial.println("too close");
//  }
//  
//  else
//  {
//     Serial.println("too far");
//  }
//  delay(200);
Serial.println(statusSensor);
delay(200);
}
