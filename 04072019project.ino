#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8,7);

int Pitch_data[113]={
216, 311,349,311,349,349,466,415,391,349,391,391,466,523,349,311,466,466,391,466,466,523,//22
622,466,622,698,466,466,783,830,783,698,622, 698, 783,830,783,523,587,622,587,622,698,830,//22
783,698,622,783,698,659,698,523,587,587,783,932,783,622,466,622,698,466,466,783,830,783,698,//23
622, 698,523,587,659,587,622,698,830,783,698,622,783,698,659,698,783,987,1046,1174,523,587,//22
523,587,216, 311,349,311,349,349,466,415,391,349,391,391,466,523,349,311,466,466,391,466,466,523};//24
int pitch_data2[42]={262,262,392,392,440,440,392,349,349,330,330,294, //12
294,262,392,392,349,349,330,330,294,392,392,349,349,330,330,294, //18
262,262,392,392,440,440,392,349,349,330,330,294,294,262}; //16
int pitch_data3[10]={293,261,176,246,246,293,261,176,246,246};
int pin_BUZZER=A0;

int pin_SWITCH[4]={5,4,3,6};


volatile int i=0,j=0;
volatile int count =0;
int data=1;


void setup() {
  // put your setup code here, to run once:
  
 
  pinMode(pin_BUZZER,OUTPUT);
  pinMode(pin_SWITCH[0],INPUT);
  pinMode(pin_SWITCH[1],INPUT);
  pinMode(pin_SWITCH[2],INPUT);
  pinMode(pin_SWITCH[3],INPUT);
  
  attachInterrupt(digitalPinToInterrupt(2),switch_ISR,FALLING); // 핀번호,호출 함수,rising(falling)
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.begin(16,2);
  lcd.print("Press Song[1]");
  lcd.setCursor(0,1);
  lcd.print("Press Song[2]");
  delay(2000);
  lcd.clear();
  lcd.print("Exit [3]");
  lcd.setCursor(0,1);
  lcd.print("Pause [4]");
  delay(2000);
  lcd.clear();

  
  if(digitalRead(pin_SWITCH[0])){
      lcd.clear();
      lcd.print("Listening");
      lcd.setCursor(0,1);
      lcd.print("Cruel Engel.....");
      Wire.beginTransmission(8);
      data=1; 
      Wire.write(data);
      Wire.endTransmission();
      mode_1();
      delay(1000);
  }
  
  if(digitalRead(pin_SWITCH[1])){
      lcd.clear();
      lcd.print("Listening");
      lcd.setCursor(0,1);
      lcd.print("Little Star.....");
      Wire.beginTransmission(8);
      data=2;
      Wire.write(data);
      Wire.endTransmission();
      mode_2();
      delay(1000);
  }
  
  if(digitalRead(pin_SWITCH[3]))
  {
    Serial.print('3');
    Wire.beginTransmission(8);
    data=3;
    Wire.write(data);
    Wire.endTransmission();
    delay(1000);
  }
}
void switch_ISR()
{
  count++;
}
void mode_1()
{
      Serial.print("You are listening Cruel Engel");
      for(i=0; i<113; i++){
        if(count%2==0){
         lcd.clear();
         lcd.setCursor(0,1);
         lcd.print("Cruel Engel.....");
         tone(pin_BUZZER,Pitch_data[i]); // buzzer on - pitch generation
         delay(150); // waits for a second
         noTone(pin_BUZZER); // buzzer off
        
        while(count%2==1)
        { 
          lcd.setCursor(0,0);
          lcd.print("   !Pause!");
          noTone(pin_BUZZER);
          if(digitalRead(pin_SWITCH[2]))
          return loop();
        }
        if(digitalRead(pin_SWITCH[2]))
         return loop();
        }
      }
    }
void mode_2()
{
       
     Serial.print("Little Star");
     for(j=0; j<42; j++){ 
      if(count%2==0){  
         if(j>=0&&j<5)
         {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Little Star.....");
          lcd.setCursor(0,1);
          lcd.print("do do sol sol ra");
         }

         if(j>=5&&j<10)
         {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Little Star.....");
          lcd.setCursor(0,1);
          lcd.print("ra sol pa pa mi");
         }
         if(j>=10&&j<15)
         {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Little Star.....");
          lcd.setCursor(0,1);
          lcd.print("mi re re do sol");
         }
         if(j>=15&&j<20)
         {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Little Star.....");
          lcd.setCursor(0,1);
          lcd.print("sol pa pa mi mi");
         }
         if(j>=20&&j<25)
         {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Little Star.....");
          lcd.setCursor(0,1);
          lcd.print("re sol sol pa pa");
         }
         if(j>=25&&j<30)
         {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Little Star.....");
          lcd.setCursor(0,1);
          lcd.print("mi mi re do do");
         }
         if(j>=30&&j<35)
         {lcd.clear();
          lcd.setCursor(0,0);
         lcd.print("Little Star.....");
         lcd.setCursor(0,1);
         lcd.print("solsol ra ra sol");
         }
         if(j>=35&&j<40)
         {lcd.clear();
          lcd.setCursor(0,0);
         lcd.print("Little Star.....");
         lcd.setCursor(0,1);
         lcd.print("pa pa mi mi re");
         }
         if(j>=40&&j<42)
         {lcd.clear();
          lcd.setCursor(0,0);
         lcd.print("Little Star.....");
         lcd.setCursor(0,1);
         lcd.print("re do");
         }
         tone(pin_BUZZER,pitch_data2[j]); // buzzer on - pitch generation
         delay(500); // waits for a second
         noTone(pin_BUZZER); // buzzer off
         
      while(count%2==1)
      {   
        lcd.setCursor(0,0);
        lcd.print("   !Pause!");
        noTone(pin_BUZZER);
        if(digitalRead(pin_SWITCH[2]))
        return loop();
      }
      if(digitalRead(pin_SWITCH[2]))
      return loop();
    }
  }   
}
