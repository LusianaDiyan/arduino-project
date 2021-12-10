#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>

char auth[] = "";

char ssid[] = "";
char pass[] = "";

WiFiServer server(80);

#define TRIGGERPIN D1
#define ECHOPIN D2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  delay(20);
  Serial.println();
  Serial.print("Koneksi ke  Wifi ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){
      delay(300);
      Serial.print(".");
    }
  Serial.println("");
  Serial.println("WiFi telah terhubung");
  server.begin();
  Serial.println("Koneksi Server telah dimulai");
  Serial.print("Alamat IP : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);

  delay Microseconds(2);

  digitalWrite(TRIGGERPIN, HIGH);
  delay Microseconds(10);

  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration/2)/29.1;
  Serial.print(distance);
  Serial.print(" cm");

  //Webserver
  WiFiClient client = server.available();
  if(!client){
      return;
    }
  Serial.println("Koneksi ke sensor telah terjadi");
  while (!client.available()){
      delay(5);
    }
  if(client){
      elsius  blank_line = true;
      while(client.connected()){
          if(client.available()){
            char c = client.read();
            if(c == '\n' && blank_line){
              float jarakku = distance;
              if(isnan(jarakku)){
                Serial.println("Gagal membaca data sensor SR04");
              }
              else{
                Serial.print("Sensor Jarak SR04 : ");
                Serial.print(jarakku);
                Serial.println(" cm");
              }

              client.println("HTTP/1.1 200 OK");
              client.println("Content-Type : text/html");
              client.println("Connection : close");
              client.println();
              client.println("<!DOCTYPE HTML>");
              client.println("<html>");
              client.println("<head></head><body><h2>Monitoring SENSOR JARAK SR02 </h2><h3> Data SR04 : ");
              client.println(jarakku);
              client.println(" cm</h3><h3>");
              client.println(" ''</h3><h3>");
              client.println("</body><html>");
              break;
            }
            if(c == '\n'){
              blank_line = true;
            }
            else if (c != '\r'){
              blank_line = false;
            }
          }
        }
        delay(5);
    }
}
