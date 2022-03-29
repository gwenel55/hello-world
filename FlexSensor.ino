
int flexSensor = 1; //digital pin 1
int flexSensorOutput;
unsigned long score;
unsigned long timeLimit = 10000;  //the amount of time that the action must be completed in
unsigned long startingTime; //the time once the photoResistorFunction is called because
                            //millis() returns milliseconds passed since arduino board started 
                            //running the whole program

void flexSensorFunction(void *)
{
  startingTime = millis();
  
  int flexSensorValue = digitalRead(flexSensor);

  //if current time - startingTime is less than timeLimit AND input is high
  if((millis() - startingTime) <= timeLimit && flexSensorValue == HIGH){
    flexSensorOutput == HIGH;
    score++;
    //decrement the timeLimit for the next action
    timeLimit = timeLimit - 101;
  }
  
  else{
    flexSensorOutput == LOW;
  }
}
   
void setup() 
{
  Serial.begin(9600);
  pinMode(flexSensor, INPUT);  
}

void loop() {
  
  //first action = 10 seconds to complete
  //10 / 99 = 0.101 
  //decrement time by 0.101 for every success

  //call photoResistorFunction if startAction is high
  if(startAction == HIGH){
    flexSensorFunction();
  }
  
  
}
