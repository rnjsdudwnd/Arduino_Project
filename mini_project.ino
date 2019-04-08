#include <Wire.h>

//{261, 293, 329, 349, 391, 440, 493, 523};
int Pitch_data[52] ={261, 329, 349, 349 ,391, 391, 329 ,391, 349, //9
329, 349, 293, 329, 261, 329, 349, 349 ,391, 391, 329 ,391, 349, //13
329, 349, 293, 261, 391, 523, 493, 440, 391, 391, 329, 391, 349, //13
329, 349 ,293, 329, 391, 523, 493, 440, 391, 391, 329, 391, 349, //13
329, 349 ,293, 261 }; //4->52
int pitch_data2[46]={262,262,392,392,440,440,392,349,349,330,330,294, //12
294,262,0,0,392,392,349,349,330,330,294,392,392,349,349,330,330,294, //18
0,0,262,262,392,392,440,440,392,349,349,330,330,294,294,262}; //16
int pitch_data3[52]={293,261,176,246,246,293,261,176,246,246};
int pin_BUZZER=A0;
int pin_LED[8]={13,12,11,10,9,8,7,6};
int pin_SWITCH[4]={5,4,3,2};

volatile int count =0;
int data;


void setup() {
  // put your setup code here, to run once:
  int i,j;
  Serial.begin(9600);
  pinMode(pin_BUZZER,OUTPUT);
  pinMode(5,OUTPUT);//5번핀을 5볼트로 VCC
  digitalWrite(5,HIGH);//5번핀을 5볼트로 VCC
  pinMode(4,OUTPUT);//4번핀을 4볼트로 VCC
  digitalWrite(4,HIGH);//4번핀을 4볼트로 VCC
  pinMode(3,OUTPUT);//3번핀을 3볼트로 VCC
  digitalWrite(3,HIGH);//3번핀을 3볼트로 VCC
  for(i=0; i<8; i++){
    pinMode(pin_LED[i],OUTPUT);
  }
  for(j=0; j<4; j++){
    pinMode(pin_SWITCH[j],INPUT);
  }
  pinMode(2,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),switch_ISR,FALLING); // 핀번호,호출 함수,rising(falling)

  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int i,j;

  Wire.beginTransmission(8);
  

  
  if(digitalRead(pin_SWITCH[0])){
      data=1;
      Wire.write(data);
      Wire.endTransmission();
      Serial.print("You are listening Happy HOUSE");
      for(i=0;i<8;i++){
        digitalWrite(pin_LED[i], HIGH);
        delay(5);
            for(j=7; j>=0;j--){
              digitalWrite(pin_LED[j],LOW);
               delay(5);
                          }
                         }
      for(i=7; i>=0; i--){
        digitalWrite(pin_LED[i],HIGH);
        delay(5);
            for(j=0;j<8;j++){
                digitalWrite(pin_LED[j],LOW);
                delay(5);
                   }
                 }
      for(i=0; i<52; i++){
        if(count%2==0){
         tone(pin_BUZZER,Pitch_data[i]); // buzzer on - pitch generation
         delay(500); // waits for a second
         noTone(pin_BUZZER); // buzzer off
        
        while(count%2==1)
        noTone(pin_BUZZER);
        }
       
    }

    }
  else if(digitalRead(pin_SWITCH[1])){
       data=2;
       
       Wire.write(data);
       Wire.endTransmission();
       Serial.print("School Song");
      for(i=0;i<8;i++){
         digitalWrite(pin_LED[i], HIGH);
         delay(5);
             for(j=7; j>=0;j--){
                  digitalWrite(pin_LED[j],LOW);
                  delay(5);
                              }
                          }
       for(i=7; i>=0; i--){
           digitalWrite(pin_LED[i],HIGH);
           delay(5);
                 for(j=0;j<8;j++){
                     digitalWrite(pin_LED[j],LOW);
                     delay(5);
    }
  }
     for(j=0; j<46; j++){
      if(count%2==0){
         tone(pin_BUZZER,pitch_data2[j]); // buzzer on - pitch generation
         delay(500); // waits for a second
         noTone(pin_BUZZER); // buzzer off
        
      while(count%2==1)
      noTone(pin_BUZZER);
     }
     }
  }else if(digitalRead(pin_SWITCH[2])){
       data=3;
       Wire.write(data);
       Wire.endTransmission();
       Serial.print("School Song");
      for(i=0;i<8;i++){
         digitalWrite(pin_LED[i], HIGH);
         delay(5);
             for(j=7; j>=0;j--){
                  digitalWrite(pin_LED[j],LOW);
                  delay(5);
                              }
                          }
       for(i=7; i>=0; i--){
           digitalWrite(pin_LED[i],HIGH);
           delay(5);
                 for(j=0;j<8;j++){
                     digitalWrite(pin_LED[j],LOW);
                     delay(5);
    }
  }
     for(j=0; j<46; j++){
      if(count%2==0){
         tone(pin_BUZZER,pitch_data3[j]); // buzzer on - pitch generation
         delay(200); // waits for a second
         noTone(pin_BUZZER); // buzzer off
      
      while(count%2==1)
        noTone(pin_BUZZER);
     }
   }
  }

  //lll
  
 
 delay(100); // waits for a second
 
}
void switch_ISR()
{
  count++;
}
