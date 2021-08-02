
//Inclueix i defineix Blynk i la ESP8266

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "1j5XUb-6UxW58jIsG1vFFv6cUITpydlG"; //Escriu la clau que s'ha enviat al teu correu
char ssid[] = "ADAMO-D850"; //Nom de la teva wifi
char pass[] = "TP4INUWIHZZBTV"; //Clau de la teva wifi

WidgetLED led1(V1);

BlynkTimer timer;

//El led està parpellejant en el monitor serial

void blinkLedWidget() 
{
  if (led1.getValue()) {
    led1.off();
    Serial.println("LED on V1: off");
  } else {
    led1.on();
    Serial.println("LED on V1: on");
    
  }
}

void setup()
{

  Serial.begin(9600); //La freqüència en que va la placa

  Blynk.begin(auth, ssid, pass);
  // Si tens un servidor pots fer-lo servir amb les funcions de sota, treient la dobla barra
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer.setInterval(1000L, blinkLedWidget);
}

void loop()
{
  Blynk.run(); //Es conecta amb Blynk
  timer.run();
}
