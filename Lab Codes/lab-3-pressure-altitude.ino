//////////////////////////////////////////////
// This code displays Pressure and Altitude
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
  OD01.println("  Weather  ");    //Print opening message on OLED Screen
  OD01.println("===========");

  delay(5000);                    //Allow SW01 sensor to normalize before starting loop
}

void loop() {
// This is the body of the code. It will repeat indefinitely.
  OD01.clear();             //Clear display
  OD01.set2X();             //Set font size
  OD01.println("Weather");  //Display 'Weather' title

//Display Pressure
  OD01.set1X();                        //Set font size
  SW01.poll();                         //Tell the SW01 sensor to read and store data
  OD01.println("Pressure:");
  OD01.print(SW01.getPressure()/100);  //Display the pressure on the OLED screen
  OD01.println(" hPa");
  OD01.println();
  
//Display Altitude
  OD01.println("Altitude:");
  OD01.print(SW01.getAltitude()); //Display the altitude on the OLED screen
  OD01.println(" m above the sea");

  delay(5000);                    //Pause for five seconds

}
