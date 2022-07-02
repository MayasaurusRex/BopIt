// libraries and header files
#include <TimerOne.h>
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
#include "pitches.h"
#include "pinmap.h"
#include "flags.h"

// define LCD display
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // using I2C connection

void setup() {
  //Initialize the LCD:
  lcd.init();
  lcd.backlight();

  // Initialize Interrupt
//  Timer1.initialize(1000000); 
//  Timer1.attachInterrupt(InterruptHandler);

  // set up pins
  pinSetup();

  randomSeed(analogRead(4)); // random seed to generate random tasks
}

void loop() {
  if (first == 1) { // if this is the first pass of the game...
    ChooseTask(); // choose the first task
    first = 0; // change flag
    second = 1;
  }

  else if (timeOut == 1) {
    inputHandler(false); // failure
    timeOut == 0;
  }

  PollInput(); // otherwise, poll for user input
  
  count = count - 1;
  if (count == 0) {
    inputHandler(false); // failure
  }
}
