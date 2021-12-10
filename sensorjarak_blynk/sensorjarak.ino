#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "Jarak"
#define BLYNK_DEVICE_NAME "Lusiana"

char auth[] = "eas9C-5lOMzq1HyXI5nqNYqSgN7eVNjS";

char ssid[] = "anna";
char pass[] = "adiana456";

WidgetLCD lcd(V1);

#define TRIGGERPIN D1
#define ECHOPIN D2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, OUTPUT);
  lcd.clear();
  lcd.print(0,0,"Jarak(cm) : ");
}

void loop() {
  // put your main code here, to run repeatedly:
  long durasi, jarak;
  digitalWrite(TRIGGERPIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIGGERPIN, LOW);
  durasi = pulseIn(ECHOPIN, HIGH);
  jarak = (durasi/2)/29.1;
  Serial.print(jarak);
  Serial.println("cm");

  lcd.clear();
  lcd.print(0, 0, "Jarak(cm)");
  lcd.print(7, 1, jarak);
  Blynk.run();

  if(jarak<5){
      Serial.println("Jarak terlalu dekat");
      Blynk.notify("Jarak terlalu dekat");
    } else {
         Serial.println("Jarak jauh");
          Blynk.notify("Jarak jauh");
      }

   delay(1000);
}
