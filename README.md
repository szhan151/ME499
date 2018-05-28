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
* 1.5 voltage Battery (Four)
* 4WD Off Road Robot Smart Car Kit
  https://www.banggood.com
* HC-05 Arduino Wireless Bluetooth Receiver 
  https://www.amazon.com
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
* Write c code for bluetooth 
  * Initialize the bluetooth, and set baud rate to 230400. Configure TX & RX pins. Configure the UART interrupts.
  * Write command function for bluetooth. Use ASCII table, W as forward, S as backward, A as left turn, D as right turn.
### Stage4
* Write main code and interrupt
  * Initialize PWM and Bluetooth in the main function.
  * Put bluetooth command function in the interrupt.
  * Reset flag at the end of the interrupt. 
### Stage5 
* Write signal control and testing code
  * Add four more pins to control the signal LED. W
## Result
