int buzzer = 5; //digital 5
int newAction;
int startAction;

void setup() 
{
  randomSeed(analogRead(0)); //analog 0 pin
}

void loop() 
{
  
  //3 tones and different patterns to indicate which action
  //use the tone(pin, freq, duration) function  
  
  //1 low buzz: Cover it
  //2 medium buzzes: Bend it
  //3 high buzzes: Joystick
  
  if(newAction == HIGH){
    randNumber = random(1, 4); //random number from 1 to 3
  
    //Cover it
    if(randNumber == 1){
      tone(buzzer, 1000, 500);
      startAction == HIGH;      
    }
    
    //Bend it
    Else if (randNumber == 2){
      tone(buzzer, 2000, 250);
      tone(buzzer, 2000, 250);
      startAction == HIGH;      

    }
    
    //Joystick
    Else {
      tone(buzzer, 3000, 125);
      tone(buzzer, 3000, 125);
      tone(buzzer, 3000, 125);
      startAction == HIGH;     
    }

    startAction == LOW;
    newAction == LOW;
  }
}
