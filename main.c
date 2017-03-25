#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 1000000

int main (void){
	DDRB = 0x0f;
	PORTB = 0b00001010;
	while(1){};
}