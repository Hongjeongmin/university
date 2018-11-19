const char trigPin = 13;
const char echoPin = 12;
const int RED = 2;
const int GREEN = 3;
const int BLUE = 4;

int pulseWidth;
int distance;
int distanceOld;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  digitalWrite(trigPin, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pulseWidth = pulseIn(echoPin, HIGH);
  distance = pulseWidth / 15;

  if(distance <= 200 || distance >= 2){
    if(distance >= 2 && distance <= 10) {
      // RED HIGH + 나머지 LOW
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, LOW);
    }
    else if(distance >= 11 && distance <= 20) {
      // GREEN HIGH + 나머지 LOW
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);
      digitalWrite(BLUE, LOW);
    }
    else if(distance >= 21) {
      // BLUE HIGH + 나머지 LOW
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, HIGH);
    }
    if(distance != distanceOld) {
      Serial.print(distance);
      Serial.println(" cm");
    };
  };
  distanceOld = distance;
  delay(100);
}
