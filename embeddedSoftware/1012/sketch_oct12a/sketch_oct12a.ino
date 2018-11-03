// FND 0에서 9까지 출력 (2~8)
//세븐 세그먼트


const byte number[16]= {
  B00111111,
  B00000110,
  B01011011,
  B01001111,
  B01100110,
  B01101101,
  B01111101,
  B00000111,
  B01111111,//8
  B01101111,
  //////0~9
  B01110111,//A
  B01111111,//B
  B00111001,//C
  B00111111,//D
  B01111001,//E
  B01110001//F
};


void fndDisplay(int displayValue){
  boolean bitValue;

  for(int i=2;i<=9;++i){
    digitalWrite(i, LOW);
  }
  for(int i=0;i<=7;++i){
    bitValue = bitRead(number[displayValue], i);
    digitalWrite(i+2, bitValue);
  }
}

void setup() {
  Serial.begin(9600);
  for(int i=2;i<=9;++i){
    pinMode(i, OUTPUT);
  }
  digitalWrite(9, LOW);
}

void loop() {
  for(int k=0;k<=15;++k){
    fndDisplay(k);
    delay(1000);
  }
}
