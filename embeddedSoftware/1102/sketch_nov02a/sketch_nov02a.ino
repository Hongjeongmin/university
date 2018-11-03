// 0번 아날로그 핀을 포텐쇼미터 입력으로 설정한다.
const int potentioMeterPin = 0;

// 13번 핀에 연결되어 있는 내장 LED를 출력으로 사용한다.
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adcValue; // 실제 센서로부터 읽은 값(0~1023)
  int duty;     // LED 점멸 주기(0~100%)

  // 포텐쇼미터 값을 읽는다.
  adcValue = analogRead(potentioMeterPin);
  // 포텐쇼미터 값을 0~100의 범위로 변경한다.
  duty = map(adcValue, 0, 1023, 0, 100);

  // LED를 duty ms 만큼 점등한다.
  digitalWrite(ledPin, HIGH);
  delay(duty);

  // 나머지 시간에는 소등시킨다.
  digitalWrite(ledPin, LOW);
  delay(duty);

  // 시리얼 통신으로 ADC 값과 Duty를 출력한다.
  Serial.print("ADC Value is ");
  Serial.print(adcValue);
  Serial.print(". Duty cycle is ");
  Serial.print(duty);
  Serial.println("%");
}
