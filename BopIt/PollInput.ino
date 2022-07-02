void PollInput() {
  // 1 = Strum, 2 = Fret, 3 = Whammy
  int fretButtonState = digitalRead(Fret);
  int whammyButtonState = analogRead(Whammy);
  int Strum1ButtonState = digitalRead(StrumSw1);
  int Strum2ButtonState = digitalRead(StrumSw2);
    
  if(Strum1ButtonState == LOW) {
    inputHandler(currTask == 1);
  }

  if(Strum2ButtonState == LOW) {
    inputHandler(currTask == 1);
  }

  if(fretButtonState == LOW) {
    inputHandler(currTask == 2);
  }

  if(whammyButtonState < 500) {
    inputHandler(currTask == 3);
  }
}
