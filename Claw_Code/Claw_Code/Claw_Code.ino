#include <Servo.h>

Servo arm;

Servo claw;



void setup()
{
  arm.attach(11);
  claw.attach(10);
}

void loop() { 
  armUp();
  delay(1500);

  armStop();
  delay(1000);
  
  
  arm.write(91);
  delay(3000);

  clawOpen();
  delay(2000);

  clawClose();
  delay(2000);

  armDown();
  delay(1500);

  armStop();
  delay(2000);
}


void armStop() {
  arm.write(0);
}


void armUp() {
  arm.write(60);
}

void armDown() {
  arm.write(150);
}

void clawClose() {
  claw.write(80);
}

void clawOpen() {
  claw.write(120);
}
