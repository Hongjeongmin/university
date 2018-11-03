// 풀업 스위치
const int ledPin = 15;
const int inputPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
}

void loop() {
   boolean state = digitalRead(15);
   digitalWrite(2,HIGH);
}
