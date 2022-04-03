
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

int photoResistor = 2; //digital pin 0
int photoResistorOutput;
unsigned long score;
unsigned long timeLimit = 10000;  //the amount of time that the action must be completed in
int const startingTime = millis(); //the time once the photoResistorFunction is called because
                            //millis() returns milliseconds passed since arduino board started 
                            //running the whole program
int startAction;                    

void photoResistorFunction()
{
  //startingTime = millis();   
  

  //if current time - startingTime is less than timeLimit AND input is high
  if((millis() - startingTime) <= timeLimit && digitalRead(photoResistor) == HIGH){
    lcd.clear();
    lcd.print("SUCCESS");
    score++;
    //decrement the timeLimit for the next action
    timeLimit = timeLimit - 9000;
  }
  
  else if((millis() - startingTime) > timeLimit){
    lcd.clear();
    lcd.print("FAILURE");
  }
}
   
void setup() 
{
  Serial.begin(9600);
  pinMode(photoResistor, INPUT); 
  lcd.init();
  lcd.backlight(); 
}

void loop() {
  
  //first action = 10 seconds to complete
  //10 / 99 = 0.101 
  //decrement time by 0.101 for every success
  
  startAction = HIGH;
  //call photoResistorFunction if startAction is high
  if(startAction == HIGH){
    photoResistorFunction();
    
    
  }
  delay(10);
  
  
}
