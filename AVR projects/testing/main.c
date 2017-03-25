#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"
#define F_CPU 1000000
#define REF 720

void set_PWM()	{
	DDRD |= 0xFF;
	TCCR1A |= 1<<WGM11 | 1<<COM1A1 | 1<<COM1A0| 1<<COM1B1 | 1<<COM1B0;
	TCCR1B |= 1<<WGM13 | 1<<WGM12 | 1<<CS10;
	ICR1 = 24999; 	//40hz
}

int main(void){
	set_PWM();
	float kp=5,turn=5;      
	float ep = 0;
	float forward_pow =0.5;                     //Calibrate
	OCR1A=24999-forward_pow*24999;
	OCR1B=24999-forward_pow*24999;
	adc_init();
	int left_sensor, middle_front_sensor, middle_back_sensor, right_sensor;

	while(1){
		left_sensor = adc_read(0);
		middle_back_sensor = adc_read(1);
		right_sensor = adc_read(2);
		middle_front_sensor = adc_read(3);

		ep=kp*(left_sensor - right_sensor);			//ep > 20 then turn left ,else if ep < -20 turn right
		if(kp*(left_sensor- right_sensor) > 50){
			//OCR1A = (24999/2) - kp*(left_sensor- right_sensor)*50;
			OCR1A = 24999;
			_delay_ms(20);
		}
		
		else if(kp*(left_sensor- right_sensor) < -50){
			//OCR1B = (24999/2) + kp*(left_sensor- right_sensor)*50;
			OCR1B = 24999;
			_delay_ms(20);
		}
		OCR1A = (24999/2); 
		OCR1B = (24999/2);
	}
}