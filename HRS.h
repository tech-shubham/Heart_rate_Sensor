/***************************************************************************
*
*
* HRS.h
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#ifndef __HRS_HEADER_H__
#define __HRS_HEADER_H__

#include "adc.h"
#include "timers.h"

#define false   0
#define true	1

volatile int heart_rate;
volatile int analog_data;              
volatile int time_between_beats;            
volatile int pulse_signal;    
volatile int beat[10];         //heartbeat values will be sotred in this array    
volatile int peak_value;          
volatile int trough_value;        
volatile int thresh ;              
volatile int amplitude;                 
volatile int first_heartpulse ;      
volatile int second_heartpulse ;    
volatile unsigned long samplecounter;   //This counter will tell us the pulse timing
volatile unsigned long lastBeatTime;
char h_rate[5];


////////////////////////////// hert rate sensor //////////////////////// 
void AB_STEM_init_HRS(unsigned int ADC_PIN);
int AB_STEM_Read_HRS(void);











#endif //__HRS_HEADER_H__