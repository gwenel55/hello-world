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

void setup() {
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();

  //pins for the joystick
  pinMode(8,INPUT); 
  digitalWrite(8,HIGH); 
}

void loop() {
  //if we hit the start button
  if(start){
    lcd.setCursor(2, 0); // Set the cursor on the third column and first row.
    lcd.print("Game Started"); // Print the string to the screen
    delay(2000);
    lcd.clear(); // clear the screen
    start = false;
  }
    
  lcd.setCursor(2, 0);
  lcd.print("Score:     ");
  lcd.setCursor(2, 1);
  lcd.print(Score);
  MixIt();
}

void DetectAction(bool Right)
{
  if(Right){
    Score++;
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
  
}

void BendIt()
{
  
}
