void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
      char inChar = Serial.read();
      if(inChar == 'b'){
          Serial.println("LED1 OFF");
          digitalWrite(2, HIGH);
        }
      if(inChar == 'a'){
          Serial.println("LED1 ON");
          digitalWrite(2, LOW);
        }
      if(inChar == 'd'){
        Serial.println("LED2 OFF");
          digitalWrite(3, HIGH);
        }
      if(inChar == 'c'){
          Serial.println("LED2 ON");
          digitalWrite(3, LOW);
        }
    }
}
