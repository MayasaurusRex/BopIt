void inputHandler(bool correct) {
  
  if (correct) { // if the user entered in the correct input
    score = score + 1; // increment the score
    
    lcd.setCursor(3, 0); // Set the cursor on the LCD
    lcd.print("Success!"); // Print the string "Success"
    lcd.setCursor(2, 1); // Set the cursor on the LCD
    lcd.print("Score: " + String(score)); // Print the score

    digitalWrite(GreenLED, HIGH);
    digitalWrite(RedLED, LOW);
    delay(50);

    count = originalCount - (10*score);
    
    ChooseTask(); // choose new task
  }
  else {
    lcd.setCursor(3, 0); // Set the cursor on the LCD
    lcd.print("You Lose!"); // Print the string "Lost"
    lcd.setCursor(2, 1); // Set the cursor on the LCD
    lcd.print("Score: " + String(score)); // Print the score

    Timer1.detachInterrupt(); //disable interrupt
      
    digitalWrite(GreenLED, LOW);
    digitalWrite(RedLED, HIGH);
    delay(50);
  }
}
