
#include<avr/io.h>
/*Includes io.h header file where all the Input/Output Registers and its Bits are defined for all AVR microcontrollers*/

#define           F_CPU           1000000

#include<util/delay.h>

#include "ADC.h"

#define           REF           615

int main(void)
{

DDRB=0x0f;
/*PB0,PB1,PB2 and PB3 pins of PortB are declared output ( i/p1,i/p2,i/p3,i/p4 pins of DC Motor Driver are connected )*/

int left_sensor_value,middle_sensor_value,right_sensor_value;
/*Variable declarations*/

adc_init();
/*ADC initialization*/

/*Start of infinite loop*/
while(1)
{

left_sensor_value=read_adc_channel(0);
/*Reading left IR sensor value*/

//middle_sensor_value=read_adc_channel(1);
/*Reading middle IR sensor value*/

//right_sensor_value=read_adc_channel(2);
/*Reading right IR sensor value*/
if(left_sensor_value > REF)
{
	PORTB = 0x02;
}
else
	PortB = 0x01;
}
}
/*Checking the sensor values with the reference value*/
//if(middle_sensor_value > REF)
//{

//PORTB=0x0a;
/*Robot will move in forward direction*/

//}
//else if(left_sensor_value > REF)
//{

//PORTB=0x02;
/*Robot will move in left direction*/

//}
//else if(right_sensor_value > REF)
//{

//PORTB=0x08;
/*Robot will move in right direction*/

//}
//else
//{

//;
/*Null statement*/

//}

//}

//}