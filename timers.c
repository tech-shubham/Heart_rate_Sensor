/***************************************************************************
*
*
* timers.c
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/
//#include "avrCommon.h"
//#include "abCommon.h"

#include "timers.h"

volatile unsigned long timeFromBegining;


/*
** Use 8 bit timer for internal computation purposes
*/

void timer0Init()
{
	timersEnable(AB_TIMER_0, 0,AB_SCALE_64, AB_INTERRUPT_ENABLE, AB_TIMER_NORMAL_MODE, AB_NO_PIN);

}

unsigned long timeSince()
{
	return timeFromBegining;
}

void timerDelayMicro(unsigned long microTime)
{
	while(microTime > 0);
}

void timerDelayMilli(unsigned long milliTime)
{
	volatile unsigned long initialTime,timePassed;
	
	initialTime=timeSince();
	timePassed=timeSince();
	if((timePassed-initialTime) < 0)
	{
		initialTime=timeSince();
		timePassed=timeSince();
	}
	while((timePassed-initialTime)<=milliTime)
	{
		timePassed=timeSince();
		
		
	}

}



/*
** Timers related APIs
*/

void timersEnable(unsigned int timerN, unsigned int value,unsigned int prescale_value, unsigned int timer_interrupt, unsigned int mode,char *str)
{
	if(timerN == AB_TIMER_0)
	{
		
		if(value>255)
		{
			value=255;
		}
		
		if(str[1]=='B')
		{
			TCCR0A=(mode<<6);
		}
		else if(str[1]=='G')
		{
			TCCR0A=(mode<<4);
		}
		else if(str[1]=='$')
		{
			TCCR0A=0x00;
		}
		
		TCNT0=value;
		if(timer_interrupt == AB_INTERRUPT_ENABLE)
		{
			TIMSK0=timer_interrupt;
			sei();
		}
		TCCR0B=prescale_value;
	}
	
	else if(timerN == AB_TIMER_1)
	{
		
		if(value>65535)
		{
			value=65535;
		}
		
		if(str[3]=='5')
		{
			TCCR1A=(mode<<6);
		}
		else if(str[3]=='6')
		{
			TCCR1A=(mode<<4);
		}
		else if(str[3]=='7')
		{
			TCCR1A=(mode<<2);
		}
		else if(str[3]=='$')
		{
			TCCR1A=0x00;
		}
		
		TCNT1=value;
		if(timer_interrupt == AB_INTERRUPT_ENABLE)
		{
			TIMSK1=timer_interrupt;
			sei();
		}
		TCCR1B=prescale_value;
		TCCR1C=0x00;
	}
	
	else if(timerN == AB_TIMER_2)
	{
		TCCR2A=0x00;
		if(value>255)
		{
			value=255;
		}
		if(str[1]=='B')
		{
			TCCR2A=(mode<<6);

		}
		else if(str[1]=='H')
		{
			TCCR2A=(mode<<4);
		}
		else if(str[1]=='$')
		{
			TCCR2A=0x00;
		}
		TCNT2=value;
		if(timer_interrupt == AB_INTERRUPT_ENABLE)
		{
			TIMSK2=timer_interrupt;
			sei();
		}
		TCCR2B=prescale_value;
	}
	
	else if(timerN == AB_TIMER_3)
	{
		TCCR3A=0x00;
		if(value>65535)
		{
			value=65535;
		}
		if(str[3]=='3')
		{
			TCCR3A=(mode<<6);
		}
		else if(str[3]=='4')
		{
			TCCR3A=(mode<<4);
		}
		else if(str[3]=='5')
		{
			TCCR3A=(mode<<2);
		}
		else if(str[3]=='$')
		{
			TCCR3A=0x00;
		}
		TCNT3=value;
		if(timer_interrupt == AB_INTERRUPT_ENABLE)
		{
			TIMSK3=timer_interrupt;
			sei();
		}
		TCCR3B=prescale_value;
		TCCR3C=0x00;
	}
	
	else if(timerN == AB_TIMER_4)
	{
		TCCR4A=0x00;
		if(value>65535)
		{
			value=65535;
		}
		if(str[3]=='3')
		{
			TCCR4A=(mode<<6);

		}
		else if(str[3]=='4')
		{
			TCCR4A=(mode<<4);
		}
		else if(str[3]=='5')
		{
			TCCR4A=(mode<<2);
		}
		TCNT4=value;
		if(timer_interrupt == AB_INTERRUPT_ENABLE)
		{
			TIMSK4=timer_interrupt;
			sei();
		}
		TCCR4B=prescale_value;
		TCCR4C=0x00;
	}
	
	else if(timerN == AB_TIMER_5)
	{
		TCCR5A=0x00;
		if(value>65535)
		{
			value=65535;
		}
		if(str[3]=='3')
		{
			TCCR5A=(mode<<6);
		}
		if(str[3]=='4')
		{
			TCCR5A=(mode<<4);
		}
		if(str[3]=='5')
		{
			TCCR5A=(mode<<2);
		}
		TCNT5=value;
		if(timer_interrupt == AB_INTERRUPT_ENABLE)
		{
			TIMSK5=timer_interrupt;
			sei();
		}
		TCCR5B=prescale_value;
		TCCR5C=0x00;
	}
}

//////////// Write your Code here for Timers Intterupt /////////////////////////////////////

ISR(TIMER0_OVF_vect)
{
	// Write your Code here for Timer0 Intterupt	

	timeFromBegining++;
}


ISR(TIMER3_OVF_vect)
{
	// Write your Code here for Timer3 Intterupt
	
}
ISR(TIMER4_OVF_vect)
{
	// Write your Code here for Timer4 Intterupt
	
}
ISR(TIMER5_OVF_vect)
{
	// Write your Code here for Timer5 Intterupt
	
}



void deInitiateTimer(unsigned int timerN)
{

	if(timerN == AB_TIMER_0)
	{
		TCCR0A=0x00;
		TIMSK0=0x00;
		TCCR0B=0x00;
	}
	
	else if(timerN == AB_TIMER_1)
	{
		TCCR1A=0x00;
		TIMSK1=0x00;
		TCCR1B=0x00;
	}
	
	else if(timerN == AB_TIMER_2)
	{
		TCCR2A=0x00;
		TIMSK2=0x00;
		TCCR2B=0x00;
	}
	
	else if(timerN == AB_TIMER_3)
	{
		TCCR3A=0x00;
		TIMSK3=0x00;
		TCCR3B=0x00;
	}
	
	else if(timerN == AB_TIMER_4)
	{
		TCCR4A=0x00;
		TIMSK4=0x00;
		TCCR4B=0x00;
	}
	
	else if(timerN == AB_TIMER_5)
	{
		TCCR5A=0x00;
		TIMSK5=0x00;
		TCCR5B=0x00;
	}
	


}














