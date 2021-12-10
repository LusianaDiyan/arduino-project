unsigned int tick, hour = 0, minute = 0, sec = 0, ms = 0;
int PIN_START = 7;
int PIN_STOP = 6;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_START,INPUT_PULLUP);
  pinMode(PIN_STOP,INPUT_PULLUP);
  delay(1000);
  
  TCCR1A = 0x00; TCCR1B = 0X00; //default stopwatch mati
  TCNT1H = 0X00; TCNT1L = 0X00;
  ICR1H = 0X00; ICR1L = 0X00;
  OCR1AH = 0X00; OCR1AL = 0X00;
  OCR1BH = 0X00; OCR1BL = 0X00;
  Serial.println(sec);
}

void loop() {
  tick = TCNT1;

  //button start stop
  if(digitalRead(PIN_START)==LOW){
    TCCR1A = 0x00; TCCR1B = 0X04; //kondisi hidup TCCR1A = 0x00; TCCR1B = 0X04;
  }
  if(digitalRead(PIN_STOP)==LOW){
    TCCR1A = 0x00; TCCR1B = 0X00; // kondisi mati TCCR1A = 0x00; TCCR1B = 0X00;
    ms = sec = minute = hour = 0;
  }
  
  if (tick == 62500)
  {
    TCNT1 = 0;
    ms++;
    if(ms == 100){
      ms = 0; sec++;
      if(sec == 60){
        sec = 0; minute++;
        if(minute == 60){
          minute = 0; hour++;
          }
        }
      }
    Serial.print(hour); Serial.print(":"); Serial.print(minute); Serial.print(":");
    Serial.print(sec); Serial.print(":"); Serial.println(ms);
  }
}
