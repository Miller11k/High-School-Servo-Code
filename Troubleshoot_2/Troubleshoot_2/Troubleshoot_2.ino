#include <Servo.h>

Servo arm;

Servo claw;



void setup()
{
  arm.attach(11);
  claw.attach(10);
}

void loop() { 
  clawOpen();
  delay(1500);

  clawClose();
  delay(1500);
}


void armStop() {
  arm.write(0);
}


void armUp() {
  arm.write(60);
}

void armDown() {
  arm.write(120);
}

void clawClose() {
  claw.write(80);
}

void clawOpen() {
  claw.write(120);
}
