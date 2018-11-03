const byte number[16] = {
  B00111111, // 0
  B00000110, // 1
  B01011011, // 2
  B01001111, // 3
  B01100110, // 4
  B01101101, // 5 
  B01111101, // 6
  B00000111, // 7
  B01111111, // 8
  B01101111, // 9
  B01110111,//A
  B01111111,//B
  B00111001,//C
  B00111111,//D
  B01111001,//E
  B01110001//F
};

int count=0;

void setup() {
  // put your setup code here, to run once:
  for(int i=2; i<=13; ++i){
    pinMode(i, OUTPUT);
  };
  for(int i=10;i<=13; ++i){
   digitalWrite(i,LOW); 
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  fndDisplay(count);

  if(count >= 15) count = 0;
  else ++count;
  
  delay(1000);
}

void fndDisplay(int displayValue){
  boolean bitValue;

  for(int i=2; i<=9; ++i){
    digitalWrite(i, LOW);
  };

  for(int i=0; i<=7; ++i){
    bitValue = bitRead(number[displayValue],i);
    digitalWrite(i+2, bitValue);
  };
}
