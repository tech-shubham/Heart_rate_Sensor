/***************************************************************************
*
*
* adc.h
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/
#ifndef __ADC_HEADER_H__
#define __ADC_HEADER_H__

#include "avrCommon.h"


// Port for measuring Analog Values

#define AB_CHANNEL_0	0
#define AB_CHANNEL_1	1
#define AB_CHANNEL_2	2
#define AB_CHANNEL_3	3
#define AB_CHANNEL_4	4
#define AB_CHANNEL_5	5
#define AB_CHANNEL_6	6
#define AB_CHANNEL_7	7
#define AB_CHANNEL_8	8
#define AB_CHANNEL_9	9
#define AB_CHANNEL_10	10
#define AB_CHANNEL_11	11
#define AB_CHANNEL_12	12
#define AB_CHANNEL_13	13
#define AB_CHANNEL_14	14
#define AB_CHANNEL_15	15

#define AB_ANALOG_PORT1	DDRF
#define AB_ANALOG_PORT2	DDRK						

#define AB_EXTERNAL 0
#define AB_INTERNAL 1




unsigned int readAnalogValue(uint8_t channel, unsigned int v_ref);
void enableADC(void);
void disableADC(void);


#endif //__ADC_HEADER_H__