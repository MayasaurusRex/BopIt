void inputHandler(bool correct) {
  
  if (correct) { // if the user entered in the correct input
    score = score + 1; // increment the score
    
    lcd.setCursor(3, 0); // Set the cursor on the LCD
    lcd.print("Success!"); // Print the string "Success"
    lcd.setCursor(2, 1); // Set the cursor on the LCD
    lcd.print("Score: " + String(score)); // Print the score

    digitalWrite(GreenLED, HIGH); // turn on green LED
    digitalWrite(RedLED, LOW); // turn off red LED
    delay(50);

    count = originalCount - (10*score); // update time based on score
    
    ChooseTask(); // choose new task
  }
  else {
    lcd.setCursor(3, 0); // Set the cursor on the LCD
    lcd.print("You Lose!"); // Print the string "Lost"
    lcd.setCursor(2, 1); // Set the cursor on the LCD
    lcd.print("Score: " + String(score)); // Print the score
      
    digitalWrite(GreenLED, LOW); // turn off green LED
    digitalWrite(RedLED, HIGH); // turn on red LED
    delay(50);
  }
}
