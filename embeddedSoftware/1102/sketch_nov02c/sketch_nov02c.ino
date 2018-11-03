#include <LiquidCrystal.h>
LiquidCrystal lcd(44, 45, 46, 47, 48, 49); // RS, E, DB4, DB5, DB6, DB7
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

}

void loop() {
    // put your main code here, to run repeatedly:
   int light = analogRead(A0);
   Serial.println(light);
   lcd.setCursor(0,0);
   lcd.print("ADC:");
   lcd.setCursor(6,0);
   lcd.print(light);
   lcd.setCursor(0,1);
   lcd.print("ILLuminance:");
   lcd.setCursor(12,1);
   lcd.print(map(light,0,1023,0,100));
   lcd.setCursor(15,1);
   lcd.print("%");
   
  
}
