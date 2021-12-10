//#define CLK
#define DT 3
#define SW 2

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);
#pragma optsize-
  CLKPR = (1 << CLKPCE);
  CLKPR = (0 << CLKPCE) | (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0);
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

  EICRA = (0 << ISC11) | (0 << ISC10) | (0 << ISC01) | (1 << ISC00);
  EIMSK = (0 << INT1) | (1 << INT0);
  EIFR = (0 << INTF1) | (1 << INTF0);
  PCICR = (0 << PCIE2) | (0 << PCIE1) | (0 << PCIE0);

  sei();
}

ISR(INT0_vect) {
  EIFR &= ~(1 << INTF0);
  if (digitalRead(DT) == 1) {
    counter++;
  }
  else {
    counter--;
  }
  Serial.print("counter: ");
  Serial.println(counter);
}

void loop() {
  // put your main code here, to run repeatedly:

}
