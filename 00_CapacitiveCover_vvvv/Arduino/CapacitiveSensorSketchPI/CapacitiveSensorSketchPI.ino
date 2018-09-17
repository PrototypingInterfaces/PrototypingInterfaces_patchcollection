#include <CapacitiveSensor.h>

/*
 * Prototyping Interfaces Capacitive Cover Patch.
 * Based on:
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 * Links:
 * http://playground.arduino.cc//Main/CapacitiveSensor?from=Main.CapSense
 * https://github.com/arduino-libraries/CapacitiveSensor
 */


CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
long maximum = 30000; // limit the maxmum Sensor Value to some realistic value.

void setup()                    
{
   Serial.begin(9600);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
 
    //Serial.print(millis() - start);        // check on performance in milliseconds

    Serial.print(total1);                  // print sensor output 1 unlimited.
    Serial.print(',');
    
    if (total1 > maximum)                  // limit output to a maximum value.
    {                                      // this makes sense as max values can be 
      total1 = maximum;                    // extreme big when sensor is touched directly. 
    }
    
    Serial.println(total1);                  // print sensor output 1 limited

    delay(10);                             // arbitrary delay to limit data to serial port 
}
