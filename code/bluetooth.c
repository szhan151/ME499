#include "bluetooth.h"
#include <xc.h>
#include "NU32.h"
#include "direction.h"

void btInit(void){
  // set baud to 230400, to match terminal emulator; use default 8N1 of UART
  U1MODEbits.BRGH = 0;
  U1BRG = 520;

  // configure TX & RX pins
  U1STAbits.UTXEN = 1;
  U1STAbits.URXEN = 1;


  // configure the UART interrupts
  U1STAbits.URXISEL = 0x0; // RX interrupt when receive buffer not empty
  IFS0bits.U1RXIF = 0;  //  y=hh the rx interrupt flag.  for
                           // tx or error interrupts you would also need to clear
                           // the respective flags
  IPC6bits.U1IP = 1;       // interrupt priority
  IEC0bits.U1RXIE = 1;     // enable the RX interrupt

  // turn on UART1
  U1MODEbits.ON = 1;

}

void cmd(void){

  static int v = 50;
  unsigned char data = 0;
  if(U1STAbits.URXDA) { // poll to see if there is data to read in RX FIFO
      data = U1RXREG;
    //  NU32_LED1 = 0;
      if(data == '2'){
        dir(0);
        OC1RS = 4000;
      }else if(data == '4'){
        dir(2);
      }else if (data == '8') {
        dir(1);
      }else if(data == '6'){
        dir(3);
      }else{
        OC1RS = 0;
      }
  }
}
