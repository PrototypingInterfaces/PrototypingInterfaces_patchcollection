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
StandaloneDemo

Turns on LED when button is pressed. 
*/

// global variables

// Button attached to pin 2
int ButtonPin = 2;
// LED attached to pin 13
int LEDPin =  13;
// current status of button
int ButtonState = 0;

void setup() 
{
  // initialize LEDPin as OUTPUT:
  pinMode(LEDPin, OUTPUT);      
  // initialize ButtonPin as INPUT:
  pinMode(ButtonPin, INPUT);     
}

void loop()
{
  // write value from ButtonPin into ButtonState
  ButtonState = digitalRead(ButtonPin);

  // if ButtonState is HIGH
  if (ButtonState == HIGH) 
  {     
    // LED = ON    
    digitalWrite(LEDPin, HIGH);  
  }
  // if ButtonState is LOW
  else 
  {
    // LED = OFF
    digitalWrite(LEDPin, LOW); 
  }
}
