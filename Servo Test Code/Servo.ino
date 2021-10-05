int servoPin = D0;

// declare Servo object variable called "servo"
Servo servo;

void setup() {
    // turn on servo motor
    servo.attach(servoPin);
}

void loop() {
    // stop rotation
    servo.writeMicroseconds(1500);

    // alternate code (use either one but not both)
    // servo.write(90);
}
