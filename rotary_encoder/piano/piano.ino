#define T_C 262
#define T_Db 277
#define T_D 294
#define T_Eb 311
#define T_E 330
#define T_F 349
#define T_Gb 370
#define T_G 392
#define T_Ab 415
#define T_A 440
#define T_Bb 466
#define T_B 494
#define T_C1 523

// C F C C F G C F C G C
boolean state = false;
const int buzzer = 8;

void setup() {
  pinMode(buzzer, OUTPUT); //Set pin as an output
  Serial.begin(9600); //Start serial communication @9600 bps
}

void loop() {
  if (Serial.available()) {
    char val = Serial.read();
    if (val == 'c') {
      state = true;
      tone(buzzer, T_C);
    }
    if (val == 'z') {
      state = true;
      tone(buzzer, T_Db);
    }
    if (val == 'd') {
      state = true;
      tone(buzzer, T_D);
    }
    if (val == 'y') {
      state = true;
      tone(buzzer, T_Eb);
    }
    if (val == 'e') {
      state = true;
      tone(buzzer, T_E);
    }
    if (val == 'f') {
      state = true;
      tone(buzzer, T_F);
    }
    if (val == 'x') {
      state = true;
      tone(buzzer, T_Gb);
    }
    if (val == 'g') {
      state = true;
      tone(buzzer, T_G);
    }
    if (val == 'w') {
      state = true;
      tone(buzzer, T_Ab);
    }
    if (val == 'a') {
      state = true;
      tone(buzzer, T_A);
    }
    if (val == 'v') {
      state = true;
      tone(buzzer, T_Bb);
    }
    if (val == 'b') {
      state = true;
      tone(buzzer, T_B);
    }
    if (val == 'h') {
      state = true;
      tone(buzzer, T_C1);
    }
    delay(500);
    val = 'o';
    noTone(buzzer);    
  }
}
