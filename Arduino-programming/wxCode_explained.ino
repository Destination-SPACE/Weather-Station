////////////////////////////////////////////////////////////////////////////////////////////////
//Libraries:                                                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_SSD1306.h>
#include "SparkFunBME280.h"

////////////////////////////////////////////////////////////////////////////////////////////////
//Define Constant Values:                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

const int chipSelect = 3;

int delayTime = 1000; //time between data collection intervals
int timer = 0;

BME280 BME;  //Name the BME280 variable BME
File myFile; //Name the SD File variable myFile

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Define the OLED parameters using the constants above

////////////////////////////////////////////////////////////////////////////////////////////////
//Setup Loop:                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(57600); //Set the baud rate to 57600 bits per second for serial communication
  Wire.begin(); //Start the I2C bus
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display and define it's I2C address as 0x3C
  delay(2000);  //Delay the rest of the startup sequence by 2000ms
  display.clearDisplay(); //Clear the OLED display
  display.setTextColor(WHITE);  //Set the OLED text color as white
  BME.setI2CAddress(0x77);      //Set the BME280 I2C address to 0x76
  if(BME.beginI2C() == false);  //Start the BME280 I2C address
  if (!SD.begin(chipSelect)) while (1); //Set the Chip Select pin to the defined pin above. Do nothing if wired wrong
}

////////////////////////////////////////////////////////////////////////////////////////////////
//Main Loop:                                                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  delay(1000); //Delay the script by 1000ms
  String dataString = ""; //Set the data string to an empty string for data
  myFile = SD.open("datalog.csv", FILE_WRITE); //Open the datalog.csv file and write to it
  if(myFile){ //Write to the SD card
    myFile.print(timer);                        //Print Timer
    myFile.print(",");                          //Print a "," between each data point for CSV file
    myFile.print(BME.readTempC(), 2);           //Print temperature data to 2 decimal places
    myFile.print(",");                          //Print a "," between each data point for CSV file
    myFile.print(BME.readFloatPressure(), 0);   //Print pressure data to 0 decimal places
    myFile.print(",");                          //Print a "," between each data point for CSV file
    myFile.println(BME.readFloatHumidity(), 2); //Print humidity data to 2 decimal places
    myFile.close();  //Stop writing to the SD card
  }
  
  display.clearDisplay(); //Clear the OLED display
  
  display.setTextSize(1);                     //Set the text size to 1
  display.setCursor(0,0);                     //Set the cursor to coordinate (0,0)
  display.print("DS Weather Station");        //Print "DS Weather Station" on the OLED
  
  display.setCursor(0, 20);                   //Set the cursor to coordinate (0,20)
  display.print("Temperature: ");             //Print "Temperature: "
  display.print(BME.readTempC(), 2);          //Print the temperature data to 2 decimal places
  display.print(" C");                        //Print " C"
  
  display.setCursor(0, 30);                   //Set the cursor to coordinate (0,30)
  display.print("Pressure: ");                //Print "Pressure: "
  display.print(BME.readFloatPressure(), 0);  //Print pressure data to 0 decimal places
  display.print(" Pa");                       //Print " Pa"

  display.setCursor(0, 40);                   //Set the cursor to coordinate (0,40)
  display.print("Humidity: ");                //Print "Humidity: "
  display.print(BME.readFloatHumidity(), 2);  //Print humidity data to 2 decimal places
  display.print(" %");                        //Print " Pa"
 
  display.display(); //Display above on the OLED

  delay(delayTime);
  timer = timer + (delayTime)/1000;
}
