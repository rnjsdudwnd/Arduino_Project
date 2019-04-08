#include <LiquidCrystal.h>
#include <Wire.h>
LiquidCrystal lcd(13,12,11,10,9,8,7);

void setup() {
  // put your setup code here, to run once:
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  lcd.begin(16,2);
  
  lcd.print("SW1:song(1)");
  lcd.setCursor(0,1);
  lcd.print("SW2:song(2)");
  delay(5000);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}

void receiveEvent(int select)
{
  lcd.clear();
  int data=Wire.read();
  int endsong=Wire.read();
  if(data==1){
  lcd.print("You are listeni");
  lcd.setCursor(0,1);
  lcd.print("ng Happy House");
  Serial.print(data);
  }
  
  if(data==2){
  lcd.clear();
  lcd.print("School Song");
  Serial.print(data);
  }
  
  if(data==3){
  lcd.clear();
  lcd.print("Poket Monster");
  Serial.print(data);
  }
  if(endsong==0){
  lcd.clear();
  lcd.print("SW1:song(1)");
  lcd.setCursor(0,1);
  lcd.print("SW2:song(2)");
  Serial.print(data);
  }
}
