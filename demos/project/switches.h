#ifndef switches_included
#define switches_included

#define SW1 BIT0		/* switch1 is p2.0 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)	/* all switches on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed; /* effectively boolean */
extern char sw1_down, sw2_down, sw3_down, sw4_down;
extern char sw_num;

#endif // included
