# Weather-Station
## What is the Destination Weather Station?
The Destination Weather Station is a Arduino based weather station that collects, displays, and stores tempreture, pressure, and humidity data. This weather station runs on a Seeeduino XIAO by Seeed Studio and uses a custom BME280 weather sensor module to collect data. This data is then saved on a MicroSD card so data can easily be ported to the users computer.

# Getting Started
Each kit comes with all the materials needed to get started with your Destination Weather Station. Provided in each kit are

### Insert image of kit in bag

1. Seeeduino XIAO
2. BME280 sensor
3. OLED display
4. MicroSD card module
5. AA battery case
6. Breadboard
7. MicroSD card
8. AA batteries
9. USB-C cable
10. MicroSD card adapter
11. Jumper wires

<p align="center"><img src="/assets/parts.png" alt="Kit parts" width="1000" align="center"></p>

## Section 1: Laying Out Components
Breadboards are a common tool used to prototype electronic circuits. They have several *busses* that are used to electrically connect sets of sockets together to allow the current in the circuit to be distributed across several sockets. Below is an image of how these busses are connected on a standard 30 row breadboard. Each socket in a breadboard has a unique name using the corresponding column (a-j) and row (1-30). For example hole **c1** is located in the third column and in the first row. This convention will be used going forward.

<p align="center"><img src="/assets/Breadboard_diagram.jpg" alt="Breadboard Diagram" width="500" align="center"></p>

Begin by grabbing your Seeeduino XIAO, BME280, OLED display, microSD card module, and breadboard. Orientate your breadboard with the the letters at the top as shown in the image below.

<p align="center"><img src="/assets/IMG_8180.jpg" alt="Breadboard" width="500" align="center"></p>

Start by taking your Seeeduino XIAO and orientating it where the USB-C connector is facing away from you. Insert the **top left** pin into hole **c1** on your breadboard and the **top right** pin into the **g1** hole. Your breadboard should look like the image below.

<p align="center"><img src="/assets/IMG_8187-2.jpg" alt="XIAO in breadboard" width="500" align="center"></p>

Next take your OLED display and orientate it to where the pins are facing **your right**. Insert the **GND** pin into hole **h12** and insert the **SDA** pin into hole **h15**. Your breadboard should look like the image below.

<p align="center"><img src="/assets/IMG_8188.jpg" alt="OLED in breadboard" width="500" align="center"></p>

Now take your BME280 sensor and irentate it to where the pins are facing **your left**. Insert the **GND** pin into hole **b20** and insert the **SCL** pin into hole **b23**. Your breadboard should look like the image below.

<p align="center"><img src="/assets/IMG_8189.jpg" alt="BME280 in breadboard" width="500" align="center"></p>

Finally take your microSD card module and orientate it to where the pins are facing **your right**. Using the image below of the pin layout insert the **GND** pin into hole **f25** and insert the **3v3** pin into hole **f30**. 

<p align="center"><img src="/assets/IMG_8191.jpg" alt="microSD module pinout" width="500" align="center"></p>

Your breadboard should look like the image below.

<p align="center"><img src="/assets/IMG_8190.jpg" alt="microSD module in breadboard" width="500" align="center"></p>

## Section 2: Wiring
Next we will be wiring together your weather station. Each wire will connect a pin on a component to a corresponding pin on the XIAO microcontroller. The XIAO microcontroller uses several protocols and interfaces, if you would like to learn more about the XIAO and it's protocols click [here](https://github.com/Destination-SPACE/Weather-Station/edit/main/XIAO). Below is a schematic of how the wires are connected in this project. Do not worry if this is confusing, the steps below are more than enough to wire your weather station.

<p align="center"><img src="/assets/schematic.png" alt="Schematic" width="500" align="center"></p>

### OLED Display
1. Connect a wire from hole **h2** (GND) to **i12** (GND)
2. Connect a wire from hole **h1** (5V) to **i13** (VCC)
3. Connect a wire from hole **b6** (SCL) to **i14** (SCL)
4. Connect a wire from hole **b5** (SDA) to **i15** (SDA)

Your breadboard should look like the image below.

<p align="center"><img src="/assets/IMG_8192.jpg" alt="OLED wired" width="500" align="center"></p>

### BME280 Sensor
1. Connect a wire from hole **i2** (GND) to **a20** (GND)
2. Connect a wire from hole **h3** (3V3) to **a21** (3V3)
3. Connect a wire from hole **a5** (SDA) to **a22** (SDA)
4. Connect a wire from hole **a6** (SCL) to **a23** (SDA)

* Please ensure all connections are correct. This sensor has minimal hardware on it and is suseptible to breaking easily if the power pins are connected to the microcontroller incorectly.

Your breadboard should look like the image below.

<p align="center"><img src="/assets/IMG_8193.jpg" alt="BME280 wired" width="500" align="center"></p>

### MicroSD Card Module
1. Connect a wire from hole **j2** (GND) to **g25** (GND)
2. Connect a wire from hole **h5** (MISO/SDI) to **g26** (MISO/SDI)
3. Connect a wire from hole **h6** (SCK/CLK) to **g27** (CLK)
4. Connect a wire from hole **h4** (MOSI/SDO) to **g28** (MOSI/SDO)
5. Connect a wire from hole **b4** (D3) to **g29** (CS)
6. Connect a wire from hole **i3** (3V3) to **g30** (3v3)

Your breadboard should look like the image below.

<p align="center"><img src="/assets/IMG_8194.jpg" alt="microSD module wired" width="500" align="center"></p>

Your weather station is now fully wired and ready to be programmed. In the next step we will upload code to your weather station

## Section 3: Programming
One of the benefits of using a XIAO as our microcontroller is that is supports a bootloader where you can drag and drop pre-compiled scripts onto it directly through your file manager like a flash drive! This makes getting started with the XIAO simple and can easily be done on Windows, Mac, and Chrome systems. In order to upload pre-compiled code to your XIAO you need to first put it in bootloader mode. 

### Entering Bootloader Mode
To enter bootloader mode begin by connecting your weather to your computer using your USB-C cable. Next you must short the reset pins twice in succession as shown in the GIF below. Only shorting the reset pins once will reset the XIAO, starting the code from the begining.

<p align="center"><img src="/assets/XIAO-reset.gif" alt="Entering Bootloader Mode" width="500" align="center"></p>

### Uploading Files to  the XIAO

Once your enter bootloader mode on your XIAO a window should open on your computer showing the file directory of your XIAO. To upload a script to your XIAO simply drag and drop a UF2 (USB Flashing Format) file into the XIAOs directory as shown in the GIF below. The flashdrive provided with your kits contains the UF2 file needed for this camp. Once the file is uploaded to your XIAO the window will close and the script will run on your weather station.

### Insert GIF of XIAO uploading

That is all that is needed to program your weather station. If you would like to change the code to a different UF2 file follow the steps above. More up to date files can be found [here](https://github.com/Destination-SPACE/Weather-Station/tree/main/code). Additionally if you would like to upload Arduino .ino files to your XIAO follow the instructions [here](https://github.com/Destination-SPACE/Weather-Station/tree/main/Arduino-programming).

## Section 4: Connecting Batteries
Next we will begin by inserting the microSD card into the microSD card module on your weather station. This is a nessisary step that must be completed **before** your weather station is connected to power.

### Inserting the MicroSD Card
To insert the microSD card begin by orientating it to where the contacts are facing down and away from you. Then insert the card into the slot. The microSD card will only go in about halfway. Once the card is inserted the batteries can be connected. See the image below.

<p align="center"><img src="/assets/IMG_8195.jpg" alt="micrSD card" width="500" align="center"></p>

### Connecting Battery Case

The battery case is used to power the weather station when it is not connected to your computer. Begin by inserting your batteries in the correct orientation shown below. To connect the batteries to your weather station take the 1.25mm JST connector on your weather station and insert it into the matching JST receptacle. It should only connect in one direction, see GIF below. Take care when handling the JST connectors as to not damage the connections to the battery case or the XIAO.

### Insert GIF of JST connection

Once your batteries are connected to your weather station you should notice that the OLED display lights up and begins displaying the data being collected. Your weather station should look like the image below.

<p align="center"><img src="/assets/IMG_8168.jpg" alt="weather station + batteries" width="500" align="center"></p>

You have now sucessfully assembled and programmed your weather station. Below you can find example experiments, an introduction to interpreting your data, and coding your own custom programs for your Destination Weather Station. 

[Experiments](https://github.com/Destination-SPACE/Weather-Station/tree/main/experiments)

[Data Analytics](https://github.com/Destination-SPACE/Weather-Station/tree/main/data-analytics)

[Arduino Programming](https://github.com/Destination-SPACE/Weather-Station/tree/main/Arduino-programming)

If you have any questions about what was covered above or in any other section of this repository, feel free to reach out to Austin Gleydura at austingleydura@pm.me
