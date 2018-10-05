int pins[] = {2,3,4,5};
int state = -1; 
void setup() {
  Serial.begin(9600);
  for(int i=0;i<4;i++)
  {
    pinMode(pins[i],OUTPUT);
    digitalWrite(pins[i],LOW);
  }
}

void loop() {
  if(Serial.available())
  {
    char data = Serial.read(); //scanf임
    Serial.println(String("You entered \'") + data +'\''); 

    if(data >= '1' && data <='4')//char 아스키코드로 해석해서 인트로받는 존나귀찮은 짓
    {
      state = data - '0' -1;  //1들어면 state 0이 저장이 된다.
      Serial.print("LED");
      Serial.print(state+1);
      Serial.println("** Invalid LED number ...");
    }

    for(int i=0;i<4;i++)
    {
      if(i==state)
      {
        Serial.print(i);
        digitalWrite(pins[i],HIGH);
        
      }
      else
      {
        Serial.print("X");
        digitalWrite(pins[i],LOW);  
      } 
    }
    delay(1000);
  }
  Serial.println("끝");
}
