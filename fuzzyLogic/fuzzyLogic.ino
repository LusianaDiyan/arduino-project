float suhu;
float dingin,hangat,panas;
float pwm;
float Lambat,Sedang,Cepat;

int pwmLambat = 100;
int pwmSedang = 200;
int pwmCepat = 250;

float PWM0, PWM1, PWM2, PWMTot, OutputPWM;
float DEF0, DEF1, DEF2, DEFTot;

int rule[9] = {0,0,0,0,0,0,0,0,0};

unsigned char suhuDingin(){
  if (suhu <= 22.5){dingin =1;}
  else if (suhu > 22.5 && suhu <= 25){dingin=(25-suhu)/(25-22.5);}
  else if (suhu >= 25){dingin =0;}
  return dingin;
}
unsigned char suhuHangat(){
  if (suhu <= 22.5){hangat =0;}
  else if (suhu >=22.5 && suhu <=25){hangat=(suhu-22.5)/2.5;}
  else if (suhu > 25 && suhu <=27.5){hangat=(27.5-suhu)/2.5;}
  else if (suhu > 27.5){hangat =0;}
  return hangat;
}
unsigned char suhuPanas (){
  if (suhu <= 22.5 ){panas =0;}
  else if (suhu > 25 && suhu <=27.5){panas=(suhu-25)/2.5;}
  else if (suhu > 27.5){panas =1;}
  return panas;
}
unsigned char pwmLambatt(){
  if (pwm <= 100){Lambat =1;}
  else if (pwm >=100 && pwm <=200){Lambat=(200-pwm)/100;}
  else if (pwm > 200){Lambat =0;}
  return Lambat;
}
unsigned char pwmSedangg(){
  if (pwm <= 100){Sedang =0;}
  else if (pwm >=100 && pwm <=200){Sedang=(pwm-100)/100;}
  else if (pwm >=200 && pwm <=250){Sedang=(200-pwm)/50;}
  else if (pwm > 250){Sedang =0;}
  return Sedang;
}
unsigned char pwmCepatt (){
  if (pwm <= 100){Lambat =1;}
  else if (pwm >=200 && pwm <=250){Cepat=(pwm-200)/50;}
  else if (pwm > 250){Cepat =0;}
  return Cepat;
}
unsigned char defuzzifikasi(){
  PWM0 = (rule[0]*pwmLambat) + (rule[1]*pwmLambat) + (rule[2] * pwmLambat);
  PWM1 = (rule[3]*pwmLambat) + (rule[4]*pwmSedang) + (rule[5] * pwmCepat);
  PWM2 = (rule[6]*pwmCepat) + (rule[7]*pwmCepat) + (rule[8] * pwmCepat);
  PWMTot = PWM0 + PWM1 + PWM2;

  DEF0 = (rule[0] + rule[1] + rule[2]);
  DEF1 = (rule[3] + rule[4] + rule[5]);
  DEF2 = (rule[6] + rule[7] + rule[8]);
  DEFTot = DEF0 + DEF1 + DEF2;

  OutputPWM = PWMTot/DEFTot;
  Serial.print("DC PWM : ");
  Serial.println(OutputPWM);
}
void fuzzifikasi(){
  suhuDingin();
  suhuHangat();
  suhuPanas();
  pwmLambatt();
  pwmSedangg();
  pwmCepatt();
  defuzzifikasi();
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
suhu = 54; //memasukan nilai suhu 54 derajat
pwm = 104; //memasukan nilai pwm 104
fuzzifikasi(); // memanggil fungsi fuzzifikasi untuk menghitung keanggotaan masing2 variable
Serial.print("dingin : ");
Serial.print(dingin);
Serial.print("t  ");
Serial.print("hangat : ");
Serial.print(hangat);
Serial.print("t  ");
Serial.print("panas : ");
Serial.println(panas);
Serial.print("lambat : ");
Serial.print(Lambat);
Serial.print("t  ");
Serial.print("sedang : ");
Serial.print(Sedang);
Serial.print("t  ");
Serial.print("cepat : ");
Serial.println(Cepat);
}
void loop() {
  // put your main code here, to run repeatedly:
}
