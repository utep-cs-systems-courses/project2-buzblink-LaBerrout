#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;
static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update()
{
  if(switch_state_changed){
    char ledFlags = redVal[red_on] | greenVal[green_on];
  
  /*
  if (switch_state_changed) {   /* added sw1_down */
  /*    char ledFlags = 0; /* by default, no LEDs on */
  /* if(sw1_down){
      toggle_red();
    }*/

    /* 
    //ledFlags |= sw1_down ? LED_GREEN : 0;
    //ledFlags |= sw1_down ? 0 : LED_RED;
*/
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}

