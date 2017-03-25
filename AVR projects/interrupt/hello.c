#include <avr/io.h>
#include <avr/interrupt.h>


int main(void) {

	sei(); //enable global interrupt
	
	DDRA |= 1<<PINA0;

	TCCR1B |= 1<<CS10 | 1<<CS11 | 1<<WGM12; //prescalar , enable CTC
	TIMSK |= 1<<OCIE1A;  //Timer1 Output Compare A Match interrupt is enabled
	OCR1A = 15624; //Value at which CTC

	while(1)  { }


}

ISR(TIMER1_COMPA_vect)   {  //CHECK arg


	PORTA ^= 1<<PINA0;
}