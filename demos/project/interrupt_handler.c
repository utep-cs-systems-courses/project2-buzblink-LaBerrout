#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"

/* Switch on P1 (S2). LB: Change everything to P2 for the red board*/
void
__interrupt_vec(PORT2_VECTOR) Port_1(){
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	      /* single handler for all switches */
  }
}

