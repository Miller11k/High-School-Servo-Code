if (cm > 75){
  delay(100);
  right();
  delay(250);
  forward();
 } else if (cm < 50) {
  delay(100);
  left();  //Turn away from surface bumped
  delay(250);
  forward();
 } else {     //Tells Vex what to do if button is not pressed
   forward();  //Tells Vex to go straight
 }
 
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