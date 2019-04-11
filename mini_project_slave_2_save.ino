
#include <Wire.h>

volatile int pin_ROW[4] = {13, 12, 11, 10};
volatile int pin_COLUMN[4] = {9, 8, 7, 6};
volatile int pin_BUZZER=A0;
volatile int pin_GND=5;
int Number=0;
volatile int Pitch_data[16]={261,293,329,349,391,440,493,523,587,659,698,783,880,987,1046,2093};
void setup() {
  Wire.begin();
  
  for(int i=0;i<4;i++)
  {
    pinMode(pin_ROW[i],OUTPUT);
    pinMode(pin_COLUMN[i],INPUT);
  }
  pinMode(pin_GND, OUTPUT);
  digitalWrite(pin_GND, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

int i, j;
int ROW, COLUMN;
for(i=0; i<4; i++)
{
digitalWrite(pin_ROW[i], HIGH);
ROW = 0;
ROW = i*4; // ROW = 0, 4, 8, 12
for(j=0; j<4; j++)
{
COLUMN = 0;
COLUMN += j; // COLUMN = 0, 1, 2, 3
if(digitalRead(pin_COLUMN[j]))
{
Number = ROW + COLUMN;
Serial.print("KEY [");
Serial.print(Number, HEX);
 Serial.println("] PUSH");
 Wire.beginTransmission(8);
 Wire.write(Number);
 Wire.endTransmission();
 //delay(500);
 tone(pin_BUZZER,Pitch_data[Number]);
                            delay(300);
                            noTone(pin_BUZZER);
}
}
digitalWrite(pin_ROW[i], LOW);

}
}
