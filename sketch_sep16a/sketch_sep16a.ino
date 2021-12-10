void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT_PULLUP);
  Serial.begin(9600);
}

unsigned char var=50;
void loop() {
  digitalWrite(2, HIGH); delay(var);
  digitalWrite(3, HIGH); delay(var);
  digitalWrite(4, HIGH); delay(var);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

  delay(var);
  if(digitalRead(5)== LOW)
  {
    var++;
    Serial.println(var);
    delay(10);
  }
}
