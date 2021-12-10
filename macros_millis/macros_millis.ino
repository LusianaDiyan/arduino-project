int pbutton=2;
int deb=0;
unsigned long mill=0;

void setup() {
  
  TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
  TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) | (0<<CS12) | (1<<CS11) | (1<<CS10);
  TCNT1H=0x00;
  TCNT1L=0x00;
  OCR1AH=0x00;
  OCR1AL=0xF9;//F9
  TIMSK1=(0<<ICIE1) | (0<<OCIE1B) | (1<<OCIE1A) | (0<<TOIE1);
  
  Serial.begin(9600); 
  pinMode(pbutton,INPUT_PULLUP);
  sei();
}

ISR(TIMER1_COMPA_vect) {
  TCNT1=0;
    mill++; 
}

unsigned long m,s,mins;

void nilmillis(){
  cli();
  m=mill;
  sei();
   if(mill/1000){
    s++;mill=0;
      if(s/60){
        mins++;
        s=0;
      }
   }
    
  Serial.print(mins);
  Serial.print(":");  
  Serial.print(s);
  Serial.print(":");
  Serial.print((m/10)); //millis
  Serial.print(":");
  Serial.println(TCNT1*4/10); //micros
  }
  
bool ispress=0;
void readdigi(){
  if(digitalRead(pbutton)==0){
    deb++;
    if(deb>=6){
      if(ispress){
      Serial.println("Timer stop");}
      else{Serial.println("Timer start ");}
      
      deb=0;
      mill=0,TCNT1=0,s=0,mins=0;
      ispress=!ispress;
      }
      delay(75);
    }
}

void loop() {
  readdigi();
  if(ispress){
    nilmillis();
  }
}
