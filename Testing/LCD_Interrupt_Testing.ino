#include <TimerOne.h>
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
#include "pitches.h"
#define BUZZER 2

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,20,4) for 20x4 LCD.
bool buzz;

void setup() {
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();
  Timer1.initialize(1000000); 
  Timer1.attachInterrupt(testInterrupt);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
  buzz = false;
}

void loop() {
  // Print 'Hello World!' on the first line of the LCD:
  lcd.setCursor(2, 0); // Set the cursor on the third column and first row.
  lcd.print("Hello World!"); // Print the string "Hello World!"
  lcd.setCursor(2, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
  lcd.print("Group Delta!");
  delay(200);
  lcd.clear();
  if (buzz == true) {
    tone(BUZZER, 1000); // Send 1KHz sound signal...
    delay(100);        // ...for 1 sec
    noTone(BUZZER);     // Stop sound...
    delay(100);        // ...for 1sec
    buzz = false;
  }
}

void testInterrupt() {
   buzz = true;
}
