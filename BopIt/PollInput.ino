void PollInput() {
  // 1 = Strum, 2 = Fret, 3 = Whammy
  
  int fretButtonState = digitalRead(Fret); // read from fret signal
  int whammyButtonState = analogRead(Whammy); // read from whammy signal
  int Strum1ButtonState = digitalRead(StrumSw1); // read from the first strum signal
  int Strum2ButtonState = digitalRead(StrumSw2); // read from the second strum signal
    
  if(Strum1ButtonState == LOW) { // if the first strum is triggered...
    inputHandler(currTask == 1); // check if accurate
//    lcd.clear();
//    lcd.print("Strum1"); // Print the score
  }

  if(Strum2ButtonState == LOW) { // if the second strum is triggered...
    inputHandler(currTask == 1); // check if accurate
//    lcd.clear();
//    lcd.print("Strum2"); // Print the score
  }

  if(fretButtonState == LOW) { // if the fret is triggered...
    inputHandler(currTask == 2); // check if accurate
//    lcd.clear();
//    lcd.print("Fret"); // Print the score
  }

  if(whammyButtonState < 500) { // if the whammy is triggered...
    inputHandler(currTask == 3); // check if accurate
//    lcd.clear();
//    lcd.print("Whammy"); // Print the score
  }
  delay(1);
}