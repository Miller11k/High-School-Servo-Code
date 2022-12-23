#include <Servo.h>        //include servo motor library
int trigPin = 11; //Trig - green Jumper
int echoPin = 12; //Echo - yellow Jumper
long duration, cm, inches; //Tells units of length
Servo claw;



void setup() {
  claw.attach(10);
  //Serial Port begin 
  Serial.begin (9600); // Sets a serial port value
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT); // Trig is output and sound waves come out of trig
  pinMode(echoPin, INPUT); //Echo is input and recieves waves after a period of time
}

void loop() {
digitalWrite(trigPin, LOW); // Trig starts off
delayMicroseconds(5); //Wait five microseconds
digitalWrite(trigPin, HIGH); // Trig pin on
delayMicroseconds(10); // Wait ten microseconds
digitalWrite(trigPin, LOW); // Trig pin off
// Read the signal from the sensor:wef a HIGH pulse whose
// Read the signal from the sensor:wef a HIGH pulse whose
// duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object
duration = pulseIn(echoPin, HIGH); // Echo pin is on
// convert the time into a distance
cm = (duration/2) / 29.1; // Converts time to cm value
Serial.print(cm); //Prints cm value
Serial.print("cm"); // Prints “cm
Serial.println(); // Prints out results to the serial reader
 
 if(cm < 15) {
  Open();
  delay(1500);
  Close();
}
}

void Open() {
  claw.write(120);
}

void Close() {
  claw.write(60);
}