/*
PROTOTYPING INTERFACES
INTERACTIVE SKETCHING WITH VVVV

ISBN: 9783874398435
First Edition,Verlag Hermann Schmidt Mainz, 2013
http://www.prototypinginterfaces.com

COPYRIGHT 2013
Jan Barth
Roman Grasy
Jochen Leinberger
Mark Lukas
Markus Lorenz Schilling

LICENSED UNDER
Apache License, Version 2.0 http://www.apache.org/licenses/LICENSE-2.0
*/

/*
Interface Demo

Rotary Potentiometer sends values to VVVV using the Serial Port
*/

int SensorPin = A0;
int SensorValue = 0;
// delay time for the main loop in milliseconds (1000 ms = 1 sec)
int Delaytime = 10;

void setup() 
{
  // use the serial port to send/receive values to/from the computer
  Serial.begin(9600);
}

void loop() 
{
  // read potentiometer and save value in SensorValue
  SensorValue = analogRead(SensorPin);
  // send value to Serial Port
  Serial.println(SensorValue);
  // wait for 10ms
  delay(Delaytime);
}
