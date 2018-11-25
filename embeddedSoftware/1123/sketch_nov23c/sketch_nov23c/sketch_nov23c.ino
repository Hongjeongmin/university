int ENABLE1 = 38;
int PWM1 = 9;
int DIR1 = 39;

int sw = 14;
boolean direction = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENABLE1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(DIR1, OUTPUT);

  digitalWrite(ENABLE1, HIGH); // 모터 제어 가능
  
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(A0);
  int speed = map(reading, 0, 1023, -255, 255);

  if(speed > 0) {
    digitalWrite(DIR1, HIGH);
    int pwm_value = 255 - speed;
    analogWrite(PWM1, pwm_value);
    Serial.print(String("Reading : ") + reading );
    Serial.println(String(", Clockwise : ") + speed);
  }
  else {
    digitalWrite(DIR1, LOW);
    int pwm_value = abs(speed);
    analogWrite(PWM1, pwm_value);
    Serial.print(String("Reading : ") + reading );
    Serial.println(String(", Anti-Clockwise : ") + pwm_value);
  }

  delay(20);
}
