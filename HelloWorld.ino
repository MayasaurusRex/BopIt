#define newLED 8
#define newBTN 9

void setup() {
  pinMode(newBTN, INPUT);
  pinMode(newLED, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(newBTN);

  if(buttonState == HIGH) {
    digitalWrite(newLED, HIGH);
    delay(50);
    digitalWrite(newLED, LOW);
    delay(50);
  }
  else {
    digitalWrite(newLED, LOW);
    delay(50);
  }
}
