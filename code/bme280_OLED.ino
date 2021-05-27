#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "SparkFunBME280.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

BME280 mySensorB;

void setup() {
  Serial.begin(57600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  Wire.begin();
  mySensorB.setI2CAddress(0x76);
  if(mySensorB.beginI2C() == false) Serial.println("Sensor Failed to Connect, Check Wiring");
}

void loop() {
  delay(500);
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("DS Weather Station");
  
  display.setCursor(0, 20);
  display.print("Temperature: ");
  display.print(mySensorB.readTempC(), 2);
  display.print(" C");
  
  display.setCursor(0, 30);
  display.print("Pressure: ");
  display.print(mySensorB.readFloatPressure(), 0);
  display.print(" Pa");

  display.setCursor(0, 40);
  display.print("Humidity: ");
  display.print(mySensorB.readFloatHumidity(), 2);
  display.print(" %");
 
  display.display(); 
}
