const int inputPin = 2;

long startTime = 0;
long swCountTimer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(inputPin) == LOW)
  {
    startTime = millis();
    while(digitalRead(inputPin) == LOW);

    swCountTimer = millis() - startTime;

    Serial.print(swCountTimer);
    Serial.println(" ms");
  };
}
