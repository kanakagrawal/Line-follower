#include<avr/io.h>
#define F_CPU 1000000
#include<util/delay.h>

int main(void)
{
	//define
	//int x = 3;
	DDRA = 0b00000111;
	while(1){
	PORTA = 0b00000001;
	_delay_ms(1000);
	PORTA = 0b00000010;
	_delay_ms(250);
	PORTA = 0b00000100;
	_delay_ms(500);
}
	//PORTA = 0b00000100;
	//_delay_ms(500);
/*	while(1)
	{
		PORTA ^= 1<<PINA0 ; //PORTA ^= 0b00000001;
		_delay_ms(500);
	}
*/
}
