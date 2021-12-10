void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  TCCR1A=0xA2;
  TCCR1B=0x14;
  ICR1H=0x02;
  ICR1L=0x71;
}

void loop() {
  for (int i=3; i<63;i++)
  {
    OCR1A = i;
    Serial.println(i);
    delay(30);
  }
  delay(1000);

  for (int i=3; i>31;i++)
  {
    OCR1A = i;
    Serial.println(i);
    delay(30);
  }
  delay(1000);

}
