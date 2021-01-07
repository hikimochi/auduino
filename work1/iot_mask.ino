#include "SR04.h"

// Ultrasonic
#define TRIGGER_PIN 13
#define ECHO_PIN 12
SR04 sr04 = SR04(ECHO_PIN, TRIGGER_PIN);
long distance;

// 人感センサ
int pir_in=10;

// Buzzer
int buzzer = 11;

// 1-digit
int a=2; 
int b=1; 
int c=6; 
int d=7; 
int e=8; 
int f=3; 
int g=4; 
int dp=5;  

void setup()//初期設定するところ
{
  // Ultrasonic
  Serial.begin(9600);
  delay(1000);

  // buzzer
  pinMode(buzzer,OUTPUT);//12番ポートをOUTPUTとして設定

  // 1digit
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  // 人感センサ
  pinMode(pir_in, INPUT_PULLUP);
}

void loop()//ループ関数
{
  distance=sr04.Distance();
  // モニタで確認するために設定
  Serial.print(distance);
  Serial.println("cm");

  // main
  if (digitalRead(pir_in) == HIGH){
    buzzer_display_by_distance(distance);
  } else {
    delay(2000);
  }

  clearDisplay();
}

void buzzer_display_by_distance(long distance)
{
  if (distance < 10){
    display1();
    buzzer1();
  } else if ((distance >= 10) && (distance < 50)){
    display2();
    buzzer2();
  } else if ((distance >= 50) && (distance < 100)){
    display3();
    buzzer3();
  } else{
    display4();
    buzzer4();
  }
  clearDisplay();
}

void display1() 
{ 
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
} 

void display2() 
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(d,HIGH);
} 

void display3() 
{ 
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);  
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(g,HIGH);
} 

void display4() 
{ 
  digitalWrite(f,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
} 

void display5() 
{ 
  digitalWrite(a,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
} 

void display6() 
{ 
  digitalWrite(a,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);  
  digitalWrite(e,HIGH);  
} 

void display7() 
{   
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
} 

void display8() 
{ 
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);  
  digitalWrite(e,HIGH);  
  digitalWrite(f,HIGH);  
} 

void clearDisplay() 
{ 
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(g,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);  
  digitalWrite(e,LOW);  
  digitalWrite(f,LOW);  
} 

void display9() 
{ 
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);  
  digitalWrite(f,HIGH);  
} 

void buzzer1()
{
  for(int i=0;i<50;i++)
  {
    digitalWrite(buzzer,HIGH);
    delay(20);
    digitalWrite(buzzer,LOW);
    delay(20);
  }
}

void buzzer2()
{
  for(int i=0;i<20;i++)
  {
    digitalWrite(buzzer,HIGH);
    delay(50);
    digitalWrite(buzzer,LOW);
    delay(50);
  }
}

void buzzer3()
{
  for(int i=0;i<10;i++)
  {
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
  }
}

void buzzer4()
{
  for(int i=0;i<5;i++)
  {
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
    delay(200);
  }
}

void buzzer5()
{
  for(int i=0;i<2;i++)
  {
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    delay(500);
  }
}