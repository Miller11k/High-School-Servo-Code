#define BUTTON 3
int pwm_a = 3; //PWM control for motor outputs 1 and 2
int pwm_b = 11; 
int dir_a = 2; 
int dir_b = 4; 

int val = 1;              //Sets val to 0

void setup() { 
  pinMode(pwm_a,OUTPUT); 
  pinMode(pwm_b,OUTPUT); 
  pinMode(dir_a,OUTPUT);
  pinMode(dir_b,OUTPUT);
  analogWrite(pwm_a,100); 
  analogWrite(pwm_b,100);
  pinMode(BUTTON, INPUT);
} 

void loop(){ 
val = digitalRead(BUTTON);

  if (val == 1){
    backward();
  } else {
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