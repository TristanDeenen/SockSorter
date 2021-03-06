int IRSensor = 23; // connect ir sensor to arduino pin 2

void setup() 
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  Serial.begin(9600);
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);  // 1 means no object in front, 0 means object in front

  Serial.println(statusSensor);
  delay(200);                                   // delay to stabilize the sensor 
}
