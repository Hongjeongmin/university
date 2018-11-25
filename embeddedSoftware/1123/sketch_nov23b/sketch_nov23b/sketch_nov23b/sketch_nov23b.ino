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
  digitalWrite(DIR1, direction); // 초기방향은 정방향
  digitalWrite(PWM1, !direction); // 최고 속도

  pinMode(sw, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(sw)) {
    direction = !direction;
  }

  if(direction) {
    Serial.println("Clockwise...");
  }
  else {
    Serial.println("Anti-Clockwise....");
  }
  digitalWrite(DIR1, direction);
  digitalWrite(PWM1, !direction);

  delay(200);

  
}
