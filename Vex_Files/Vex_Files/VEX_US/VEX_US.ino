int trigPin = 12; //Trig - green Jumper
int echoPin = 13; //Echo - yellow Jumper
long duration, cm, inches; //Tells units of length

int pwm_a = 3; //PWM control for motor outputs 1 and 2
int pwm_b = 11; 
int dir_a = 2; 
int dir_b = 4; 
int val = 0; 

void setup() {
  pinMode(pwm_a,OUTPUT); 
  pinMode(pwm_b,OUTPUT); 
  pinMode(dir_a,OUTPUT);
  pinMode(dir_b,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,INPUT);
  
  analogWrite(pwm_a,100); 
  analogWrite(pwm_b,100); 

    //Serial Port begin 
Serial.begin (9600); // Sets a serial port value
//Define inputs and outputs
pinMode(trigPin, OUTPUT); // Trig is output and sound waves come out of trig
pinMode(echoPin, INPUT); //Echo is input and recieves waves after a period of time
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


if (cm > 75){
  backward();
  delay(100);
  right();
  delay(250);
  forward();
 } else if (cm < 50) {
  backward();
  delay(100);
  left();  //Turn away from surface bumped
  delay(250);
  forward();
 } else {     //Tells Vex what to do if button is not pressed
   forward();  //Tells Vex to go straight
 }
}

void forward() {  //Tells Vex what to do when "forward();" occurs in code
  digitalWrite(dir_a,HIGH); //Makes A wheel go forward
  digitalWrite(dir_b,HIGH); //Makes B wheel go forward
  analogWrite(pwm_a,255);  //Sets the A wheel speed to go fast
  analogWrite(pwm_b,255);  //Sets the B wheel speed to go fast
  delay(100);
}

void backward() { //Tells Vex what to do when "backward();" occurs in code
  digitalWrite(dir_a,LOW); //Makes the A wheel go backwards
  digitalWrite(dir_b,LOW); //Makes the B wheel go backwards
  analogWrite(pwm_a,255);  //Sets the A wheel speed to go fast
  analogWrite(pwm_b,255);  //Sets the B wheel speed to go fast

}

void right() { //Tells Vex what to do when "turnI();" occurs in code
  digitalWrite(dir_a,HIGH); //Makes A wheel go forward
  digitalWrite(dir_b,LOW);  //Makes the B wheel go backwards
  analogWrite(pwm_a,255);  //Sets the A wheel speed to go fast
  analogWrite(pwm_b,255);  //Sets the B wheel speed to go fast

}

void left() { //Tells Vex what to do when "turnII();" occurs in code
  digitalWrite(dir_a,LOW);  //Makes the A wheel go backwards
  digitalWrite(dir_b,HIGH); //Makes B wheel go forward
  analogWrite(pwm_a,255);  //Sets the A wheel speed to go fast
  analogWrite(pwm_b,255);  //Sets the B wheel speed to go fast

}

void recenter_left() {
  digitalWrite(dir_a,HIGH);
  digitalWrite(dir_b,HIGH);
  analogWrite(pwm_a,125);
  analogWrite(pwm_b,255);
}

void recenter_right() {
  digitalWrite(dir_a,HIGH);
  digitalWrite(dir_b,HIGH);
  analogWrite(pwm_a,255);
  analogWrite(pwm_b,125);
}