#include <Servo.h>
Servo arm;
Servo claw;



void setup() {
  arm.attach(11);
}

void loop() { 
  armUp();
  delay(1000);

  armDown();
  delay(1500);
}


void Stop() {
  arm.write(90);
}


void armUp() {
  arm.write(60);
}

void armDown() {
  arm.write(120);
}