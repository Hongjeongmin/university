int pins[] = {2,3,4,5};
int pins2[] = {0,0,0,0};
int state = -1; 
void setup() {
  Serial.begin(9600);
  for(int i=0;i<4;i++)
  {
    pinMode(pins[i],OUTPUT);
    digitalWrite(pins[i],LOW);
  }
}
//1넣으면 불들어오고 1누르면 불꺼지고
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
      if(pins2[state] == 0)
      {
        digitalWrite(pins[state],HIGH);
        pins2[state]=1;
        Serial.println("1");
      }
      else
      {
        digitalWrite(pins[state],LOW);
        pins2[state]=0;
        Serial.println("2");
      } 
    }
  }
    Serial.println("끝");
}
