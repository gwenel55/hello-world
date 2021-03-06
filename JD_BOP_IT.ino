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
unsigned long currentMillis = millis();
unsigned long previousMillis = 0;
unsigned long timeLimit = 10101;
long randomAction;

int photoResistor = 2; //digital pin 2
int flexSensor = 9; //digital pin 1


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

  timeLimit = timeLimit - 101;
  if(randomAction == 1){
    //timeLimit = timeLimit - 101;
    lcd.setCursor(5, 1);
    lcd.print("Mix It  ");
    //lcd.setCursor(11, 0);
    //lcd.print(timeLimit);
    delay(1000);
    MixIt();
  }
  else if(randomAction == 2){
    lcd.setCursor(5,1);
    lcd.print("Cover It");
    //lcd.setCursor(11, 0);
    //lcd.print(timeLimit);
    delay(1000);
    CoverIt();
  }
  else if (randomAction == 3){
    lcd.setCursor(5,1);
    lcd.print("Bend It  ");
    //lcd.setCursor(11, 0);
    //lcd.print(timeLimit);
    delay(1000);
    BendIt();
  }
  
  //lcd.setCursor(5, 1);
  //lcd.print(timeLimit);
  //timeLimit = timeLimit - 101;
  //lcd.setCursor(5, 1);
  //lcd.print("Mix It");
  //delay(1000);
  //CoverIt();
  
 
}

void DetectAction(bool Right)
{
  if(Right){
    Score++;
    loop();
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
  while((millis() - previousMillis) < timeLimit){
    //lcd.setCursor(11, 0);
    //lcd.print(millis());
    a = analogRead(A1);
    if(a >= 1000)
    {
      delay(130);
      b = analogRead(A0);  
      if(b >= 1000)
      { 
        previousMillis = millis();
        //lcd.setCursor(11, 1);
        //lcd.print(previousMillis);
        Right = 1;
        DetectAction(Right);
        exit(0);
      }
      else{
            Right = 0;
            DetectAction(Right);
      }
    }
  }
  Right = 0;
  DetectAction(Right);
}

void CoverIt()
{
  
  while((millis() - previousMillis) < timeLimit){
    //lcd.setCursor(11, 0);
    //lcd.print(millis());
    if(digitalRead(photoResistor) == LOW){
      previousMillis = millis();
      //lcd.setCursor(11, 1);
      //lcd.print(previousMillis);
      Right = 1;
      DetectAction(Right);
      exit(0);
    }
  }
  
  Right = 0;
  DetectAction(Right);
  
}

void BendIt()
{
  while((millis() - previousMillis) < timeLimit){
    //lcd.setCursor(11, 0);
    //lcd.print(millis());
    if(digitalRead(flexSensor) == HIGH){
      previousMillis = millis();
      //lcd.setCursor(11, 1);
      //lcd.print(previousMillis);
      Right = 1;
      DetectAction(Right);
      exit(0);
    }
  }
  Right = 0;
  DetectAction(Right);
 
}
