#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
//Motor PINs
#define ENA D0
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENB D5
 
bool motorcutting = 0;
int Speed;
char auth[] = "BwduIIMzHvbR2h3fVhRWgpTQYPLjD3k9"; //Enter your Blynk application auth token
char ssid[] = "nodemcu"; //Enter your WIFI name
char pass[] = "Nodemcu123"; //Enter your WIFI passowrd
 
 
void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
 
  Blynk.begin(auth, ssid, pass);
}
 
BLYNK_WRITE(V2) {
  motorcutting = param.asInt();
}
 
BLYNK_WRITE(V4) {
  Speed = param.asInt();
}
 
void smartcar() {
  if (motorcutting == 1) {
    cutting();
    Serial.println("cutting");
  } else if (motorcutting == 0) {
    carStop();
    Serial.println("carstop");
  }
}
void loop() {
  Blynk.run();
  smartcar();
}
 
void cutting() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(1000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
