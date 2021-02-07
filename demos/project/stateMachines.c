#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
//#include "buzzer.c"

char last_state = 0;

void states_handler()
{
  red_on = 1;
  green_on = 0;
  led_update();
}

  


char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    led_update();
    break;
  case 1:
    red_on = 0;
    state = 0;
    led_update();
    break;
  }
  return 1;			/* always changes a led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

/*
void state_advance()		/* alternate between toggling red & green */
/*{
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
  }
*/


