# Bluetooth Control Vehicle

## Project Objective
* Develop a bluetooth controlled off-road vehicle control by android app.  
## Software used 
* C
* Arduino Bluetooth RC Car (Andriod app)
## Hardware used
* NU32 developboard 
  http://hades.mech.northwestern.edu/index.php/NU32:_Introduction_to_the_PIC32
  <img src="http://hades.mech.northwestern.edu/images/c/c6/NU32_Nov2015.jpg" width="500">
* H bridge DRV8835 (Two)
  https://www.robotshop.com/en/drv8835-dual-motor-driver-carrier.html
* LED (Four)
  https://en.wikipedia.org/wiki/Light-emitting_diode
* 1.5 voltage Battery (Four)
* 4WD Off Road Robot Smart Car Kit
  https://www.banggood.com
* HC-05 Arduino Wireless Bluetooth Receiver 
  https://www.amazon.com
## Milestones
### Stage1 
* Electrical skematic 

  <img src="https://github.com/szhan151/ME499/blob/master/source/schemetic.png" width="500">
### Stage2
* Assemble the develop board and vehicle 
  * Output PWM signal from Pin D0. And four motor control by the same PWM signal.
  * Pin B10 to B13 Control the direction of the motor.
  * The battery pack generate 6v input to NU32 VIN port, and NU32 output voltage 3.3v and 5v.
  * 3.3v power supply for the H bridge.
  * 5v power supply for the bluetooth.
  * Pin B1 to B4 control the four LED signal light.
### Stage3
* Write c code for motor control
  * Write direction function and PWM function in the motor control file. 
  * Set Pin B10 to B13 as input pins. When input 1, the motor rotate clockwise. When input 0, the motor rotate counter clockwise. 
  * When four motors input 1, the vehicle move forward. When four motors input 0, the vehicle move backward. When one side of the motors     input 1 and another side of motors input 0, the vehicle will rotate. 
### Stage4
* Write c code for bluetooth 
  * Initialize the bluetooth, and set baud rate to 9600. Configure TX & RX pins. Configure the UART interrupts.
  * Write command function for bluetooth. Use ASCII table, F as forward, B as backward, L as left turn, R as right turn.
### Stage5
* Write main code and interrupt
  * Initialize PWM and Bluetooth in the main function.
  * Put bluetooth command function in the interrupt.
  * Reset flag at the end of the interrupt. 
### Stage6 
* Write signal control and testing code
  * Add four more pins to control the signal LED. Under the if statement of the direction control, insert LED control command. 
### Stage7 
* Choose app for the HC-05 bluetooth
  * Reference from https://sites.google.com/site/bluetoothrccar/home/4PuttingItAllTogetherAndTheAndroidApplication
       <img src="https://github.com/szhan151/ME499/blob/master/source/control_panal.png" width="400">
## Result
### Picture of vehicle
   <img src="https://github.com/szhan151/ME499/blob/master/source/IMG_2404.JPG" width="300"><img src="https://github.com/szhan151/ME499/blob/master/source/IMG_2405.JPG" width="300">

### GIF of operation
![gif](https://github.com/szhan151/ME499/blob/master/source/demo.gif)

The demo video also in the source folder.
