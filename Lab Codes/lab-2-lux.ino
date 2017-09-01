//////////////////////////////////////////////
// This code reads LUX and displays the data on the OLED
// Uses OD01, CW01, IP01, SL01 xChips
// Written by E. Bujold
/////////////////////////////////////////////

#include <xCore.h>  //This library makes the processor usable
#include <xSL01.h>  //This library makes the light sensor usable
#include <xOD01.h>  //This library makes the OLED screen usable

void setup() {
// These first commands prepare the xSystem, by starting the chips
// This section will run only once

Wire.begin(2,14); // Start the I2C Communication with xSystem
OLED.begin();     // Turn on the OLED display
SL01.begin();     // Start the  SL01 Sensor

OD01.set2X();     // Set the font size to large
  
OD01.println("===========");
OD01.println("XinaBox LUX");
OD01.println("==========="); 

delay(5000);    //delay before beginning loop function
}

void loop() {
// This is where the body of the program is
// This section will repeat indefinitely

OD01.clear();   // Clear the display
SL01.poll();    // Poll Sensor for collect data

OD01.println("Light Level: ");  
OD01.print(SL01.getLUX());      //Read information from sensor and print it
OD01.println(" LUX");

if (SL01.getLUX() < 150){       // If the lux level is less than 150
  OD01.println ("It's dark!");  // Then print this information
  }

delay(2000);                    // Two second delay before restarting the loop
}
