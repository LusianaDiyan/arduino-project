#include <avr/wdt.h>

byte LM35= 7;
float suhu, data;
int LED = 4;

void setup(){
  Serial.begin(9600);
  wdt_enable(WDTO_1S);
  pinMode(LED, OUTPUT);
}

void loop(){
  data = analogRead(LM35);   // menyimpan nilai dari LM35 ke variabel nilaiLM35
  suhu = data * 0.126 ;   // konversi nilai dari LM35 menjadi Derajat Celcius
  Serial.print("data : ");
  Serial.print(data);     // menampilkan nilai dari LM35 ke Serial Monitor
  Serial.print(" ; suhu : ");
  Serial.println(suhu);
  delay(500);                     // memberi jeda sebanyak 500 milidetik

  if (suhu < 35 && suhu > 25)       // jika nilaiLM35 25 - 35
  {
    digitalWrite(LED, HIGH); // LED menyala
    Serial.println("device on");
  }
  else
  {
    digitalWrite(LED, LOW); // LED Off
    wdt_reset();
    Serial.println("standby");
  }
}
