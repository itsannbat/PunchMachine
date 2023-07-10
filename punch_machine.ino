#include <Servo.h>
int incomingByte = 0; // for incoming serial data

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

bool isClosed = true;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(13, "INPUT");
  Serial.begin(9600);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    if(incomingByte == 'c'){
      isClosed = true;
    } else if (incomingByte == 'o'){
      isClosed = false;
    }
  }
  if(isClosed){
    myservo.write(90);
  } else {
    myservo.write(0);
  }
}
