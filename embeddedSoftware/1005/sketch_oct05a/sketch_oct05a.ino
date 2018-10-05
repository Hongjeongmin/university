const int ledA = 3;
const int ledB =5;

void setup() {
  pinMode(ledA,OUTPUT);
  pinMode(ledA,OUTPUT);

}

void loop() {
  digitalWrite(ledA,HIGH);
  digitalWrite(ledB,LOW);
  delay(100);
  digitalWrite(ledA,LOW);
  digitalWrite(ledB,HIGH);
  delay(100);
  
}
