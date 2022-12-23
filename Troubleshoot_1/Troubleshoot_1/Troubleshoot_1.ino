#include <Servo.h>
Servo arm;
Servo claw;



void setup() {
  arm.attach(10);
  claw.attach(11);
}

void loop() { 
  armUp();
  delay(1500);

  Open();
  delay(1500);

  armDown();
  delay(1500);

  Close();
  delay(1500);
}


void Stop() {
  arm.write(90);
  claw.write(90);
}


void armUp() {
  arm.write(60);
}

void armDown() {
  arm.write(120);
}

void Open() {
  claw.write(120);
}


void Close() {
  claw.write(60);
}