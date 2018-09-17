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
3_3_HelloWorld

"Hello World" of the Physical Computing. 
Turns LED repeatedly ON and OFF
*/

void setup() 
{
  // initialize LED pin 13 as output:
  pinMode(13, OUTPUT);           
}

void loop()
{
  // turn LED ON
  digitalWrite(13, HIGH);
  // wait one second
  delay(1000);
  // turn LED OFF
  digitalWrite(13, LOW);
  // wait one second
  delay(1000);
}
