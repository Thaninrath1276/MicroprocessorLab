#include <SPI.h>
#define DATA_PIN 11
#define CLOCK_PIN 13
#define SS_PIN_1 10
#define SS_PIN_2 9
int iii;
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

void spi_write_1(unsigned char cData) {
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, cData);
  digitalWrite (SS_PIN_1, HIGH);
  digitalWrite (SS_PIN_1, LOW);
}
void spi_write_2(unsigned char cData) {
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, cData);
  digitalWrite (SS_PIN_2, HIGH);
  digitalWrite (SS_PIN_2, LOW);
}
void setup()
{
  pinMode(SS_PIN_1, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
}
void loop()
{
  
  if(iii>10)
  {iii=0;}
  for(iii = 0 ; iii < 10 ;iii++)
  {
   for(int ii = 0 ; ii < 10 ;ii++)
   {spi_write_1(map7seg[ii]);
    digitalWrite (CLOCK_PIN,HIGH);
    digitalWrite (CLOCK_PIN,LOW);
    spi_write_2(map7seg[iii]);
   digitalWrite (CLOCK_PIN,HIGH);
   digitalWrite (CLOCK_PIN,LOW);
    delay(1000);}
  }
}
