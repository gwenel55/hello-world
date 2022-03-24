///Tamer Muddi
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  
  pinMode(9, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  int buttonState = digitalRead(9);
  if(buttonState == HIGH){
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);
    delay(500);
    
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(4, LOW);
    delay(500);
    
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
  }
  else{
    digitalWrite(8, LOW);
  }
                         
}
