const int ledPin = 31; 
const float threshold = 80.0;
 
void setup() { 
  // put your setup code here, to run once: 
  Serial.begin(115200); 
  pinMode(ledPin, OUTPUT); 
} 
 
void loop() { 
  // put your main code here, to run repeatedly: 
  int sensorValue = analogRead(A3); 
  Serial.print("raw: ");
  Serial.println(sensorValue);
  float temp_C = ((3.3*sensorValue/1023.0))/0.01; 
  float temp_F = temp_C*(9.0/5.0)+32.0; 
  Serial.println(temp_F); 
  delay(1000);
  if(temp_F >= threshold){
    digitalWrite(ledPin,HIGH);  
  } else {
    digitalWrite(ledPin,LOW);
  }
} 
