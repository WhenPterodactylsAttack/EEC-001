void setup(){ 
  //Initialize serial communication to 115200 bits per second. 
  Serial.begin(115200); 
} 
 
void loop(){ 
  Serial.println("Hello, World!"); 
  delay(10000); //prints statement to monitor every 10s 
} 
