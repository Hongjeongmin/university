//string 저장하는법~
//16진수로 바꿔서 출력하는방법

int pins[] = {2,3,4,5};
int state=16;
boolean process_it =false;
String buffer = "";

void setup() {
  Serial.begin(9600);

  for(int i=0;i<4;i++)
  {
    pinMode(pins[i],OUTPUT);
    digitalWrite(pins[i],LOW);  
  }
}

void loop() {
  while(Serial.available())
  {
    char data = Serial.read();
    if(data == '\n')
    {
      process_it=true;
      break;  
    }
    else
    {
      buffer +=data; 
    }
  }

  
  if(process_it)
  {
    Serial.println(String("You entered \'") + buffer + '\'');
    state= buffer.toInt();

    if(state<0 || state>15)
    {
      Serial.println("invalid print");
      state = 16;
    }
  }    

  for(int i=0;i<4;i++)
  {
    boolean on_off = state & (0x1 <<i);// 0111 입력 시프트후 111 시프트후 11 시프투후 1 시프트후 0 끝
    if(on_off)
    {
      Serial.print("0");
      digitalWrite(pins[i],HIGH);
    } 
    else
    {
      Serial.print("X");
      digitalWrite(pins[i],LOW);
    }
  }
  Serial.println();

  buffer="";
  process_it = false;
 }
