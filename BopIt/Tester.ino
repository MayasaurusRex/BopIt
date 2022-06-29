// libraries and header files
#include <TimerOne.h>
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
#include "pitches.h"
#include "pinmap.h"

// define LCD display
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,20,4) for 20x4 LCD.

void setup() {
  // Initialize the LCD:
  lcd.init();
  lcd.backlight();

  // Initialize Interrupt
  Timer1.initialize(1000000); 
  Timer1.attachInterrupt(InterruptHandler);

  // set up pins
  pinSetup();
}

void loop() {
  int startButtonState = digitalRead(StartBTN);
  
  if(startButtonState == LOW) {
    lcd.setCursor(2, 0); // Set the cursor on the LCD
    lcd.print("Starting"); // Print the string "Starting"
    lcd.setCursor(2, 1); // Set the cursor on the LCD
    lcd.print("BopIt!"); // Print the string "BopIt!"
    digitalWrite(GreenLED, HIGH);
    digitalWrite(RedLED, LOW);
    delay(50);
  }
  else {
    lcd.clear();
    digitalWrite(GreenLED, LOW);
    digitalWrite(RedLED, HIGH);
    delay(50);
  }

  int fretButtonState = digitalRead(Fret);
  
  if(fretButtonState == LOW) {
    lcd.setCursor(2, 0); // Set the cursor on the LCD
    lcd.print("Fret"); // Print the string "Starting"
    lcd.setCursor(2, 1); // Set the cursor on the LCD
    lcd.print("Pressed!"); // Print the string "BopIt!"
    tone(Buzzer, NOTE_D5);
    delay(100);
  }
  else {
    lcd.clear();
    noTone(Buzzer);
    delay(50);
  }

  int whammyButtonState = analogRead(Whammy);
  
  if(whammyButtonState < 500) {
    lcd.setCursor(2, 0); // Set the cursor on the LCD
    lcd.print("Whammy"); // Print the string "Starting"
    lcd.setCursor(2, 1); // Set the cursor on the LCD
    lcd.print("Pressed!"); // Print the string "BopIt!"
    tone(Buzzer, NOTE_G5);
    delay(100);
  }
  else {
    lcd.clear();
    noTone(Buzzer);
    delay(50);
  }

  int Strum1ButtonState = digitalRead(StrumSw1);
  
  if(Strum1ButtonState == LOW) {
    lcd.setCursor(2, 0); // Set the cursor on the LCD
    lcd.print("Strum1"); // Print the string "Starting"
    lcd.setCursor(2, 1); // Set the cursor on the LCD
    lcd.print("Pressed!"); // Print the string "BopIt!"
    tone(Buzzer, NOTE_C7);
    delay(100);
  }
  else {
    lcd.clear();
    noTone(Buzzer);
    delay(50);
  }

  int Strum2ButtonState = digitalRead(StrumSw2);
  
  if(Strum2ButtonState == LOW) {
    lcd.setCursor(2, 0); // Set the cursor on the LCD
    lcd.print("Strum2"); // Print the string "Starting"
    lcd.setCursor(2, 1); // Set the cursor on the LCD
    lcd.print("Pressed!"); // Print the string "BopIt!"
    tone(Buzzer, NOTE_C7);
    delay(100);
  }
  else {
    lcd.clear();
    noTone(Buzzer);
    delay(50);
  }
  
}