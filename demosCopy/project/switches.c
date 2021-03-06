#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char switch_state_down, switch_state_changed; /* effectively boolean */
int switch_ID;
char last_state = 0;

static char 
switch_update_interrupt_sense()
{
  //char p1val = P1IN;
  char p2val = P2IN;            /* LB: added to get the buttons to work with the green board*/
                                /* Every part that stated P1 was changed to P2*/
  

  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  char down1, down2, down3, down4;
  
  down1 = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  down2 = (p2val & SW2) ? 0 : 1; //S2
  down3 = (p2val & SW3) ? 0 : 1; //S3
  down4 = (p2val & SW4) ? 0 : 1; //S4


  if (down1){  //S1
    if(last_state){
      red_on = 0;
      green_on = 1;
      led_update();
      last_state = 0;
    }else{
      red_on = 1;
      green_on = 0;
      led_update();
      last_state = 1;
    }
  }

  if (down2){ //S2 Dim leds
    dim_leds(0);
    dim_leds(1);
    dim_leds(2);
    dim_leds(3);
    dim_leds(4);
  }
  
  if (down3){//S3 Buzzer state ...run out of time to use state_advance()
    last_state = 0;
    tada(0);
    tada(1);
    for(int i=0; i<2;i++){
      tada(2);
      tada(3);
      tada(1);
    }
    
  }
  
  if (down4){
    if(last_state){
      green_on = 1;
      red_on = 0;
      led_update();
      tada(2);
    } else{
      green_on = 0;
      red_on = 1;
      led_update();
      tada(1);
    }
     
  }
  

}
