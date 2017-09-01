///////////////////////////////////////////////
// This program counts and displays how long it has been running on the OD01 OLED
// Uses OD01, CW01, and IP01 chips
// Written by E. Bujold
//////////////////////////////////////////////

#include "xCore.h"  //This library makes the processor usable
#include "xOD01.h"  //This library makes the OLED screen usable

// Define variables and starting values
int count = 0;
int temp = 0;
int minute = 0;
int second = 0;
int hour = 0;

void setup() {  
// These first commands prepare the xSystem, by starting the chips
// This section will run only once

Wire.begin(2,14); // Starts the communication with the xSystem
OLED.begin();     // Turn on the OLED Display OD01

}

void loop() {
// This is where the body of the program is
// This section will repeat indefinitely

OD01.set1X();   // set display text to normal size

count++;                        //This is equalavlent to the total number of seconds the program has been running

hour = count / 3600;            // This calculates the number of hours in our counter.
                                // Integer math dictates that we will only get whole number answers
temp =  count - (hour * 3600);  // Subtract the number of seconds in an hour from the total number of seconds, saved in a temporary counter
                                // If the number of hours is zero, then temp will equal count
minute = temp / 60;             // The number of minutes in our temporary value.
second = temp - (minute * 60);  // Subract the number of seconds in minute
  
OD01.print(" H: "); OD01.print(hour);
OD01.print(" M: "); OD01.print(minute);
OD01.print(" S: "); OD01.println(second);

delay(1000);   // count one second before repeating from the top of void loop()
}
