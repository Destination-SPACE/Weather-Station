#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "SparkFunBME280.h"
Adafruit_SSD1306 display(128, 64, &Wire, -1);
BME280 BME;
File myFile;
void setup() {
  Serial.begin(57600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  //delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  Wire.begin();
  BME.setI2CAddress(0x76);
  if(BME.beginI2C() == false);
  if (!SD.begin(3)) while (1);
}
void loop() {
  delay(500);
  String dataString = "";
  myFile = SD.open("datalog.csv", FILE_WRITE);
  if(myFile){
    myFile.print(BME.readTempC(), 2);
    myFile.print(",");
    myFile.print(BME.readFloatPressure(), 0);
    myFile.print(",");
    myFile.println(BME.readFloatHumidity(), 2);
    myFile.close();    
  }  
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("DS Weather Station");
  display.setCursor(0, 20);
  display.print("Temperature: ");
  display.print(BME.readTempC(), 2);
  display.print(" C");
  display.setCursor(0, 30);
  display.print("Pressure: ");
  display.print(BME.readFloatPressure(), 0);
  display.print(" Pa");
  display.setCursor(0, 40);
  display.print("Humidity: ");
  display.print(BME.readFloatHumidity(), 2);
  display.print(" %");
  display.display();
}
