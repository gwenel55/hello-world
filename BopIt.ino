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
unsigned long const currentMillis = millis();
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
  lcd.print("Score:     ");
  lcd.setCursor(2, 1);
  lcd.print(Score);

  while(millis() < timeLimit
  //random action 
  randomAction = random(1,4);

  if(randomAction == 1){
    lcd.setCursor(5, 1);
    lcd.print("Mix It");
    delay(1000);
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
  a = analogRead(A1);
  if(a > 1000)
  {
    delay(130);
    b = analogRead(A0);  
    if(b > 1000)
    { 
      delay(130);
      c = analogRead(A1); 
      if(c < 10)
      {
        delay(130);
        d = analogRead(A0);  
        if(d < 10)
        {
          Right = 1;
          DetectAction(Right);
        }
        else{
          Right = 0;
          DetectAction(Right);
        }
      }
      else{
          Right = 0;
          DetectAction(Right);
      }
    }
    else{
          Right = 0;
          DetectAction(Right);
    }
  }
  
}

void CoverIt()
{
  
  if(digitalRead(photoResistor) == LOW){
    int temp = 1;
    if( temp == 1){
      Right = 1;
      DetectAction(Right);
    }
    temp++;
  }
  Right = 0;
  //else{
    //Right = 0;
    //DetectAction(Right);
  //}
  //previousMillis = currentMillis;
  
}

void BendIt()
{
  if(digitalRead(flexSensor) == HIGH){
    int temp = 1;
    if( temp == 1){
      Right = 1;
      DetectAction(Right);
    }
    temp++;
  }
  Right = 0;
 
}
