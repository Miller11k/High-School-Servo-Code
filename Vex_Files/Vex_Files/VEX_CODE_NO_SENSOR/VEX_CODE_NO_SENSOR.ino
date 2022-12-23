// This is Vex Code for use of void libraries and stuff like that
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

  analogWrite(pwm_a,100); 
  analogWrite(pwm_b,100); 

}

void loop() {
  forward();
  backward();
}

void forward() {
  digitalWrite(dir_a,HIGH); 
  digitalWrite(dir_b,HIGH);
  analogWrite(pwm_a,255); 
  analogWrite(pwm_b,255); 
  delay(5000); 

}

void backward() {
  digitalWrite(dir_a,LOW); 
  digitalWrite(dir_b,LOW);
  analogWrite(pwm_a,255); 
  analogWrite(pwm_b,255); 
  delay(5000); 

}

void turnI() {
  digitalWrite(dir_a,HIGH); 
  digitalWrite(dir_b,LOW);
  analogWrite(pwm_a,255); 
  analogWrite(pwm_b,255); 
  delay(5000); 

}

void turnII() {
  digitalWrite(dir_a,LOW); 
  digitalWrite(dir_b,HIGH);
  analogWrite(pwm_a,255); 
  analogWrite(pwm_b,255); 
  delay(5000); 

}