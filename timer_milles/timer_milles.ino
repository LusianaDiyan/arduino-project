#define btn 3

unsigned int tick, microsc = 0, sec = 0, ms = 0;
int i = 0;

void setup() {
  // For diagnostics.
  Serial.begin(115200);
  pinMode(btn, INPUT_PULLUP);
  Serial.println("Starting up...");

  TCCR1A = (0 << COM1A1) | (0 << COM1A0) | (0 << COM1B1) | (0 << COM1B0) | (0 << WGM11) | (0 << WGM10);
  TCCR1B = (0 << ICNC1) | (0 << ICES1) | (0 << WGM13) | (1 << WGM12) | (0 << CS12) | (1 << CS11) | (1 << CS10);
  TCNT1H = 0x00;
  TCNT1L = 0x00;
  ICR1H = 0x00;
  ICR1L = 0x00;
  OCR1AH = 0x00;
  OCR1AL = 0xF9;
  OCR1BH = 0x00;
  OCR1BL = 0x00;
  TIMSK1=(0<<ICIE1) | (0<<OCIE1B) | (1<<OCIE1A) | (0<<TOIE1);

  sei();
}

ISR(TIMER1_COMPA_vect) {
  microsc++;
  if (microsc == 1000) {
    ms++;
    microsc = 0;
    if(ms == 1000){
      sec++;
      ms = 0;
    }
  }
  /*tick = TCNT1;
  
  if (digitalRead(btn) == 1){
    i++;
  }else{
    sec = ms = microsc = 0;
  }
  
  if (tick == 1000)
  {
    TCNT1 = 0;
    microsc++;
    if(microsc == 1000){
      microsc = 0; 
      ms++;
      if(ms == 100){
        ms = 0; 
        sec++;
        }
      }
    Serial.print(sec); Serial.print(":");
    Serial.print(ms); Serial.print(":"); 
    Serial.println(microsc);
  }*/
}

void loop() {
  //Serial.println("test");
  //delay(500);

    Serial.print(sec);
    Serial.print(" : ");
    Serial.print(ms);
    Serial.print(" : ");
    Serial.println(microsc);
}
