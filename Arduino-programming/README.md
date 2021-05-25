# Programming the Seeeduino XIAO in Arduino IDE
In addition to being able to read UF2 files the Seeeduino XIAO can also be programmed in the Arduino IDE. There are a few nessisary steps that will be covered. The first step is to download Arduino IDE.

## Section 1: Downloading Arduino IDE
Navigate to the page below that corresponds to the system you are using to download Arduino IDE.

[Windows](https://github.com/Destination-SPACE/Weather-Station/tree/main/Arduino-programming/Windows)

[MacOS](https://github.com/Destination-SPACE/Weather-Station/tree/main/Arduino-programming/MacOS)

Once you have sucessfully installed Arduino IDE follow the instructions below.

## Section 2: Installing Seeeduino board manager
To program the XIAO you will need to download the Seeeduino board manager so IDE can communicate with the XIAO.
- In Arduino IDE go to **File > Preferences**. This will open the Preferences window.
- In the Preferences window go down to the **Additional Boards Manager URLs:** text box. Copy and paste the following URL and click the **OK** button.

Seeeduino Board Manager URL: https://files.seeedstudio.com/arduino/package_seeeduino_boards_index.json

<p align="center"><img src="/assets/boardManagers.PNG" alt="Arduino IDE Board Managers" align="center"></p>

- Wait for everything to finalize

## Section 3: Installing Code Libraries
To get the weather station working you will need to install code libraries to work with the BME280 sensor and the OLED display. Follow the instructions below.
- In Arduino IDE navigate to **Tools > Manage Libraries...**. This will open the Library Manager window.

<p align="center"><img src="/assets/libraryManager.PNG" alt="Arduino IDE Board Managers" align="center"></p>

- In the search box at the top enter Adafruit_SSD1306 spelled exactly this way.
- Click Install

### Insert image of installing Adafruit_SSD1306

- In the search box at the top enter **SparkFun BME280** spelled exactly this way including the space.
- Click Install

### Insert image of installing SparkFun BME280

## Section 4: Uploading Code
To upload code to your weather station follow the instructions below. You can modify the code if you would like before uploading.
- Plug your weather station into your computer with the USB-C cable.
- Open the [wxCodeExplained.ino](https://github.com/Destination-SPACE/Weather-Station/blob/main/Arduino-programming/wxCode_explained.ino) file in IDE.
- Click Tools and make sure your settings are similar to the ones shown below. Your COM Port may be different. Make sure the one that has **(Seeeduino XIAO)** is selected.

<p align="center"><img src="/assets/tools.PNG" alt="Arduino IDE Tools" align="center"></p>

- Click the tiel arrow near the top left to upload your code
- Wait for the code to compile and upload. This will open your file manager and close it.
- Once your OLED display is reading weather data you can unplug your weather station.
