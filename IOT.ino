const int trigpin = 6; 
const int echopin = 9; 
int distance; 
int duration; 
const int pump =13; 
void setup() 
{ 
 pinMode(trigpin, OUTPUT); 
 pinMode(echopin, INPUT); 
 Serial.begin(9600); 
 pinMode(pump, OUTPUT); 
 digitalWrite(pump, LOW); 
} 
void loop() 
{ 
 digitalWrite(trigpin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigpin, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trigpin, LOW);  
duration=pulseIn(echopin, HIGH); 
 distance=(0.034*duration)/2; 
 Serial.print("Distance is = "); 
 Serial.println(distance); 
 delay(1000); 
 if(distance >= 4 && distance <=15) 
 { 
 Serial.println("POURING SANITIZER"); 
 digitalWrite(pump, HIGH); 
 delayMicroseconds(20); 
 } 
 else{ 
 Serial.println("HAND NOT SENSED"); 
 digitalWrite(pump, LOW); 
 delay(1000); 
 } 
 delayMicroseconds(200); 
} 
