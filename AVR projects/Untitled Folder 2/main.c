#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
unsigned char sensor_data[4];

void f_move()
	{
	PORTC=0b00000101;
	_delay_ms(1000);
	return;
	}

void l_move()
	{
		PORTC=0b00000100;
		_delay_ms(500);
		PORTC=0b00000001;
		_delay_ms(300);
		return;
	}

void r_move()
	{
		PORTC=0b00000001;
		_delay_ms(500);
		PORTC=0b00000100;
		_delay_ms(300);
		return;
	}
		
int main(void)
{
    DDRA=0x00;
	DDRC=0xFF;
	while(1)
	{
		sensor_data[0]=PINA & (1<<PINA0);
		sensor_data[1]=PINA & (1<<PINA1);
		sensor_data[2]=PINA & (1<<PINA2);
		sensor_data[3]=PINA & (1<<PINA3);
		if(sensor_data[1])
			{
				if(sensor_data[3])
					{
						f_move();
						continue;
					}
				else
					{
						if(sensor_data[0] && sensor_data[2])
							{
								r_move();
								continue;
							}
						if(sensor_data[0])
							{
							r_move();
							continue;
							}
						else
						if(sensor_data[2])
							{	
								l_move();
								continue;
							}
					}
				}
			else
				if(sensor_data[0])
				{
					r_move();
					continue;
				}
			else
				if(sensor_data[2])
				{
					l_move();
					continue;
				}
			
			}
}