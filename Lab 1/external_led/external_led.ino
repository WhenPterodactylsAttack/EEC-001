int ext_LED = 10; //digital write pin 
void setup() { 
  // put your setup code here, to run once: 
  pinMode(ext_LED, OUTPUT);  
} 
 
void loop() { 
  // put your main code here, to run repeatedly: 
  digitalWrite(ext_LED, HIGH); 
  delay(1000); 
  digitalWrite(ext_LED, LOW); 
  delay(1000); 
} 
