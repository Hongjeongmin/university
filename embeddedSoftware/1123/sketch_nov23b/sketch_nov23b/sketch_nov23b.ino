int ENABLE1 = 38;
int PWM1 = 9;
int DIR1 = 39;


void setup() {
  // put your setup code here, to run once:
  pinMode(ENABLE1, OUTPUT);
  digitalWrite(ENABLE1, LOW); // 모터 제어 불능 상태
  pinMode(PWM1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  
  
}

void loop() {
  // 모터 제어
  digitalWrite(ENABLE1, HIGH); // 모터 제어 가능 상태

  digitalWrite(DIR1, HIGH); // 정방향 회전
  digitalWrite(PWM1, LOW); // 최고 속도
  delay(4000);
  digitalWrite(PWM1, HIGH); // 속도 0

  delay(200);

  digitalWrite(DIR1, LOW); // 역방향 회전
  digitalWrite(PWM1, HIGH); // 최고 속도
  delay(4000);
  digitalWrite(PWM1, LOW); // 속도 0

  delay(200);

  digitalWrite(ENABLE1, LOW);
}
