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

### Insert image of kit layed out

## Step 1: Laying Out Components
Breadboards are a common tool used to prototype electronic circuits. They have several *busses* that are used to electrically connect sets of sockets together to allow the current in the circuit to be distributed across several sockets. Below is an image of how these busses are connected on a standard 30 row breadboard. Each socket in a breadboard has a unique name using the corresponding column (a-j) and row (1-30). For example hole **c1** is located in the third column and in the first row. This convention will be used going forward.

### Insert image of breadboard diagram


Begin by grabbing your Seeeduino XIAO, BME280, OLED display, microSD card module, and breadboard. Orientate your breadboard with the the letters at the top as shown in the image below.

### Insert image of breadboard

Start by taking your Seeeduino XIAO and orientating it where the USB-C connector is facing away from you. Insert the **top left** pin into hole **c1** on your breadboard and the **top right** pin into the **g1** hole. Your breadboard should look like the image below.

### Insert image of XIAO in breadboard

Next take your OLED display and orientate it to where the pins are facing **your right**. Insert the **GND** pin into hole **h12** and insert the **SDA** pin into hole **h15**. Your breadboard should look like the image below.

### Insert image of OLED in breadboard

Now take your BME280 sensor and irentate it to where the pins are facing **your left**. Insert the **GND** pin into hole **b20** and insert the **SCL** pin into hole **b23**. Your breadboard should look like the image below.

### Insert image of BME280 in breadboard

Finally take your microSD card module and orientate it to where the pins are facing **your right**. Using the image below of the pin layout insert the **GND** pin into hole **f25** and insert the **3v3** pin into hole **f30**. 

### Insert image of microSD card module upsidedown

Your breadboard should look like the image below.

### Insert image of microSD module in breadboard

## Step 2: Wiring
Next we will be wiring together your weather station. Each wire will connect a pin on a component to a corresponding pin on the XIAO microcontroller. The XIAO microcontroller uses several protocols and interfaces, if you would like to learn more about the XIAO and it's protocols **Click here**. 
### OLED Display
1. Connect a wire from hole **h2** (GND) to **i12** (GND)
2. Connect a wire from hole **h1** (5V) to **i13** (VCC)
3. Connect a wire from hole **b6** (SCL) to **i14** (SCL)
4. Connect a wire from hole **b5** (SDA) to **i15** (SDA)

Your breadboard should look like the image below.

### Insert image of OLED wired

### BME280 Sensor
1. Connect a wire from hole **i2** (GND) to **a20** (GND)
2. Connect a wire from hole **h3** (3V3) to **a21** (3V3)
3. Connect a wire from hole **a5** (SDA) to **a22** (SDA)
4. Connect a wire from hole **a6** (SCL) to **a23** (SDA)

Your breadboard should look like the image below.

### Insert image of BME280 wired

### MicroSD Card Module
1. Connect a wire from hole **j2** (GND) to **g25** (GND)
2. Connect a wire from hole **h5** (MISO/SDI) to **g26** (MISO/SDI)
3. Connect a wire from hole **h6** (SCK/CLK) to **g27** (CLK)
4. Connect a wire from hole **h4** (MOSI/SDO) to **g28** (MOSI/SDO)
5. Connect a wire from hole **b4** (D3) to **g29** (CS)
6. Connect a wire from hole **i3** (3V3) to **g30** (3v3)

Your breadboard should look like the image below.

### Insert image of microSD wired

Your weather station is now fully wired and ready to be programmed. In the next step we will upload code to your weather station

## Step 3: Programming
One of the benefits of using a XIAO as our microcontroller is that is supports a bootloader where you can drag and drop pre-compiled scripts onto it directly through your file manager like a flash drive! This makes getting started with the XIAO simple and can easily be done on Windows, Mac, and Chrome systems. In order to upload pre-compiled code to your XIAO you need to first put it in bootloader mode you must short the reset pins twice in succession as shown in the GIF below. Shorting the reset pins once will reset the XIAO, starting the code from the begining.

### Insert GIF of XIAO bootloader


