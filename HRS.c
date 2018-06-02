/***************************************************************************
*
*
* HRS.c
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#include "HRS.h"

///////////////////////////// Heart rate sensor ////////////////
volatile int HR_Channel=2;
void AB_STEM_init_HRS(unsigned int ADC_PIN)// ADC pins and Timmer_2 isused in this 
{	
	time_between_beats = 600;
	pulse_signal = false;
	peak_value = 512;        
	trough_value = 512;
	thresh = 525;
	amplitude = 100;                 
	first_heartpulse = true;      
	second_heartpulse = false;    
	samplecounter = 0;   //This counter will tell us the pulse timing
	lastBeatTime = 0;
	
	enableADC();
	timersEnable(AB_TIMER_2, 5,AB_TIMER2_SCALE_128, AB_INTERRUPT_ENABLE,AB_TIMER_NORMAL_MODE,AB_NO_PIN);
	HR_Channel=ADC_PIN;
}

int AB_STEM_Read_HRS()
{	
	 return heart_rate;
}
ISR(TIMER2_OVF_vect)
{
	// Write your Code here for Timer2 Intterupt
	
	cli();                                     
	analog_data = readAnalogValue(HR_Channel, AB_INTERNAL);            
	samplecounter += 2;                        
	int N = samplecounter - lastBeatTime;      
	if(analog_data < thresh && N > (time_between_beats/5)*3)
    {     
		if (analog_data < trough_value)
		{                       
			trough_value = analog_data;
		}
    }
	if(analog_data > thresh && analog_data > peak_value)
    {        
		peak_value = analog_data;
    }                          
	if (N > 250)
	{                            
		if ( (analog_data > thresh) && (pulse_signal == false) && (N > (time_between_beats/5)*3) )
		{       
			pulse_signal = true;          
			time_between_beats = samplecounter - lastBeatTime;
			lastBeatTime = samplecounter;     
			if(second_heartpulse)
			{                        
			  second_heartpulse = false;   
			  for(int i=0; i<=9; i++)    
			  {            
				beat[i] = time_between_beats; //Filling the array with the heart beat values                    
			  }
			}
			if(first_heartpulse)
			{                        
			  first_heartpulse = false;
			 second_heartpulse = true;
			  sei();            
			  return;           
			}  
			int runningTotal = 0;  
			for(int i=0; i<=8; i++)
			{               
				beat[i] = beat[i+1];
				runningTotal += beat[i];
			}
			beat[9] = time_between_beats;             
			runningTotal += beat[9];   
			runningTotal /= 10;        
			heart_rate = 60000/runningTotal;
		}                      
	}
	if (analog_data < thresh && pulse_signal == true)
    {  
		pulse_signal = false;             
		amplitude = peak_value - trough_value;
		thresh = amplitude/2 + trough_value; 
		peak_value = thresh;           
		trough_value = thresh;
    }
	if (N > 2500)
    {                          
		thresh = 512;                     
		peak_value = 512;                 
		trough_value = 512;               
		lastBeatTime = samplecounter;     
		first_heartpulse = true;                 
		second_heartpulse = false;               
    }
	sei();                                
}


int main()
{
	int heartPulse=0;
	AB_STEM_init_HRS(AB_CHANNEL_2);
	
	while(1)
	{
		heartPulse=AB_STEM_Read_HRS();	///// Gives rate in BPM
	}

		return 0;
}
