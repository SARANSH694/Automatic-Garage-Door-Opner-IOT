#include<Servo.h>
Servo s;
void setup()
{
  Serial.begin(9600);
  pinMode(5, OUTPUT); // set arduino pin 5 to output mode
  pinMode(4, INPUT);  // set arduino pin 4 to input mode
  s.attach(2);       // attaches the servo on pin 2 to the servo object
  s.write(0);       // rotate servo motor to 0 degree
}

void loop()
{
  digitalWrite(5, HIGH);
  delayMicroseconds(10); // generate 10-microsecond pulse to TRIG pin
  digitalWrite(5, LOW);    

  float duration = pulseIn(4, HIGH);
  float distance = (duration*0.0343)/2;    // calculate the distance


  if(distance <150)
      s.write(90);    // rotate servo motor to 90 degree to open garage door
 
  delay(4000);		 // delay 4000 milliseconds 
  s.write(0);        // rotate servo motor to 0 degree to close garage door

  Serial.print("Distance in cm: ");
  Serial.println(distance);
}