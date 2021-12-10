#include <avr/wdt.h>

#define WDPS_2S   (0<<WDP3)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0)
#define WDPS_4S   (1<<WDP3)|(0<<WDP2)|(0<<WDP1)|(0<<WDP0)
#define WDPS_8S   (1<<WDP3)|(0<<WDP2)|(0<<WDP1)|(1<<WDP0)

byte LM35= 7;
float suhu, data;
const int LED = 4;

void WDTOn()
{
  #pragma optsize-
  WDTCSR= (1<<WDCE) | (1<<WDE);
  WDTCSR=(0<<WDIF) | (0<<WDIE) | (0<<WDCE) | (1<<WDE) |WDPS_2S;
  #ifdef _OPTIMIZE_SIZE_
  #pragma optsize+
  #endif
}

void WDTreset()
{
  WDTCSR = 0x00;
}

void setup(){
  Serial.begin(9600);
  //wdt_enable(WDTO_1S);
  //Serial.println("Start");
  //WDTOn(); //timeout 2 detik
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

  if (suhu > 28)       // jika nilaiLM35 sama dengan 28
  {
    digitalWrite(LED, HIGH); // LED menyala
    Serial.println("device on");
    delay(200);
    if(LED == LOW)
    {
      WDTOn();
      Serial.println("WDT On");
    }
  }
  else
  {
    digitalWrite(LED, LOW);
    Serial.println("standby"); 
    wdt_reset();
  }
}
