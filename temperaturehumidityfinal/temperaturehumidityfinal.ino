#include <LiquidCrystal.h>

#include <DHT.h>

#include "DHT.h"

#define DHTPIN A0     // what pin we're connected to

#define DHTTYPE DHT22   // we are using the DHT22 sensor

LiquidCrystal lcd(8,9,10,11,12,13);

DHT dht(DHTPIN, DHTTYPE);

int green = 5;
int red = 6;
int blue = 7;

void setup()
{

pinMode(green, OUTPUT);
pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(3, OUTPUT);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print(" Digital ");
lcd.setCursor(0,1);
lcd.print("Hygro Thermometer");
delay(2000);
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print(" Station");
//delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" MADE BY Bishal");
delay(2000);
lcd.clear();
  
Serial.begin(9600);

//lcd.begin(16,2);  //16 by 2 character display
  
dht.begin();
}
 
void loop()
{
  delay(1000);
  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  
  float t = dht.readTemperature();  // Read temperature as Celsius (the default)

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);  //printing temperarture to the LCD display
  lcd.print((char)223);
  lcd.print("C");


  
  
//the 3-led setup process
if (t>=10 && t<=30)
{
  lcd.setCursor(15,0);
  lcd.print("N");
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, HIGH);
}else if(t<10)
{
  lcd.setCursor(15,0);
  lcd.print("L");
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  tone(3, 1000, 500);
}else if(t>30)
{
  lcd.setCursor(15,0);
  lcd.print("H");
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(blue, LOW);
  tone(3, 1000, 500);
}
  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(h);  //printing humidity to the LCD display
  lcd.print("%");
}
