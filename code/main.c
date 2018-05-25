#include "NU32.h"              // constants, functions for startup and UART
#include "direction.h"

void btInit(void){
  // set baud to 9600, to match terminal emulator; use default 8N1 of UART
  U1MODEbits.BRGH = 0;
  U1BRG = 520;

  // configure TX & RX pins
  U1STAbits.UTXEN = 1;
  U1STAbits.URXEN = 1;


  // configure the UART interrupts
  U1STAbits.URXISEL = 0x0; // RX interrupt when receive buffer not empty
  IFS0bits.U1RXIF = 0;     // clear the rx interrupt flag.  for
                           // tx or error interrupts you would also need to clear
                           // the respective flags
  IPC6bits.U1IP = 1;       // interrupt priority
  IEC0bits.U1RXIE = 1;     // enable the RX interrupt

  // turn on UART1
  U1MODEbits.ON = 1;

}

void pwmInit(){

      OC1CONbits.OCM = 0b110;  // PWM mode without fault pin; other OC1CON bits are defaults
      OC1CONbits.OCTSEL = 1;   // Use Timer3 for comparison
      OC1RS = 0;             // duty cycle = OC1RS/(PR3+1) = 50%
      OC1R = 2000;              // initialize before turning OC1 on; afterward it is read-only
      OC1CONbits.ON = 1;       // turn on OC1

      T3CONbits.TCKPS = 0;     // Timer3 prescaler N=1 (1:1)
      PR3 = 3999;              // period = (PR3+1) * N * 12.5 ns = 50 us, 20 kHz
      TMR3 = 0;                // initial TMR3 count is 0
      T3CONbits.ON = 1;        // turn on Timer3  55555

}

void cmd(void){
  unsigned char data = 0;
  if(U1STAbits.URXDA) { // poll to see if there is data to read in RX FIFO
      data = U1RXREG;
     NU32_LED1 = 0;

      if(data = 'w'){
        dir(0);
        OC1RS = 2000;
      }else if(data = 'a'){
        dir(2);
        OC1RS = 4000;
      }else if (data = 's') {
        dir(1);
        OC1RS = 4000;
      }else if(data = 'd'){
        dir(3);
        OC1RS = 4000;
      }else{
        OC1RS = 0;
        }

  }
}



void __ISR(_UART_1_VECTOR, IPL1SOFT) IntUart1Handler(void) {
    TRISBbits.TRISB0 = 0;
    LATBbits.LATB0 = 1;
    LATBbits.LATB1 = 0;
    LATBbits.LATB2 = 0;
    LATBbits.LATB3 = 0;
    LATBbits.LATB4 = 0;

  unsigned char data = 0;
 if(U1STAbits.URXDA) { // poll to see if there is data to read in RX FIFO
      data = U1RXREG;

      if(data == 'w'){
        dir(0);
        OC1RS = 4000;
        LATBbits.LATB1 = 1;
      }else if(data == 'd'){
        dir(2);
        LATBbits.LATB2 = 1;
        OC1RS = 4000;
      }else if (data == 's') {
        dir(1);
        LATBbits.LATB4 = 1;
        OC1RS = 4000;
      }else if(data == 'a'){
        dir(3);
        LATBbits.LATB3 = 1;
        OC1RS = 4000;
      }else if(data == 'q'){
        OC1RS = 0;

      }
    }
  //  cmd();

    IFS0bits.U1RXIF = 0;

}

int main(void) {
  NU32_Startup();   // cache on, interrupts on, LED/button init, UART init
  __builtin_disable_interrupts();
  OC1CONbits.OCM = 0b110;  // PWM mode without fault pin; other OC1CON bits are defaults
  OC1CONbits.OCTSEL = 1;   // Use Timer3 for comparison
  OC1RS = 0;             // duty cycle = OC1RS/(PR3+1) = 50%
  OC1R = 0;              // initialize before turning OC1 on; afterward it is read-only
  OC1CONbits.ON = 1;       // turn on OC1

  T3CONbits.TCKPS = 0;     // Timer3 prescaler N=1 (1:1)
  PR3 = 3999;              // period = (PR3+1) * N * 12.5 ns = 50 us, 20 kHz
  TMR3 = 0;                // initial TMR3 count is 0
  T3CONbits.ON = 1;        // turn on Timer3

// motor direction control bits
// pin 10 to 13
  TRISBbits.TRISB10 = 0;
  TRISBbits.TRISB11 = 0;
  TRISBbits.TRISB12 = 0;
  TRISBbits.TRISB13 = 0;
// pin B1 to B4 SIGNAL LIGHTS
  TRISBbits.TRISB1 = 0;
  TRISBbits.TRISB2 = 0;
  TRISBbits.TRISB3 = 0;
  TRISBbits.TRISB4 = 0;
//  pwmInit();
  //btInit();
  U1MODEbits.BRGH = 0;
  U1BRG = 520;

  // configure TX & RX pins
  U1STAbits.UTXEN = 1;
  U1STAbits.URXEN = 1;


  // configure the UART interrupts
  U1STAbits.URXISEL = 0x0; // RX interrupt when receive buffer not empty
  IFS0bits.U1RXIF = 0;     // clear the rx interrupt flag.  for
                           // tx or error interrupts you would also need to clear
                           // the respective flags
  IPC6bits.U1IP = 1;       // interrupt priority
  IEC0bits.U1RXIE = 1;     // enable the RX interrupt

  // turn on UART1
  U1MODEbits.ON = 1;
  __builtin_enable_interrupts();


  return 0;
}
