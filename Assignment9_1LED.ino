// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  int buttonState = digitalRead(9);
  if(buttonState == HIGH){
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(8, LOW);
    delay(1000);
  }
  else{
    digitalWrite(8, LOW);
  }
                         
}
