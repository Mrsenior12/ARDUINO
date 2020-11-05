#define trigPin 12
#define echoPin 11
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
void setup() {
  pinMode(trigPin, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin, INPUT); //a echo, jako wejście
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("distance: ");
  lcd.setCursor(0,1);  
}

void loop() {  
 lcd.print(checkDistance());
 lcd.print(" cm");
 lcd.setCursor(0,1);
 delay(500);
 lcd.print("                ");
 lcd.setCursor(0,1);
} 
float checkDistance() {
  float TIME, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  TIME = pulseIn(echoPin, HIGH);
  distance = TIME * 0.034 / 2;
  return distance;
}
