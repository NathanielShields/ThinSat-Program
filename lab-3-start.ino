//////////////////////////////////////////////
// This code reads Pressure and displays the data on the OLED
// Written by J. Singh
/////////////////////////////////////////////

#include <xCore.h>                //This library allows us to use the CW01 processor
#include <xOD01.h>                //This library allows us to use the OD01 screen
#include <xSW01.h>                //This library allows us to use the weather sensor
    
void setup() {
  // This setup code will prepare our xSystem for use. It will only run once.
 
  Wire.begin(2,14);               //Start I2C communication with the xSystem
  OLED.begin();                   //Turn on the OLED Screen
  SW01.begin();                   //Turn on the SW01 sensor

  OD01.set2X();
  OD01.println("===========");    
  OD01.println(" Pressure  ");    //print opening message on OLED Screen
  OD01.println("==========="); 

  delay(5000);                    //allow SW01 sensor to normalize before starting loop
}

void loop() {
  // This is the body of the code. It will repeat indefinitely.
 
  OD01.clear();                   //Clear the OLED display
  float pressure = 0;             //declare pressure variable and initialize as zero
  SW01.poll();                    //Tell the SW01 sensor to read and store data
  pressure = SW01.getPressure();  //set pressure variable equal to the current pressure reading
  OD01.println("Pressure is");
  OD01.print(pressure);           //display the pressure on the OLED screen
  OD01.println(" Pa");

  delay(2000);                    //pause for two seconds before displaying new reading
  
  
}
