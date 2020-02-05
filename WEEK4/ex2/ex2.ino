int clk_pin = 13; //SHCP 
int latch_pin = 10;  //STCP 
int data_pin = 11;  //DS 
bool toggle; 
int map7seg[16] ={
  0x3F, //0
  0x06, //1
  0x5B, //2
  0x4F, //3
  0x66, //4
  0x6D, //5
  0x7D, //6
  0x07, //7
  0x7F, //8
  0x6F, //9
  0x77, //A
  0x7C, //B
  0x39, //C
  0x5E, //D
  0x79, //E
  0x71, //F
};
void setLed(uint8_t state)
{
  for(int i = 0 ; i < 8 ; i++) 
    {
      digitalWrite(data_pin,state>>7-i & 0x01); 
      digitalWrite(clk_pin,HIGH); 
      digitalWrite(clk_pin,LOW); 
   }
   digitalWrite(latch_pin,HIGH); 
   digitalWrite(latch_pin,LOW); 
   delay(1000);
}

void setup() { 
  Serial.begin(9600);
  while(!Serial)
  {}
  Serial.println("\n\nString toInt():");
  Serial.println();
  pinMode(clk_pin,OUTPUT); 
  pinMode(latch_pin,OUTPUT); 
  pinMode(data_pin,OUTPUT); 
} 
void loop()
{
  String inString;
  if (Serial.available()!=0)
  {
     while(Serial.available()>0)
     {
    int inChar = Serial.read();
    inString = (char)inChar;
    Serial.print("Value:");
    Serial.println(inString.toInt());
     }
  setLed(map7seg[inString.toInt()]);
  }
} 
