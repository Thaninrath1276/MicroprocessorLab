int clk_pin = 13; //SHCP
int latch_pin = 10; //STCP
int data_pin = 11; //DS
bool toggle;
int data;
int count = 0;
int map7seg[16] = {
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

void setup(){
  pinMode(clk_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
}  

void loop()
{
  for(int ii = 0 ; ii< 16; ii++)
  {
  for(int i = 0; i < 8 ; i++)
  {
    digitalWrite(data_pin,map7seg[ii]>>7-i & 0x01);
    digitalWrite(clk_pin,HIGH);
    digitalWrite(clk_pin,LOW);
    
  }
  digitalWrite(latch_pin,HIGH);
  delay(1000);
  digitalWrite(latch_pin,LOW);
  }
}
