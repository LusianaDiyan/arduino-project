#define PIN_SWITCH 2
byte i;
void setup() {
  pinMode(PIN_SWITCH, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
//  if(digitalRead(PIN_SWITCH) == LOW)
//  {
//    i++;
//    Serial.println(i);
//  }

  
//  while(digitalRead(PIN_SWITCH));//selama button dilepas
//  i++; //falling edge
//  Serial.println(i);
//  while(!digitalRead(PIN_SWITCH));//selama button ditekan

  if(digitalRead(PIN_SWITCH)== LOW){
    delay(10);
    if(digitalRead(PIN_SWITCH)==LOW){
        i++;
        pinMode(PIN_SWITCH, OUTPUT);
        digitalWrite(PIN_SWITCH, LOW);
        Serial.println(i);
        digitalWrite(13, HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
      }
    }
}
