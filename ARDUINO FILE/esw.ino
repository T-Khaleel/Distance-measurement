#include <LiquidCrystal.h> 
LiquidCrystal LCD(11,10,9,2,3,4,5);  
#define button 8    
#define led 7      
#define trig 13 
#define echo 12 

int time1, distance;
int buttonState = 0; 
int a=0;
void setup() 
{  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  LCD.begin(16,2); 
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  time1 = pulseIn(echo, HIGH);
  distance = time1*(0.034/2);

  if (distance < 5 )
  {
  
   LCD.setCursor(0,0);
   LCD.print("                "); 
   LCD.setCursor(0,0);
   LCD.print("WARNING!!!     ");
   LCD.setCursor(0,1);  
   LCD.print("                "); 
   LCD.setCursor(0,1);   
   LCD.print(distance);
   LCD.print(" cm            ");  
   delay(250); 
   digitalWrite(led, HIGH);
   buttonState = digitalRead(button);
   
  if (buttonState == HIGH) {
   a=1;
   } 

  if (a==1)
   {
   digitalWrite(led, LOW);
   }
  
   }
  
  else
   {
   a=0;
   LCD.setCursor(0,0);  
   LCD.print("Distance:       ");  
   LCD.setCursor(0,1);  
   LCD.print("                "); 
   LCD.setCursor(0,1);  
   LCD.print(distance); 
   LCD.print(" cm          ");  
   delay(250); 
   digitalWrite(led, LOW); }
  }
