#include <avr/io.h>
#include <util/delay.h>

#include "lcd.h"

int main(){
	LCD_init();
	LCD_write("hello");
	_delay_ms(5000);
	
	LCD_write("ED_macha_rahi_h");
	_delay_ms(3000);
	//int counter=0;
	while(1);
}