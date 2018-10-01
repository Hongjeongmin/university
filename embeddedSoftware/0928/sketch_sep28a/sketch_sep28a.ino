#include <LiquidCrystal.h>
LiquidCrystal lcd(44,45,46,47,48,49); 
unsigned int i=2;
int j=1;
int time=0;
//int arr[1000];
byte user1[8] ={B00000,B10001,B00000,B00000,B100001,B01110,B00000,B00000};
byte user2[8] ={B00000,B100001,B01010,B10001,B00000,B10001,B01110,B00000};

void setup() {
  /*
  lcd.begin(16,2);
  lcd.print("Iduino hellow");
  arr[0]=0;
  arr[1]=1; 
  */
  lcd.createChar(0,user1);
  lcd.createChar(1,user2);
  lcd.begin(16,2);
  lcd.clear();

  lcd.write(byte(0));
  lcd.setCursor(0,1);
  lcd.write(byte(1));
}

void loop() {
  /*
  for(i=0;i<=1;i++)
  {
    for(j=0;j<=15;j++)
    {
      lcd.setCursor(j,i);
      lcd.write('0');
      delay(1000);
      lcd.setCursor(j,i);
      lcd.write(' ');
    }
  }
 */
 /*
 lcd.setCursor(0,1);
 lcd.print(time);
 time++;
 delay(1000);
 */
 /*
 lcd.setCursor(0,1);
 lcd.print(i);
 lcd.setCursor(3,1);
 lcd.print("*");
 lcd.setCursor(6,1);
 lcd.print(j);
 lcd.setCursor(9,1);
 lcd.print("=");
 lcd.setCursor(12,1);
 lcd.print(i*j);
 
 delay(300);
 j++;
 if(j==9)
 {
  j=1;
  i++;
  lcd.setCursor(12,1);
  lcd.print("     ");
 }
*/
/*
lcd.setCursor(0,1);
arr[i]=arr[i-1]+arr[i-2];
lcd.print(arr[i]);
i++; 
delay(1000);
*/

}
