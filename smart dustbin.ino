#include <Servo.h>

const int trigPin = 12;
const int echoPin = 14;
long duration;
int distance;
 
Servo myServo;
void setup() {
  // put your setup code here, to run once:
myServo.attach(13);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
distance = calculateDistance();

  
myServo.write(0);
if ( distance < 5)
{ myServo.attach(13);
myServo.write(160);
delay(500);
myServo.write(0);
delay(1000);

}
else{
  myServo.detach();
}
Serial.println(distance);
}
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
