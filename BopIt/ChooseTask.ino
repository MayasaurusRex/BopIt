void ChooseTask() {

  // clear the LCD
  lcd.clear();

  // randomly select task
  // 1 = Strum, 2 = Fret, 3 = Whammy
  currTask = random(1, 4);

  // display task on LCD
  if (currTask == 1) { // If the random task is strum
    lcd.setCursor(4, 0); // Set the cursor on the LCD
    lcd.print("Strum!"); // Print the string "Strum"
    tone(Buzzer, NOTE_C7); // play the corresponding tone
    delay(50);
    noTone(Buzzer);

  } else if (currTask == 2) { // If the random task is fret
    lcd.setCursor(4, 0); // Set the cursor on the LCD
    lcd.print("Fret!"); // Print the string "Fret"
    tone(Buzzer, NOTE_D5);
    delay(50);
    noTone(Buzzer);

  } else { // If the random task is whammy
    lcd.setCursor(4, 0); // Set the cursor on the LCD
    lcd.print("Whammy!"); // Print the string "Whammy"
    tone(Buzzer, NOTE_G6);
    delay(50);
    noTone(Buzzer);
  }
}
