#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define ldrPin A0
#define ledPin D2 
BlynkTimer timer;

char auth[] = "eas9C-5lOMzq1HyXI5nqNYqSgN7eVNjS";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Galaxy A51C010";
char pass[] = "wmtc9748";

void sendSensor()
{
  int sensorValue = analogRead(ldrPin);
  Blynk.virtualWrite(V5, sensorValue);
  if(sensorValue < 400){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
}
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(ledPin, OUTPUT);
  timer.setInterval(1000L, sendSensor);
}
void loop()
{
  Blynk.run();
  timer.run();
}
