#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
#include <Servo.h>
#define rollerband_servo_pin 8

int red_frequency = 0;
int green_frequency = 0;
int blue_frequency = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  Servo myServo;
  myServo.attach(rollerband_servo_pin);
  myServo.write(90);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}

void loop() {
  red_frequency = readRedFrequency();
  delay(100);
  green_frequency = readGreenFrequency();
  delay(100);
  blue_frequency = readBlueFrequency();
  delay(100);
  
  Serial.print("R= ");//printing name
  Serial.print(red_frequency);//printing RED color frequency
  Serial.print("  ");
  
  Serial.print("G= ");//printing name
  Serial.print(green_frequency);//printing RED color frequency
  Serial.print("  ");
  
  Serial.print("B= ");//printing name
  Serial.print(blue_frequency);//printing RED color frequency
  Serial.println("  ");

}

int readRedFrequency(){
  int frequency = 0;
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remapping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 20,177,255,0);
  return frequency;
}

int readGreenFrequency(){
  int frequency = 0;
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 30,250,255,0);
  return frequency;
}

int readBlueFrequency(){
  int frequency = 0;
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 35,200,255,0);
  return frequency;
}
