int trigPin = 11; //Trig - green Jumper
int echoPin = 10; //Echo - yellow Jumper
long duration, cm, inches; //Tells units of length


void setup() { 
Serial.begin (9600); // Sets a serial port value
//Define inputs and outputs
pinMode(trigPin, OUTPUT); // Trig is output and sound waves come out of trig
pinMode(echoPin, INPUT); //Echo is input and recieves waves after a period of time
pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);  
} 

void loop() {
// The sensor is triggered by a HIGH pulse of 10 or more microseconds
// Give a short LOW pulse beforehand to ensure a clean HIGH
pulse:
digitalWrite(trigPin, LOW); // Trig starts off
delayMicroseconds(5); //Wait five microseconds
digitalWrite(trigPin, HIGH); // Trig pin on
delayMicroseconds(10); // Wait ten microseconds
digitalWrite(trigPin, LOW); // Trig pin off
// Read the signal from the sensor: a HIGH pulse whose
// duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object
pinMode(echoPin, INPUT); // Echo pin recieves output waves
duration = pulseIn(echoPin, HIGH); // Echo pin is on
// convert the time into a distance
cm = (duration/2) / 29.1; // Converts time to cm value
 inches = (duration/2) / 74; // Converts time to inch value

 Serial.print(inches); // Prints inches value
 Serial.print("in,"); // Prints “in,”
 Serial.print(cm); //Prints cm value
 Serial.print("cm"); // Prints “cm”
 Serial.println(); // Prints out results to the serial reader 

 if (cm >= 16) { // If distance between sensor and wall is less than 5...
digitalWrite(5,1);
 } else{
digitalWrite(3,1);
}
}