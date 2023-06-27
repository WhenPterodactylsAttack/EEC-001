//Exercise 5: LED brightness control with analogWrite() and For loops 
int ext_LED = 4; //analog output pin 
int val; 
 
void setup() { 
  pinMode(ext_LED, OUTPUT); 
} 
 
void loop() { 
  for (val=255; val>0;val--) 
  { 
    analogWrite(ext_LED,val); 
    delay(10); 
  } 
  for (val=0; val<255; val++) 
  { 
    analogWrite(ext_LED,val); 
    delay(10); 
  } 
} 
