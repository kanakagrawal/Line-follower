#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000
//#define REF 1


int main (void)
{
	DDRB = 0x0f;
	PORTB = 0x0a;
	//int left_sensor_value;

//	ADCSRA |= (1<<ADEN) | (1<<ADPS2) ; 
//	ADMUX |= (1<<REFS0) | (1<<REFS1) ;
//	ADMUX = (ADMUX & 0xf8) | 0x01;
//	ADCSRA |= (1<<ADSC) ; 
//	while(ADCSRA & (1<<ADSC));
//	uint8_t low_1 = ADCL;
//	uint16_t output_ans = ADCH<<8 |low_1;

//	if(output_ans > REF)
//	{
//		PORTB = 0x01;
//	}
//	else
//		PORTB = 0x02;
//
	while(1);
} 	