//My first program 
 
int RLED = 75; // pin for RED LED
int BLED = 77; // pin for BLUE LED
int YLED = 78; // pin for YELLOW LED
int GLED = 76; // pin for GREEN LED

 
void setup() { 
  // put your setup code here, to run once: 
  pinMode(RLED, OUTPUT); //variable LED (or pin 75 is set as an output) 
  pinMode(BLED, OUTPUT);
  pinMode(YLED, OUTPUT);
  pinMode(GLED, OUTPUT);
} 
 
void loop() { 
  //make it blink! 
  digitalWrite(RLED, HIGH); //Turn the LED on 
  delay(1000); //wait 1000ms 
  digitalWrite(RLED, LOW); //Turn the LED off 
  delay(1000); //wait 1000ms
  digitalWrite(BLED, HIGH); //Turn the LED on 
  delay(1000); //wait 1000ms 
  digitalWrite(BLED, LOW); //Turn the LED off 
  delay(1000); //wait 1000ms 
  digitalWrite(YLED, HIGH); //Turn the LED on 
  delay(1000); //wait 1000ms 
  digitalWrite(YLED, LOW); //Turn the LED off 
  delay(1000); //wait 1000ms
   digitalWrite(GLED, HIGH); //Turn the LED on 
  delay(1000); //wait 1000ms 
  digitalWrite(GLED, LOW); //Turn the LED off 
  delay(1000); //wait 1000ms  
  /*loop tells the program to begin at the beginning of this section and 
repeat 
   * the process continuously. 
  */ 
   
} 
