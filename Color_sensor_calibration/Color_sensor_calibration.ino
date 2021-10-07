#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int frequency = 0;
int oldfrequency = 0;

int red_upper_lim = 0;
int red_lower_lim= 0;
int blue_upper_lim= 0;
int blue_lower_lim= 0;
int green_upper_lim= 0;
int green_lower_lim= 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}

void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  
  red_upper_lim = upperLimitTest(frequency,oldfrequency);
  Serial.print("R= ");//printing name
  Serial.print(red_upper_lim);//printing RED color frequency
  Serial.println("  ");
  delay(100);
  oldfrequency = frequency;

  /*
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(100);
  */
}

int upperLimitTest(int frequency, int oldfrequency){
  int upper_lim = 0;
  
  if(frequency > oldfrequency){
     upper_lim = frequency;
  }
  else{
    upper_lim = oldfrequency;
  }
  return upper_lim; 
}
