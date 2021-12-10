int a;
int b;
int h;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Rumus Segitiga");
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.print("a = ");
    while(Serial.available()<= 0);
    a = Serial.read();
    a = a - 48;
    Serial.print(a);
    Serial.print("  b = ");
    while(Serial.available()<= 0);
    b = Serial.read();
    b = b - 48;
    Serial.print(b);
    h = sqrt(a*a + b*b);
    Serial.print("  h = "); Serial.println(h);
}
