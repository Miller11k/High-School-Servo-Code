#define BUTTON 7 // input pin of the pushbutton

int val = 0; // stores the state of input value

int state = 0;  // 0 = LED off while 1 = LED on
void setup()
{
  pinMode(10, OUTPUT);  //Sets pin 3 as an output (Green)
  pinMode(11, OUTPUT); // Sets pin 5 as an output (Red)
  pinMode(9, OUTPUT);  //Sets pin 6 as an output (Blue)
}

void loop() {
  
  if (val == HIGH){  // If distance (cm) is greater than 15
    digitalWrite(11, HIGH);  // Turn RGB LED Green
    digitalWrite(10, LOW);
    delay(5000);
  } else {  //Otherwise...
    digitalWrite(11, LOW);  //Keep RGB LED not green (ends up red because Blue is always off)
    digitalWrite(10, HIGH);
  }
 }