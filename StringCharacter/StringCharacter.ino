char input[99];
boolean addchar=false, serialDataValid;
int checksumvalidasi=0, i=0;
byte checksum;
int jmlChar[0];
String serialBuffer="";
String counter[3]="";
byte t;
char bar;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    digitalWrite(13, !digitalRead(13));
    delay(500);
    while(input[i] != 0x0D){
      input[i] = Serial.read();
      serialBuffer+=input[i];
      if(input[i] < 30 && input[i]>122)addchar=true;
      }
      i++;
      int r=0, q=0;
      Serial.print("  input = ");
      Serial.println(serialBuffer);
      while(r<serialBuffer.length()-1){
        if(serialBuffer.charAt(r) != ','){
          counter[q]+=serialBuffer.charAt(r);
          }else{
            Serial.print("counter ");
            Serial.println(": "+counter[q]);
            q++;
            }
            r++;
        }
        Serial.println("counter 3 : "+counter[q]+"");
    }
}
