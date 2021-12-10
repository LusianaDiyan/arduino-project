#define Do 523
#define re 587
#define mi 659
#define fa 698
#define sol 784
#define la 880
#define si 990
#define Do1 1056

String tohex(int dec){
  char hexaDeciNum[100];
    int i = 0;
    while (dec != 0) {
        // temporary variable to store remainder
        int temp = 0;
 
        // storing remainder in temp variable.
        temp = dec % 16;
 
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        dec = dec / 16;
    }
    
    String tops;
    // printing hexadecimal number array in reverse order
    for (int j = i - 1; j >= 0; j--){
      Serial.print(hexaDeciNum[j]);
      tops+=hexaDeciNum[j];
    }
    return tops;
}

//mengatur nada
void tonePFC(int freq,int lengths,int pauses){
 long decimalnum, quotient, remainder;
//menghitung top = f_clock/(2*n*frequency)
int top;
    long fclk=16000000;
    top=fclk/(16*freq);
    
int duty=top/2; //mengatur nilai duty cycle
    //mengatur timer nilai count top
    String tops,sduty;  
    ICR1H=(top>>8)&0x00FF; //memastikan nilainya 8 bit
    
    ICR1L=top;
    OCR1AH=(duty>>8)&0x00FF;
    OCR1AL=duty;
    delay(lengths);
    
    ICR1H=0;
    ICR1L=0;
    OCR1AH=0;
    OCR1AL=0;
    delay(pauses);
}

void setup() {
  Serial.begin(115200);
  pinMode(9,OUTPUT);
  //codevisionAVR
  TCCR1A=(1<<COM1A1) | (0<<COM1A0) | (1<<COM1B1) | (1<<COM1B0) | (0<<WGM11) | (0<<WGM10);
  TCCR1B=(0<<ICNC1) | (0<<ICES1) | (1<<WGM13) | (0<<WGM12) | (0<<CS12) | (1<<CS11) | (0<<CS10);
  TCNT1H=0x00;
  TCNT1L=0x00;
  ICR1H=0x07;
  ICR1L=0x78;
  OCR1AH=0x03;
  OCR1AL=0x89;
  OCR1BH=0x03;
  OCR1BL=0x89;
}

void loop() {
  //tangga nada lagu
  tonePFC(sol,220,120);
  tonePFC(sol,220,120);
  tonePFC(sol,220,200);
  
  tonePFC(fa,220,120);
  tonePFC(mi,110,60);
  tonePFC(re,110,60);
  tonePFC(mi,110,60);
  tonePFC(fa,110,60);
  tonePFC(sol,220,120);
  tonePFC(fa,220,120);
  tonePFC(mi,220,120);
  tonePFC(re,220,120);
  tonePFC(fa,220,120);
  tonePFC(mi,220,200);
  
  tonePFC(la,220,120);
  tonePFC(la,220,120);
  tonePFC(la,220,120);
  tonePFC(si,220,120);
  tonePFC(Do1,220,200);
  
  tonePFC(si,220,120);
  tonePFC(la,110,60);
  tonePFC(sol,110,60);
  tonePFC(fa,220,120);
  tonePFC(sol,220,120);
  tonePFC(mi,220,200);

  tonePFC(re,220,120);
  tonePFC(re,220,120);
  tonePFC(re,220,120);
  tonePFC(mi,220,120);
  tonePFC(fa,220,200);
  tonePFC(mi,220,120);
  tonePFC(re,220,120);
  tonePFC(mi,220,120);
  tonePFC(fa,220,120);
  tonePFC(sol,220,200);
  
  tonePFC(la,220,120);
  tonePFC(Do1,220,120);
  tonePFC(si,220,120);
  tonePFC(la,220,120);
  tonePFC(sol,220,120);
  tonePFC(re,220,120);
  tonePFC(fa,220,120);
  tonePFC(mi,220,120);
  tonePFC(re,220,120);
  tonePFC(Do,160,160);  
  delay(2000);
}
