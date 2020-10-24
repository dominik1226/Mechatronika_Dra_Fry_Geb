Kod na serwo,przyciski, lampkę

#####################################

#include "Servo.h"
#define button1 5
#define button2 6
#define led 4
#define servo 9
Servo myservo;
int pos = 0;

void setup() 
{
	 myservo.attach(servo);
	 pinMode(led, OUTPUT);
 	pinMode(button1, INPUT);
	 pinMode(button2,INPUT);
 	myservo.write(90);
}

void loop() 
{
	if(digitalRead(button1) == HIGH)
	{
	 	 myservo.write(0);
	 	 digitalWrite(led,HIGH);
 		 back();
 	 }
 	if(digitalRead(button2) == HIGH)
 	{
    		myservo.write(180);
   		 digitalWrite(led,LOW);
  	}
  
}

void back()
{
  delay(2000);
  myservo.write(90);
  digitalWrite(led,LOW);
}



##############################

Kod na LCD i dalmierz

#############################

#define trigPin 12
#define echoPin 11

#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); //wejscie wyzwalające
  pinMode(echoPin, INPUT); //z wyjścia echo odczytujemy zmierzona odleglosc
  lcd.begin(16, 2); //Deklaracja typu
  lcd.clear();
}
 
void loop() 
{
  Serial.print(zmierz());
  Serial.println(" cm");
  
  pokaz_na_lcd();
}

int zmierz()
{
  long czas, dystans;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(12);
  digitalWrite(trigPin, LOW);
  
  czas = pulseIn(echoPin, HIGH); //czas zmierzonego sygalu, dlugosc sygnalu jest proporcjonalna do odleglosci
  dystans = czas / 58; // 58 Wynika z czasu przez jaki dźwięk pokonuje odległość 1 cm oraz wzoru na odległość jaką przedstawił producent

   return dystans;
}

int pokaz_na_lcd(){
  lcd.setCursor(0,1);
  lcd.print("Dystans:");
  lcd.setCursor(9,1);
  lcd.print(zmierz());
  lcd.setCursor(13,1);
  lcd.print("cm");
  delay(200);
  lcd.clear(); 
}
