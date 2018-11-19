#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>

//LiquidCrystal_I2C lcd(0x3f, 16, 2);

// 핀 번호 ( RS, E, DB4, DB5, DB6, DB7 )
LiquidCrystal lcd(44, 45, 46, 47, 48, 49);

const int xAxisPin = A0;
const int yAxisPin = A1;
const int zAxisPin = 2;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  //lcd.write("Hello World!");
  pinMode(zAxisPin, INPUT_PULLUP);

  //lcd.init();
  //lcd.backlight();
  
  lcd.write("ex 6.5");
  lcd.setCursor(0,1);
  lcd.write("Joystick");
  delay(3000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("X: ");
  lcd.setCursor(0,1);
  lcd.write("Y: ");
  lcd.setCursor(15,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xValue = analogRead(xAxisPin);
  int yValue = analogRead(yAxisPin);
  int zValue = analogRead(zAxisPin);
  
  int xDisplay = map(xValue, 0, 1023, 6, 15);
  int yDisplay = map(yValue, 0, 1023, 6, 15);

  lcd.setCursor(2,0);
  lcd.print("              ");

  lcd.setCursor(2,0);
  lcd.print(xValue);

  lcd.setCursor(xDisplay, 0);
  lcd.print("|");

  lcd.setCursor(2,1);
  lcd.print("              ");

  lcd.setCursor(2,1);
  lcd.print(yValue);

  lcd.setCursor(yDisplay, 1);
  lcd.write("|");

  if(zValue == LOW) {
    //lcd.noBacklight();
    delay(300);
    //lcd.backlight();
  }
  delay(100);
}
