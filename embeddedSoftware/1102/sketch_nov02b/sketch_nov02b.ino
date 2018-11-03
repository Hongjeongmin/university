

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A0);
  Serial.println(light);
  int ledLight = map(light,0,1023,255,0);
  analogWrite(9,ledLight);
}
