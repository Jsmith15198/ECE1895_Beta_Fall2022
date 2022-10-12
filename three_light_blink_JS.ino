#define toggle 9
#define LED1 13
#define LED2 12
#define LED3 11

// Setup function
void setup() {
  pinMode(toggle, INPUT); // SPST is an input
  pinMode(LED1, OUTPUT); // LED1 is an output
  pinMode(LED2, OUTPUT); // LED2 is an output
  pinMode(LED3, OUTPUT); // LED3 is an output
}

// Loop 3 LEDs turing ON and OFF based on toggle
void loop() {
  if(digitalRead(toggle) == HIGH) {
    digitalWrite(LED1, HIGH); // LED1 turns ON when toggle is pressed
    delay(1000); // Wait 1 second
    digitalWrite(LED1, LOW); // LED1 turns OFF when toggle is pressed
    delay(1000); // Wait 1 second
    digitalWrite(LED2, HIGH); // LED2 turns ON when toggle is pressed
    delay(1000); // Wait 1 second
    digitalWrite(LED2, LOW); // LED2 turns OFF when toggle is pressed
    delay(1000); // Wait 1 second
    digitalWrite(LED3, HIGH); // LED3 turns ON when toggle is pressed
    delay(1000); // Wait 1 second
    digitalWrite(LED3, LOW); // LED3 turns OFF when toggle is pressed
    delay(1000); // Wait 1 second
  }
}

//Comment edit from Quincy
//Comment edit from Caileigh
