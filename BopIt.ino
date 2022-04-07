#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD

// Wiring: SDA pin is connected to A4 and SCL pin to A5.
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

int Score = 0;
int x;
int y;
int a;
int b;
int c;
int d;
bool Right;
bool start = true;
bool Temp1 = true;
unsigned long currentMillis;
unsigned long previousMillis = 0;
unsigned long timeLimit = 10000;
long randomAction;

int photoResistor = 2; //digital pin 2
int flexSensor = 11; //digital pin 1


void setup() {
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();

  //pins for the joystick
  pinMode(8,INPUT); 
  digitalWrite(8,HIGH); 

  randomSeed(analogRead(2));

}

void loop() {
    
  lcd.setCursor(2, 0);
  lcd.print("Score: ");
  lcd.setCursor(2, 1);
 lcd.print(Score);

    //random action 
    randomAction = random(1,4);
  
    if(randomAction == 1){
      lcd.setCursor(5, 1);
      //lcd.print("Mix It");
      delay(1000);
      lcd.print(currentMillis);
      
      MixIt();
    }
    else if(randomAction == 2){
      lcd.setCursor(5,1);
      lcd.print("Cover It");
      delay(1000);
      CoverIt();
    }
    else if (randomAction == 3){
      lcd.setCursor(5,1);
      lcd.print("Bend It");
      delay(1000);
      BendIt();
    }

  timeLimit = timeLimit - 101;


  
}

void DetectAction(bool Right)
{
  if(Right){
    int temp = Score;
    if(temp == Score){
      Score++;
    }
    
   }

  else
  {
    Score = 0;
    lcd.clear();
    lcd.setCursor(2, 0); // Set the cursor on the third column and first row.
    lcd.print("Game Over"); // Print the string to the screen
    exit(0);
  }
}

void MixIt()
{
  while((currentMillis - previousMillis) < timeLimit){
    a = analogRead(A1);
    if(a > 1000)
    {
      delay(130);
      b = analogRead(A0);  
      if(b > 1000)
      { 
        Right = 1;
        DetectAction(Right);
      }
      else{
            Right = 0;
            DetectAction(Right);
      }
    }
  }
  previousMillis = currentMillis;

}

void CoverIt()
{
  
  while((currentMillis - previousMillis) < timeLimit){
    if(digitalRead(photoResistor) == LOW){
      Right = 1;
      DetectAction(Right);
    }
  }
  
  Right = 0;
  DetectAction(Right);
  previousMillis = currentMillis;
  
}

void BendIt()
{
  while((millis() - previousMillis) < timeLimit){
    if(digitalRead(flexSensor) == HIGH){
      Right = 1;
      DetectAction(Right);
      lcd.setCursor(2, 0);
      currentMillis = millis();
      lcd.print(currentMillis);
    }
  }
  Right = 0;
  DetectAction(Right);
  previousMillis = currentMillis;
 
}
