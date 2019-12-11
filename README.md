# Strandbeest Arduino Robot
### Introduction
The original proposal was a robot based on the Strandbeest. The concept of this robot is to mimick the behavior of an insect, most similar to a cockroach. In order to accomplish this, various sensors were used; a light sensor and a infrared motion sensor reads values from the outside world to make the robot react accordingly. For instance, when a light source is shined on the robot, the robot should try to escape the light by turning around and running from it. Another example of sampling data the outside world is the infrared sensor. This acts as the robot’s eye which allows it to see and detect motion. The input from these sensors will determine the behavior of the output components. The ouput components for this robot are DC motors. To drive the motors, a motor controller is used to control the speed and direction. To power the motors, we use a Li-Po battery paired with a step down voltage regulator to supply the motors with appropriate voltage. The logic and compute power required to create the output from the input is an Arduino. In order to power this Arduino and everything else, the previously mentioned Li-Po battery is paired along with a step-up voltage regulator to provide the necessary voltage. In order to bridge the motors to the strandbeest model kit, I had to create a custom coupler using cad software and a 3d printer to materialize it.

### Schematics
<img src="/schematics.png"/>
### Power
<img src="/power.png"/>
### Parts List
1. Arduino Uno R3 
https://www.sparkfun.com/products/11021
2. SparkFun OpenPIR 
https://www.sparkfun.com/products/13968
3. Lithium Ion Battery 2AH
https://www.sparkfun.com/products/13855
4. SparkFun Adjustable LiPo Charger 
https://www.sparkfun.com/products/14380
5. SparkFun Motor Driver - Dual TB6612FNG 
https://www.sparkfun.com/products/14450
6. Double Gearbox (Left/Right Independent 4-Speed)
https://www.tamiya.com/english/products/70168double_gearbox/index.htm
7. Step-up DC Converter
https://www.ebay.com/itm/Mini-Step-up-Converter-DC-DC-3V-3-7V-5V-6V-to-12V-Boost-Voltage-Module-Regulator/112855472220?ssPageName=STRK%3AMEBIDX%3AIT&_trksid=p2057872.m2749.l2649
8. Photo Diode
https://www.amazon.com/HiLetgo-Phototransistor-Photosensitive-Sensitive-Sensors/dp/B00M1PMHO4/ref=sr_1_6?crid=3PHQZYJYC4TTM&keywords=photo+transistors&qid=1575409680&sprefix=photo+transis%2Caps%2C154&sr=8-6
9. eBoot 6 Pack LM2596 DC to DC Buck Converter
https://www.amazon.com/LM2596-Converter-3-0-40V-1-5-35V-Supply/dp/B01GJ0SC2C/ref=sr_1_4?crid=14K1S7FMEFKGS&keywords=step+down+regulator&qid=1575409793&sprefix=step+down+reg%2Caps%2C149&sr=8-4
10. Adafruit Perma Proto Board
https://www.adafruit.com/product/571
11. Mini Strandbeest Model Kit
https://www.amazon.com/HEYZLASS-Strandbeest-Interesting-Creative-Birthday/dp/B0756BD1B7/ref=sr_1_4?keywords=strandbeest+model+kit&qid=1575410157&sr=8-4

### Citations
1. Motor Driver Library 
https://github.com/sparkfun/SparkFun_TB6612FNG_Arduino_Library

