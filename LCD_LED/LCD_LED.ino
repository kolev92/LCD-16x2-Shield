#include <LiquidCrystal.h>
//LCD pin to Arduino
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10; 
LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);
int led=13;
int mode=0;
void setup() {
 pinMode(led, OUTPUT);
 lcd.begin(16, 2);
 Serial.begin(9600);
 lcd.setCursor(2,0);
 lcd.print("LED CONTROL");

}
void loop() {
 if(Serial.available()>0){
  mode=Serial.read();
 }
 lcd.setCursor(0,1);
 lcd.print("Led is: ");
 if(mode=='0'){
  lcd.print("OFF");
  digitalWrite(led, LOW);
 }
 else if (mode=='1'){
  lcd.print("ON ");
  digitalWrite(led, HIGH);
 }
} 
