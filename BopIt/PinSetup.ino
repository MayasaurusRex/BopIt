#include "pinmap.h"

void pinSetup() {
  // set all inputs
  pinMode(StartBTN, INPUT);
  pinMode(Fret, INPUT);
  pinMode(StrumSw1, INPUT);
  pinMode(StrumSw2, INPUT);

  // set all outputs
  pinMode(GreenLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}