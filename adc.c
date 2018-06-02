/***************************************************************************
*
*
* adc.c
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#include "adc.h"



//////////////////////////////	ADC Conversions	/////////////////////////////////////////////////////////////////////


unsigned int readAnalogValue(uint8_t channel, unsigned int vRef)
{
	enableADC();
	
	if(channel <= 7)
	{
		AB_ANALOG_PORT1 &=~ (1<<channel);	
		channel= (channel)&(0x0F);  

		ADMUX |= channel;        // Selecting the ADC channel
		ADCSRA |= (1<<ADSC)|(1<<ADEN);  // Start ADC conversion and enabling ADC
		ADCSRB &=~ (1<<MUX5);
		while(!(ADCSRA&(1<<ADIF)));   // Waiting for ADC conversion to complete
		ADCSRA |= (1<<ADIF);   // Clearing ADIF after conversion  is complete
		if(vRef == AB_INTERNAL)
		{
			ADMUX |= (1<<REFS0);    // Clearing ADMUX ADC channel
		}
		else
		{
			ADMUX &=~((1<<REFS0)|(1<<REFS1));
		}
		return(ADCW);
	}
	else
	{
		channel=channel-8;
		AB_ANALOG_PORT2 &=~ (1<<channel);	
		channel= (channel)&(0x0F);  

		ADMUX |= channel;        // Selecting the ADC channel
		ADCSRA |= (1<<ADSC)|(1<<ADEN);  // Start ADC conversion and enabling ADC
		ADCSRB |= (1<<MUX5);
		while(!(ADCSRA&(1<<ADIF)));   // Waiting for ADC conversion to complete
		ADCSRA |= (1<<ADIF);   // Clearing ADIF after conversion  is complete
		if(vRef == AB_INTERNAL)
		{
			ADMUX |= (1<<REFS0);    // Clearing ADMUX ADC channel
		}
		else
		{
			ADMUX &=~((1<<REFS0)|(1<<REFS1));
		}
		return(ADCW);
	}
	
	return -1;
}


//This function initializes the ADC specific control registers for Sensor usage
void enableADC()
{
	ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); // ADC sampling frequency is 125 Khz ( 16 MhZ/128) 
	ADMUX |= (1<<REFS0);                                   // Reference voltage for ADC is AVcc( 5v)
	return;
}

//This function Disables the ADC specific control registers
void disableADC()
{
	ADCSRA &=~ (1<<ADEN);		// Turning off ADC
	ADCSRB= ADCSRB&(0x00);
	ADMUX= ADMUX&(0x00);
	ADCSRA= ADCSRA&(0x00);
}




