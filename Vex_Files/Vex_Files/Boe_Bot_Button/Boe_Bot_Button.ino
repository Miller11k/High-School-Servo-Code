#include <Servo.h>        //include servo motor library
#define BUTTON 4

Servo servoLeft;          // Define left servo
Servo servoRight;         // Define right servo

int val = 0;              //Sets val to 0

void setup() { 
  servoLeft.attach(10);  // Set left servo to digital pin 10
  servoRight.attach(9);  // Set right servo to digital pin 9
  pinMode(BUTTON, INPUT);
} 

void loop(){ 
val = digitalRead(BUTTON);

  if (val == 1){
    reverse();
    turnII();
  } else {
    forward();
  }
}

void turnI() {                         // Tells servo what to do when turnI occurs in code
  servoLeft.write(0);             // Moves left wheel forward
  servoRight.write(0);          // Moves left wheel backwards
  delay (900);                      // Tells servo how long to turn for
}

void turnII() {                   // Tells servo what to do when turnII occurs in code
  servoLeft.write(180);        // Moves left wheel forward
  servoRight.write(180);     // Moves right wheel backwards
  delay (680);            // Tells servo how long to turn for
}
void forward() {                   // Tells servo what to do when forward occurs in code
servoLeft.write(0);              // Moves left wheel forward
  servoRight.write(178);    // Moves right wheel forward
}
void reverse(){
  servoLeft.write(178);
  servoRight.write(0);
  delay(1000);
}

