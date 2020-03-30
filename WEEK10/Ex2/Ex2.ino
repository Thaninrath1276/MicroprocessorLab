int a = 0;  
   
void setup()  
{    
    pinMode(2, INPUT_PULLUP);    
    Serial.begin(9600);    
    Serial.println("Test Encoder"); 
    attachInterrupt(digitalPinToInterrupt(2), 
                   alpha, RISING); 
}  
void loop() 
{ 
  Serial.println(a); 
  delay(500); 
} 
 
void alpha()  
{    
  a++; 
} 
