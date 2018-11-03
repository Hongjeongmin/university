

void setup() {
  pinMode(2,OUTPUT);
  pinMode(15,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int wsInput = digitalRead(15);

  if(wsInput == LOW)
      digitalWrite(2,HIGH);
    else
      digitalWrite(2,LOW);

}
