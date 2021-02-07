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
  green_on = 1;
  red_on = 0;
  switch_state_changed = 1;
  led_update();
  
}

void led_update()
{
  if (switch_state_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on];            /* by default, no LEDS on */
    P1OUT &= (0xff^LEDS) | ledFlags;   //clear bit for off leds
    P1OUT |= ledFlags;                 // set bit for on leds
    led_changed = 0;

    /*
    //ledFlags |= sw1_down ? toggle_red() : 0;    
    ledFlags |= sw1_down ? LED_GREEN : 0;
    ledFlags |= sw1_down ? 0 : LED_RED;
    P1OUT &= (0xff -LEDS) | ledFlags;           /* clear bits off leds */
    /*P1OUT |= ledFlags;                          /* set bits on leds */
      
  }
  switch_state_changed = 0;
}
