#include "dht.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

dht DHT;

#define DHT11_PIN 5//temp humidity sensor

int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value ;
int relayPin = A3; 



void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(sensor_pin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  pinMode(2, OUTPUT);

}


void loop() {
  // put your main code here, to run repeatedly:
  led();
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  
  lcd.setCursor(0,1); 
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(2000);
  
  lcd.setCursor(23,0);
  lcd.autoscroll();
  output_value= analogRead(sensor_pin);
  output_value = map(output_value,550,10,0,100);
  lcd.print("Mositure: ");
  lcd.print(output_value);
  lcd.print("%");
  
  lcd.setCursor(23,1);
  if(output_value<30){
  digitalWrite(relayPin, LOW);
  lcd.print("Motor ON");
 }
 else
 {
  digitalWrite(relayPin, HIGH);
  lcd.print("Motor OFF");       
 }
 
  
  delay(2500);
  lcd.noAutoscroll();
  lcd.clear();


  
  
}


void led(){
  int ldrdata= analogRead(A1);
  Serial.println("") ;
  Serial.print(ldrdata);
  delay(500);
  if(ldrdata<=700){
    digitalWrite(2, HIGH);
  }

  else{
    digitalWrite(2, LOW);
  }
  


}