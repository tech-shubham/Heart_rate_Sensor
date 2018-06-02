/***************************************************************************
*
*
* timers.h
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/
#ifndef __TIMER_HEADER_H__
#define __TIMER_HEADER_H__


#include "avrCommon.h"

////////////////////// Timers ////////////////////////////////////

#define AB_SCALE_1 	0x01
#define AB_SCALE_8 	0x02
#define AB_SCALE_64	0x03
#define AB_SCALE_256	0x04
#define AB_SCALE_1024	0x05



#define AB_TIMER2_SCALE_1		0x01
#define AB_TIMER2_SCALE_8		0x02
#define AB_TIMER2_SCALE_32		0x03
#define AB_TIMER2_SCALE_64		0x04
#define AB_TIMER2_SCALE_128		0x05
#define AB_TIMER2_SCALE_256		0x06
#define AB_TIMER2_SCALE_1024	0x07

#define AB_TIMER_0 0
#define AB_TIMER_1 1
#define AB_TIMER_2 2
#define AB_TIMER_3 3
#define AB_TIMER_4 4
#define AB_TIMER_5 5


#define AB_TIMER0_OVERFLOW (TIFR0 && 0x01)
#define AB_TIMER1_OVERFLOW (TIFR1 && 0x01)
#define AB_TIMER2_OVERFLOW (TIFR2 && 0x01)
#define AB_TIMER3_OVERFLOW (TIFR3 && 0x01)
#define AB_TIMER4_OVERFLOW (TIFR4 && 0x01)
#define AB_TIMER5_OVERFLOW (TIFR5 && 0x01)

#define AB_NO_INTERRUPT 		0x00
#define AB_INTERRUPT_ENABLE    0x01


#define AB_TIMER_NORMAL_MODE	0x00
#define AB_TIMER_TOGGLE_MODE	0x01
#define AB_TIMER_CLEAR_MODE		0x02
#define AB_TIMER_SET_MODE		0x03

#define AB_TIMER0_OC0A	AB_P71
#define AB_TIMER0_OC0B	AB_P72
#define AB_TIMER1_OC1A	AB_P73
#define AB_TIMER1_OC1B	AB_P55
#define AB_TIMER1_OC1C	AB_P71
#define AB_TIMER2_OC2A	AB_P66	
#define AB_TIMER2_OC2B	AB_P54
#define AB_TIMER3_OC3A	AB_P74
#define AB_TIMER3_OC3B	AB_P75
#define AB_TIMER3_OC3C	AB_P59
#define AB_TIMER4_OC4A	AB_P6
#define AB_TIMER4_OC4B	AB_P7
#define AB_TIMER4_OC4C	AB_P8
#define AB_TIMER5_OC5A	AB_P9
#define AB_TIMER5_OC5B	AB_P76
#define AB_TIMER5_OC5C	AB_P77
#define AB_NO_PIN	    "$$$$$"

/*
** Timers related APIs
*/


//////////////// Timers ///////////////////////

void timersEnable(unsigned int timer_N, unsigned int value,unsigned int prescale_value, unsigned int timer_interrupt, unsigned int mode, char *str);
void deInitiateTimer(unsigned int timer_N);



/*
** Use 8 bit timer for internal computation purposes
*/
void timer0Init(void); /*Configure timer 0 to run */
unsigned long timeSince(void); /*return Time in millisecond since beginning*/
void timerDelayMicro(unsigned long microTime);
void timerDelayMilli(unsigned long milliTime);



#endif //__TIMER_HEADER_H__
