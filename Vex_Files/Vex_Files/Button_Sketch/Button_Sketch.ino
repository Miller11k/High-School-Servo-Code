#define BUTTON_PIN 2

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);       // on-board LED, usually pin 13
  pinMode(BUTTON_PIN, INPUT);         // push button pin set to input
}

void loop() {
  if (digitalRead(BUTTON_PIN)) {       // switch closed?
    // switch closed with pull-down resistor
    delay(40);                        // switch debounce delay
    while (digitalRead(BUTTON_PIN));  // wait for switch to open
    digitalWrite(LED_BUILTIN, HIGH);  // switch LED on
    delay(2000);                      // leave LED on for period
  }
  else {
    // switch open with pull-down resistor
    digitalWrite(LED_BUILTIN, LOW);   // switch LED off
  }
}