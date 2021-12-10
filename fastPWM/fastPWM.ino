int pwmA = 9, pwmB = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  
  TCCR1A=(1<<COM1A1) | (0<<COM1A0) | (1<<COM1B1) | (0<<COM1B0) | (1<<WGM11) | (0<<WGM10);
  TCCR1B=(0<<ICNC1) | (0<<ICES1) | (1<<WGM13) | (1<<WGM12) | (0<<CS12) | (1<<CS11) | (0<<CS10);
  ICR1H=0x07;
  ICR1L=0xCF;
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i<=1999; i+=3)
  {
    OCR1A = i;
    Serial.println(OCR1A);
  }
  for (int i=1999; i<=0; i-=3)
  {
    OCR1A = i;
    Serial.println(OCR1A);
  }
}
