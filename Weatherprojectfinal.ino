include<LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

LiquidCrystal lcd(12,13,4,5,6,7);//CONNECT THESE PINS ON LCD
void setup(){
Serial.begin(9600);
 pinMode(2,OUTPUT);

delay(3000);
Serial.begin(9600);
lcd.begin(16,2);
dht.begin();
lcd.print("LCD IS STARTING");
delay(1000);
lcd.clear();
  

}
void loop(){
int value=analogRead(A3);
 Serial.print("Value : ");
Serial.println(value);
if (value<900) {
  digitalWrite(3,LOW);
  Serial.print("Heavy rain LED on ");
}
else{ digitalWrite( 3,HIGH);
}

float h= dht.readHumidity(); // FUNCTION FOR READING HUMIDITY DATA
float t= dht.readTemperature();// FUNCTION FOR READING TEMPERATURE DATA
if(isnan(h) || isnan(t)){
Serial.println("Failed to get data");
lcd.setCursor(0,1);
lcd.print("FAILED! TRY AGAIN");
}
else{
//analogWrite(A0,0);
// For printing the humidity data on SERIAL MONITOR
Serial.print("CURRENT HUMIDITY_");
Serial.print(h);
Serial.print("%");
Serial.print("||");
// FOR PRINTING THE TEMPERATURE DATA O0N SERIAL MONITOR
Serial.print("CURRENT TEMPERATURE_");
Serial.print(t);
Serial.println("°C");
// FOR PRINTING THE HUMIDITY DATA ON LCD
lcd.setCursor(0,0);
lcd.print("HUMIDITY_");
lcd.setCursor(10,0);
lcd.print(h);
lcd.setCursor(14,0);
lcd.print("%");
// FOR PRINTING THE TEMPERATURE DATA ON LCD
lcd.setCursor(0,1);
lcd.print("TEMPERATURE_");
lcd.setCursor(12,1);
lcd.print(t);
lcd.setCursor(15,1);
lcd.print("C");

}
}
