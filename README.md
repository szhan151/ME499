# Bluetooth control vehicle

## Project Objective
* Develop a bluetooth controlled off-road vehicle control by android app.  
## Software used 
* C
## Hardware used
* NU32 developboard 
  http://hades.mech.northwestern.edu/index.php/NU32:_Introduction_to_the_PIC32
* H bridge DRV8835 (Two)
  https://www.robotshop.com/en/drv8835-dual-motor-driver-carrier.html
* LED (Four)
  https://en.wikipedia.org/wiki/Light-emitting_diode
* 1.5 voltage Battery case (Four)
* 4WD Off Road Robot Smart Car Kit
  https://www.banggood.com/4WD-WIFI-Crosscountry-Offroad-Robot-Smart-Car-Kit-For-Arduino-p-927973.html?gmcCountry=US&amp;currency=USD&amp;createTmp=1&amp;utm_source=googleshopping&amp;utm_medium=cpc_elc&amp;utm_content=zouzou&amp;utm_campaign=pla-us-ele-prof-1-pc&amp;gclid=EAIaIQobChMIxJe2_tqe2gIVgyWBCh2XiwJxEAkYBiABEgJ67PD_BwE&amp;cur_warehouse=CN&stayold=1&cur_warehouse=CN
* HC-05 Arduino Wireless Bluetooth Receiver 
  https://www.amazon.com/dp/B01MQKX7VP/ref=asc_df_B01MQKX7VP5427675/?tag=hyprod-20&amp&creative=395033&amp&creativeASIN=B01MQKX7VP&amp&linkCode=df0&amp&hvadid=167146065113&amp&hvpos=1o1&amp&hvnetw=g&amp&hvrand=15607880664640992515&amp&hvpone=&amp&hvptwo=&amp&hvqmt=&amp&hvdev=c&amp&hvdvcmdl=&amp&hvlocint=&amp&hvlocphy=9021567&amp&hvtargid=pla-362748457327
## Milestones
### Stage1
* Assemble the develop board and vehicle 
  * Output PWM signal from Pin D0. And four motor control by the same PWM signal.
  * Pin B10 to B13 Control the direction of the motor.
  * The battery pack generate 6v input to NU32 VIN port, and NU32 output voltage 3.3v and 5v.
  * 3.3v power supply for the H bridge.
  * 5v power supply for the bluetooth.
  * Pin B1 to B4 control the four LED signal light.
### Stage2
* Write c code for motor control
  * Write direction function and PWM function in the motor control file. 
  * Set Pin B10 to B13 as input pins. When input 1, the motor rotate clockwise. When input 0, the motor rotate counter clockwise. 
  * When four motors input 1, the vehicle move forward. When four motors input 0, the vehicle move backward. When one side of the motors     input 1 and another side of motors input 0, the vehicle will rotate. 
### Stage3
* Write c code for bluetooth initialize
### Stage4
* Write main code and interrupt 
### Stage5 
* Write signal control and testing code

## Result
