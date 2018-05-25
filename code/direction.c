#include "direction.h"
#include <xc.h>

void dir(int direction){

  switch (direction) {

    default:{
      LATBbits.LATB10 = 1;
      LATBbits.LATB11 = 1;
      LATBbits.LATB12 = 1;
      LATBbits.LATB13 = 1;
    }
    case 0://forward
    {
      LATBbits.LATB10 = 0;
      LATBbits.LATB11 = 1;
      LATBbits.LATB12 = 0;
      LATBbits.LATB13 = 1;
      //led green on
      break;
    }

    case 1://backford
    {
      LATBbits.LATB10 = 1;
      LATBbits.LATB11 = 0;
      LATBbits.LATB12 = 1;
      LATBbits.LATB13 = 0;
      //led red on
      break;
    }

    case 2://turn left
    {
      LATBbits.LATB10 = 0;
      LATBbits.LATB11 = 0;
      LATBbits.LATB12 = 0;
      LATBbits.LATB13 = 0;
      //led yellow1 on
      break;
    }

    case 3://turn right
    {
      LATBbits.LATB10 = 1;
      LATBbits.LATB11 = 1;
      LATBbits.LATB12 = 1;
      LATBbits.LATB13 = 1;
      //led yellow2 on
      break;
    }
  }
}

void pwmInit(){
      T3CONbits.TCKPS = 0;     // Timer3 prescaler N=1 (1:1)
      PR3 = 3999;              // period = (PR3+1) * N * 12.5 ns = 50 us, 20 kHz
      TMR3 = 0;                // initial TMR3 count is 0

      OC1CONbits.OCTSEL = 1;   // Use Timer3 for comparison

      OC1CONbits.OCM = 0b110;  // PWM mode without fault pin; other OC1CON bits are defaults
      OC1RS = 0;             // duty cycle = OC1RS/(PR3+1) = 50%
      OC1R = 2000;              // initialize before turning OC1 on; afterward it is read-only
      T3CONbits.ON = 1;         // turn the timer3 on
      OC1CONbits.ON = 1;       // turn on OC1
}
