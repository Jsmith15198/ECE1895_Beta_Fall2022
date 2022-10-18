#define tenSeg8 5
#define tenSeg4 6
#define tenSeg2 7
#define tenSeg1 8
#define oneSeg8 9
#define oneSeg4 10
#define oneSeg2 11
#define oneSeg1 12
#define LED1 0
#define LED2 1
#define LED3 2
#define tilt 3
#define hall 4
#define flexSensor A0
#define accelSDA A4
#define accelSCL A5

// Setup function for all inputs/outputs
void setup() {
  Serial.begin(9600); // Initialize serial with 9600 baud
  pinMode(LED1, OUTPUT); // LED1 is an output for command 1
  pinMode(LED2, OUTPUT); // LED2 is an output for command 2
  pinMode(LED3, OUTPUT); // LED3 is an output for command 3
  pinMode(tenSeg8, OUTPUT); // Tens digit for binary 3
  pinMode(tenSeg4, OUTPUT); // Tens digit for binary 2
  pinMode(tenSeg2, OUTPUT); // Tens digit for binary 1
  pinMode(tenSeg1, OUTPUT); // Tens digit for binary 0
  pinMode(oneSeg8, OUTPUT); // Ones digit for binary 3
  pinMode(oneSeg4, OUTPUT); // Ones digit for binary 2 
  pinMode(oneSeg2, OUTPUT); // Ones digit for binary 1 
  pinMode(oneSeg1, OUTPUT); // Ones digit for binary 0 
  pinMode(tilt, INPUT); // Tilt ball is input
  pinMode(flexSensor, INPUT); // Flex sensor is input
}

// Loop for the bop-it
void loop() {
  displayScore(0); // Initalizes the 7-segment displays to read "00"
  if(digitalRead(tilt) == HIGH) { // Starts the game when the bottle is tilted
    int score = 0; // Sets the initial score of the game to 0
    displayScore(0); // Resets score to "00" from prior game (if applicable) or just stays at "00" for first game
    bool lose = false; // Turns to true if time for response expires or wrong command given

    // Flex sensor configuration
    float VCC = 5; // Arduino powered with 5V VCC
    float R2 = 10000; // 10K resistor in series with flex sensor
    float sensorMinRes = 15000; // Sensor value when flat
    float sensorMaxRes = 25000; // Sensor value when bent at 90 degrees

    // for loop to implement game cycle 
    for(int i = 0; i < 99; i++) {
      int timer = 3000 - (i * 20); // Timer set a 3 seconds for 1st command and decreases by 20 ms for each subsequent command
      unsigned long startTime = millis(); // Start command time
      unsigned long endTime = startTime + timer; // Time to finish command by
      long command = random(1, 4); // Randomizes a command option between 3 different commands

      if(command == 1) { // CHUG IT command
      digitalWrite(LED1, HIGH); // Turns on LED1 to indicate command 1
        while(startTime < endTime) { // Loops as long as the timer doesn't expire        
          if(digitalRead(tilt) == HIGH) { // Correct input
            score++; // Increment score by 1
            displayScore(score); // Updates the score for the user to see
            correctCommand(); // Gives LED sequence for correct command
            break; // Break out of while loop
          }

          else if(flexADCScale(VCC) < 2.5) {  // Command 2 input chosen instead of command 1 input
            lose = true; // Loss boolean turns from false to true to end game
            incorrectCommand(); // Gives LED sequence for incorrect command
            break; // Break out of while loop
          }



          startTime = millis(); // Update current time
        }

        // Scenario in which time expires
        if(startTime >= endTime) {
          lose = true; // Loss boolean turns from false to true to end game
          incorrectCommand(); // Uses the same LED sequence as an incorrect command to show a game loss
        }
        
      }

      else if(command == 2) { // CRUSH IT command
      digitalWrite(LED2, HIGH); // Turns on LED2 to indicate command 2
        while(startTime < endTime) { // Loops as long as the timer doesn't expire
          if(digitalRead(tilt) == HIGH) { // Command 1 input chosen instead of command 2 input
            lose = true; // Loss boolean turns from false to true to end game
            incorrectCommand(); // Gives LED sequence for incorrect command
            break; // Break out of while loop
          }

          else if(flexADCScale(VCC) < 2.5) {  // Correct input
            score++; // Increment score by 1
            displayScore(score); // Updates the score for the user to see
            correctCommand(); // Gives LED sequence for correct command
            break; // Break out of while loop
          }



          startTime = millis(); // Update current time
        }

        // Scenario in which time expires
        if(startTime >= endTime) {
          lose = true; // Loss boolean turns from false to true to end game
          incorrectCommand(); // Uses the same LED sequence as an incorrect command to show a game loss
        }
      }

      else if(command == 3) { // FILL IT command
      digitalWrite(LED3, HIGH); // Turns on LED3 to indicate command 3
        while(startTime < endTime) { // Loops as long as the timer doesn't expire
          if(digitalRead(tilt) == HIGH) { // Command 1 input chosen instead of command 3 input
            lose = true; // Loss boolean turns from false to true to end game
            incorrectCommand(); // Gives LED sequence for incorrect command
            break; // Break out of while loop
          }

          else if(flexADCScale(VCC) < 2.5) {  // Command 2 input chosen instead of command 3 input
            lose = true; // Loss boolean turns from false to true to end game
            incorrectCommand(); // Gives LED sequence for incorrect command
            break; // Break out of while loop
          }



          startTime = millis(); // Update current time
        }

        // Scenario in which time expires
        if(startTime >= endTime) {
          lose = true; // Loss boolean turns from false to true to end game
          incorrectCommand(); // Uses the same LED sequence as an incorrect command to show a game loss
        }
      }

      if(lose) break; // Break out of for loop if incorrect command is given; ends game
    }

    if(!lose) maxScore(); // // Gives LED sequence for achieving the maximum score of 99

  } // End of game; play again by tilting the bottle

}

// Function to determine the ADC value from the flex sensor
float flexADCScale(float VCC) {
  int ADCRaw = analogRead(flexSensor); // Read analog from pin A0
  float ADCVoltage = (ADCRaw * VCC) / 1023; // Scale analog with voltage divider formula
  return ADCVoltage;
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

// Function for LED light up for correct command
void correctCommand() {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(250);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  delay(250);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(250);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  delay(250);
  digitalWrite(LED2, LOW);
}

// Function for LED light up for incorrect command
void incorrectCommand() {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(500);
  digitalWrite(LED3, LOW);
  delay(500);
  digitalWrite(LED2, LOW);
  delay(500);
  digitalWrite(LED1, LOW);
  delay(500);
}

// Function for LED light up for max score 99
void maxScore() {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(400);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(100);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(400);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(100);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(400);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(100);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(400);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(100);
}
