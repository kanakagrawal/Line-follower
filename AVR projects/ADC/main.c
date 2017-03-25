#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
//#include "lcd.h"
# define REF 800
int main(void){
	//LCD_init();
	ADCSRA |=1<<ADPS2;
	ADMUX |=(1<<REFS0)|(1<<REFS1);
	ADCSRA |=1<<ADIE;
	ADCSRA |=1<<ADEN;

	sei();

	ADCSRA |=1<<ADSC;
	while(1){}

}
ISR(ADC_vect){
	uint8_t low_1 = ADCL;
	uint16_t output_ans = ADCH<<8 |low_1;
	DDRB = 0x0f;
	if(output_ans > REF)
	{
		PORTB = 0x01;
	}
	else
		PORTB = 0x02;
	//char s[5]={(char)(output_ans/1000 + '0'), (char)((output_ans/100)%10 + '0'), (char)((output_ans/10)%10 + '0'), (char)(output_ans%10 + '0'), 00};
	//LCD_write(s);
	//LCD_wait();

	//_delay_ms(1000);
	//LCD_command(0x01);
	ADCSRA |=1<<ADSC;
}