#define speaker 13

void setup() {
  
}

// Loop for the bop-it
void loop() {
  tone(13, 440);
  delay(500);
  noTone(13);
  delay(500);
  tone(13, 349.23);
  delay(500);
  noTone(13);
  delay(500);
  tone(13, 523.25);
  delay(500);
  noTone(13);
  delay(500);
}

