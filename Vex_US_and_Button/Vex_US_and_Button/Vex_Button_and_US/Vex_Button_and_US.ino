int trigPin = 12; //Trig - green Jumper
int echoPin = 13; //Echo - yellow Jumper
long duration, cm, inches; //Tells units of length
#define BUTTON 7  //Sets the button input to be in the 7th pin

int pwm_a = 3; //PWM control for motor outputs 1 and 2
int pwm_b = 11; 
int dir_a = 2; //dir tells the direction of the wheels
int dir_b = 4; 
int val = 1;  //Sets val to 1

void setup() {
  pinMode(pwm_a,OUTPUT); //Sets pwm_a as an output
  pinMode(pwm_b,OUTPUT); 
  pinMode(dir_a,OUTPUT);
  pinMode(dir_b,OUTPUT);
  analogWrite(pwm_a,100); 
  analogWrite(pwm_b,100);
  pinMode(BUTTON, INPUT);  //Sets the button to be an input

    //Serial Port begin 
Serial.begin (9600); // Sets a serial port value
//Define inputs and outputs
pinMode(trigPin, OUTPUT); // Trig is output and sound waves come out of trig
pinMode(echoPin, INPUT); //Echo is input and recieves waves after a period of time
} 

void loop() {
val = digitalRead(BUTTON);  // Tells the button to be read as on or off
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
 
if (val == 0 && cm > 30){ //If button is pressed and the distance is greater than 30cm
    backward();
    delay(500);
    left();
    delay(780);
    forward();
    delay(500);
  } else if (val == 0 && cm < 30){ //If the button is pressed and the distance is less than 30cm
   backward();
    delay(500);
    right();
    delay(850);
    forward();
    delay(750);
  }  else{
    forward();
  }

 
 
}

void forward() {  //Tells Vex what to do when "forward();" occurs in code
  digitalWrite(dir_a,HIGH); //Makes A wheel go forward
  digitalWrite(dir_b,HIGH); //Makes B wheel go forward
  analogWrite(pwm_a,255);  //Sets the A wheel speed to go fast
  analogWrite(pwm_b,255);  //Sets the B wheel speed to go fast
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
