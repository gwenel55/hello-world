
int photoResistor = 0; //digital pin 0
int photoResistorOutput;
unsigned long score;
unsigned long timeLimit = 10000;  //the amount of time that the action must be completed in
unsigned long startingTime; //the time once the photoResistorFunction is called because
                            //millis() returns milliseconds passed since arduino board started 
                            //running the whole program

void photoResistorFunction(void *)
{
  startingTime = millis();
  
  int photoResitorValue = digitalRead(photoResistor);

  //if current time - startingTime is less than timeLimit AND input is high
  if((millis() - startingTime) <= timeLimit && photoResitorValue == HIGH){
    photoResistorOutput == HIGH;
    score++;
    //decrement the timeLimit for the next action
    timeLimit = timeLimit - 101;
  }
  
  else{
    photoResistorOutput == LOW;
  }
}
   
void setup() 
{
  Serial.begin(9600);
  pinMode(photoResistor, INPUT);  
}

void loop() {
  
  //first action = 10 seconds to complete
  //10 / 99 = 0.101 
  //decrement time by 0.101 for every success

  //call photoResistorFunction if startAction is high
  if(startAction == HIGH){
    photoResistorFunction();
  }
  
  
}
