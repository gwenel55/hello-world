#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD

#define NOTE_B1  62
#define NOTE_B2  123
#define NOTE_B3  247

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
int flexSensor = 9; //digital pin 9
int buzzer = 3; //digital pin 3
int pushButton = 4; //digital pin 4

int buttonState = 0;

void setup() {
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();

  //pins for the joystick
  pinMode(8,INPUT); 
  digitalWrite(8,HIGH); 

  randomSeed(analogRead(2));
  //Start Game: Will go through this only once
  if(buttonState == LOW){
    lcd.setCursor(0,0);
    lcd.print("Press button to Start Game");
    do{
      delay(1);
    } while (digitalRead(pushButton) == LOW);
      buttonState == HIGH;
  }
}

void loop() {
  //No need to write code for On/Off button
  //Only need to connect the button to the reset pin on the board
  
 
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Score: ");
  lcd.setCursor(2, 1);
  lcd.print(Score);
  
  //random action 
  randomAction = random(1,4);

  timeLimit = timeLimit - 101;
  if(randomAction == 1){
    lcd.setCursor(5, 1);
    lcd.print("Mix It  ");
    
    tone(buzzer, NOTE_B1, 1000); //tone(pin, frequency Hz, duration Milliseconds)
    
    delay(1000);
    MixIt();
  }
  else if(randomAction == 2){
    lcd.setCursor(5,1);
    lcd.print("Cover It");
    
    tone(buzzer, NOTE_B2, 1000);
    
    delay(1000);
    CoverIt();
  }
  else if (randomAction == 3){
    lcd.setCursor(5,1);
    lcd.print("Bend It  ");
    
    tone(buzzer, NOTE_B3, 1000);
    
    delay(1000);
    BendIt();
  }
  
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
    a = analogRead(A1);
    if(a >= 1000)
    {
      delay(130);
      b = analogRead(A0);  
      if(b >= 1000)
      { 
        previousMillis = millis();
        Right = 1;
        DetectAction(Right);
        exit(0);
      }
      else{
            Right = 0;
            DetectAction(Right);
      }
    }
    else if(digitalRead(photoResistor) == LOW || digitalRead(flexSensor) == HIGH){
      Right = 0;
      DetectAction(Right);
    }
  }
  
  Right = 0;
  DetectAction(Right);
}

void CoverIt()
{
  
  while((millis() - previousMillis) < timeLimit){
    if(digitalRead(photoResistor) == LOW){
      previousMillis = millis();
      Right = 1;
      DetectAction(Right);
      exit(0);
    }
    else if(digitalRead(flexSensor) == HIGH || analogRead(A1) == HIGH || analogRead(A0) == HIGH){
      Right = 0;
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
      previousMillis = millis();
      Right = 1;
      DetectAction(Right);
      exit(0);
    }
    else if(digitalRead(photoResistor) == LOW || analogRead(A1) == HIGH || analogRead(A0) == HIGH){
      Right = 0;
      DetectAction(Right);
    }
  }
  Right = 0;
  DetectAction(Right);
 
}
