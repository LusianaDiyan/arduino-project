boolean state = false;

void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    char val = Serial.read();

    if(val == 't'){
      if(state == false){
        state = true;
        digitalWrite(3, HIGH);
        }else{
          state = false;
          digitalWrite(3, LOW);
         }
      }
    }
}
