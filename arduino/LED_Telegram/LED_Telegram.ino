//EDISON SCIENCE CORNER
//EDISON SCIENCE CORNER
//EDISON SCIENCE CORNER


#include "CTBot.h"
CTBot myBot;

String ssid = "smartspacekk";     //  YOUR WIFI SSID
String pass = "smartspace09"; // YOUR WIFI PASSWORD
String token = "5066982616:AAHzrVTgm2lWRZV2CbdY0G4Na_bPf865d7w";   // REPLACE Token WITH YOUR TELEGRAM BOT TOKEN
int bulb1 = D0;            
int bulb2 = D1;                           
                                        

void setup() {
  Serial.begin(9600);
  Serial.println("Starting Bot...");
  myBot.wifiConnect(ssid, pass);

  myBot.setTelegramToken(token);

  if (myBot.testConnection())
    Serial.println("\ntestConnection OK");
  else
    Serial.println("\ntestConnection Not OK");
  pinMode(bulb1, OUTPUT);
  pinMode(bulb2, OUTPUT);
  digitalWrite(bulb1, LOW); 
  digitalWrite(bulb2, LOW);
}

void loop() {
  TBMessage msg;

  if (myBot.getNewMessage(msg)) {

    if (msg.text.equalsIgnoreCase("LIGHT ON")) {             
      digitalWrite(bulb1, HIGH);
      Serial.println("ON");
      myBot.sendMessage(msg.sender.id, "LIGHT is now ON");  
    }
    else if (msg.text.equalsIgnoreCase("LIGHT OFF")) {        
      digitalWrite(bulb1, LOW);    
      Serial.println("OFF");                         
      myBot.sendMessage(msg.sender.id, "LIGHT is now OFF"); 
    }
   else if (msg.text.equalsIgnoreCase("FAN ON")) {        
     digitalWrite(bulb2, HIGH);                             
      myBot.sendMessage(msg.sender.id, "FAN is now ON"); 
    }
    else if (msg.text.equalsIgnoreCase("FAN OFF")) {       
      digitalWrite(bulb2, LOW);                            
      myBot.sendMessage(msg.sender.id, "FAN is now OFF"); 
    }
    else {                                                   
      String reply;
      reply = (String)"Welcome " + msg.sender.username + (String)". Lets think try do!.";
      myBot.sendMessage(msg.sender.id, reply);             
    }
  }
  delay(100);
}
