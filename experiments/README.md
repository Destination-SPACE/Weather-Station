# Experiments
Here you can find several experiments you can do with your weather station. Each tests a different component of your weather station. The final experiment combines all three components of your weather station that you can use for a data analytics exercise.

## Experiment 1: Tempreture
1. Take your weather station with the batteries connected, place in your refrigerator along with a cooking thermometer if you have one and close the door.
2. Start a stopwatch or keep track of the time for five minutes for you weather station to cool down.
3. After the five minutes has past open your refrigerator door and look at the display on your weather station. Does the tempreture match the tempreture on your cooking thermometer? Does this temperature make sense? Write your answers down.

Preform the same experiment following steps 1-3 above but in your freezer, and outside (if possible). 

## Experiment 2: Pressure
1. Take your weather station with the batteries connected and place it somewhere that has little air circulation, such as a closet.
2. Wait 30 seconds for the pressure and tempreture values to stabalize and then record them.
3. rearranging the formula below, calculate the approximate altitude (in meters) of your current location.

  ### P = P<sub>0</sub>⋅e<sup>-Mgh⋅(RT)<sup>-1</sup></sup>
  
  - P: Measured Pressure (Pa)
  
  - P<sub>0</sub>: Sealevel Pressure (101325.01 Pa)
  
  - M: Molar Mass of Air (~0.0289647 kg⋅mol<sup>-1</sup>)

  - g: Gravity of earth (~9.81 m⋅s<sup>-2</sup>)

  - h: height Above Sealevel (m)

  - R: Gas Constant (8.314462 J⋅K<sup>-1</sup>⋅mol<sup>-1></sup>)

  - T: Tempertature (K)
  
  After solving for h you get the equation
  ### h = ln(P⋅P<sub>0</sub><sup>-1</sup>)⋅RT⋅(Mg)<sup>-1</sup>

4. Now enter your address into [this website](https://www.advancedconverter.com/map-tools/find-elevation-of-address) to get the actual elevation of your current location
5. Does your calculated elevation roughly equal your actual elevation? Record your thoughts on why or why not.
  
## Experiment 3: Humidity (optional)
1. Take your weather station with the batteries connected and put it in your bathroom while showering. This is a good way of increasing the ambient air humidity without wasting water.
2. Record your results
3. Preform the same steps as above, but use a hair dryer on the low setting. By using a hairdryer you drive off moisture and increase tempreture.
  
## Experiment 4: Putting it all Together
1. Upload the **overnightDataCollection.UF2** file to your weather station using the steps outlined **here**. This changes your weather station from collecting data every 3 seconds to every minute. 
2. Take your weather station with the batteries connected and put it outside overnight if possible in an area where it is unlikely to be blown away or rained on. A good option is a covered porch or under a bucket or plastic container, make sure that air is allowed to freely circulate around the weather station.
2. Use the data stored on your microSD card to review your results and preform data analytics.
