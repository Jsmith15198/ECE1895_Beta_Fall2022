#define tenSeg8 5
#define tenSeg4 6
#define tenSeg2 7
#define tenSeg1 8
#define oneSeg8 9
#define oneSeg4 10
#define oneSeg2 11
#define oneSeg1 12

// Setup function for all inputs/outputs
void setup() {
  pinMode(tenSeg8, OUTPUT); // Tens digit for binary 3
  pinMode(tenSeg4, OUTPUT); // Tens digit for binary 2
  pinMode(tenSeg2, OUTPUT); // Tens digit for binary 1
  pinMode(tenSeg1, OUTPUT); // Tens digit for binary 0
  pinMode(oneSeg8, OUTPUT); // Ones digit for binary 3
  pinMode(oneSeg4, OUTPUT); // Ones digit for binary 2 
  pinMode(oneSeg2, OUTPUT); // Ones digit for binary 1 
  pinMode(oneSeg1, OUTPUT); // Ones digit for binary 0 
}

bool startup = false;

// Loop for the bop-it
void loop() {
  if(!startup) { // Powers up the 7-segment displays upon starting the program
    displayScore(0); // Initalizes the 7-segment displays to read "00"
    startup = true; // Prevents the loop from occurring again
  }
  
  int score = 0;
  while(score < 99) {
    score++;
    delay(1000);
    displayScore(score);    
  }
}

// Function to display current/final score
void displayScore(int score) {
  int onesPlace = score % 10; // Ones digit
  int tensPlace = (score / 10) % 10; // Tens digit

  if(onesPlace == 0) { // Ones digit is 0; 0000
    digitalWrite(oneSeg8, LOW);
    digitalWrite(oneSeg4, LOW);
    digitalWrite(oneSeg2, LOW);
    digitalWrite(oneSeg1, LOW);
  }  

  if(onesPlace == 1) { // Ones digit is 1; 0001
    digitalWrite(oneSeg8, LOW);
    digitalWrite(oneSeg4, LOW);
    digitalWrite(oneSeg2, LOW);
    digitalWrite(oneSeg1, HIGH);
  }  

  if(onesPlace == 2) { // Ones digit is 2; 0010
    digitalWrite(oneSeg8, LOW);
    digitalWrite(oneSeg4, LOW);
    digitalWrite(oneSeg2, HIGH);
    digitalWrite(oneSeg1, LOW);
  }  

  if(onesPlace == 3) { // Ones digit is 3; 0011
    digitalWrite(oneSeg8, LOW);
    digitalWrite(oneSeg4, LOW);
    digitalWrite(oneSeg2, HIGH);
    digitalWrite(oneSeg1, HIGH);
  }  

  if(onesPlace == 4) { // Ones digit is 4; 0100
    digitalWrite(oneSeg8, LOW);
    digitalWrite(oneSeg4, HIGH);
    digitalWrite(oneSeg2, LOW);
    digitalWrite(oneSeg1, LOW);
  }  

  if(onesPlace == 5) { // Ones digit is 5; 0501
    digitalWrite(oneSeg8, LOW);
    digitalWrite(oneSeg4, HIGH);
    digitalWrite(oneSeg2, LOW);
    digitalWrite(oneSeg1, HIGH);
  }  

  if(onesPlace == 6) { // Ones digit is 6; 0110
    digitalWrite(oneSeg8, LOW);
    digitalWrite(oneSeg4, HIGH);
    digitalWrite(oneSeg2, HIGH);
    digitalWrite(oneSeg1, LOW);
  }  

  if(onesPlace == 7) { // Ones digit is 7; 0111
    digitalWrite(oneSeg8, LOW);
    digitalWrite(oneSeg4, HIGH);
    digitalWrite(oneSeg2, HIGH);
    digitalWrite(oneSeg1, HIGH);
  }  

  if(onesPlace == 8) { // Ones digit is 8; 1000
    digitalWrite(oneSeg8, HIGH);
    digitalWrite(oneSeg4, LOW);
    digitalWrite(oneSeg2, LOW);
    digitalWrite(oneSeg1, LOW);
  }

  if(onesPlace == 9) { // Ones digit is 9; 1001
    digitalWrite(oneSeg8, HIGH);
    digitalWrite(oneSeg4, LOW);
    digitalWrite(oneSeg2, LOW);
    digitalWrite(oneSeg1, HIGH);
  }

  if(tensPlace == 0) { // Tens digit is 0; 0000
    digitalWrite(tenSeg8, LOW);
    digitalWrite(tenSeg4, LOW);
    digitalWrite(tenSeg2, LOW);
    digitalWrite(tenSeg1, LOW);
  }  

  if(tensPlace == 1) { // Tens digit is 1; 0001
    digitalWrite(tenSeg8, LOW);
    digitalWrite(tenSeg4, LOW);
    digitalWrite(tenSeg2, LOW);
    digitalWrite(tenSeg1, HIGH);
  }  

  if(tensPlace == 2) { // Tens digit is 2; 0010
    digitalWrite(tenSeg8, LOW);
    digitalWrite(tenSeg4, LOW);
    digitalWrite(tenSeg2, HIGH);
    digitalWrite(tenSeg1, LOW);
  }  

  if(tensPlace == 3) { // Tens digit is 3; 0011
    digitalWrite(tenSeg8, LOW);
    digitalWrite(tenSeg4, LOW);
    digitalWrite(tenSeg2, HIGH);
    digitalWrite(tenSeg1, HIGH);
  }  

  if(tensPlace == 4) { // Tens digit is 4; 0100
    digitalWrite(tenSeg8, LOW);
    digitalWrite(tenSeg4, HIGH);
    digitalWrite(tenSeg2, LOW);
    digitalWrite(tenSeg1, LOW);
  }  

  if(tensPlace == 5) { // Tens digit is 5; 0501
    digitalWrite(tenSeg8, LOW);
    digitalWrite(tenSeg4, HIGH);
    digitalWrite(tenSeg2, LOW);
    digitalWrite(tenSeg1, HIGH);
  }  

  if(tensPlace == 6) { // Tens digit is 6; 0110
    digitalWrite(tenSeg8, LOW);
    digitalWrite(tenSeg4, HIGH);
    digitalWrite(tenSeg2, HIGH);
    digitalWrite(tenSeg1, LOW);
  }  

  if(tensPlace == 7) { // Tens digit is 7; 0111
    digitalWrite(tenSeg8, LOW);
    digitalWrite(tenSeg4, HIGH);
    digitalWrite(tenSeg2, HIGH);
    digitalWrite(tenSeg1, HIGH);
  }  

  if(tensPlace == 8) { // Tens digit is 8; 1000
    digitalWrite(tenSeg8, HIGH);
    digitalWrite(tenSeg4, LOW);
    digitalWrite(tenSeg2, LOW);
    digitalWrite(tenSeg1, LOW);
  }

  if(tensPlace == 9) { // Tens digit is 9; 1001
    digitalWrite(tenSeg8, HIGH);
    digitalWrite(tenSeg4, LOW);
    digitalWrite(tenSeg2, LOW);
    digitalWrite(tenSeg1, HIGH);
  }
}

