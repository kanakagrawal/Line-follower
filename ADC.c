#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
uint16_t l=0, m=0, r=0,f=0;
float DL_l=0,DL_r=0;
void set_ADC() {
	ADCSRA |= 1<<ADPS2;
	ADMUX |= (1<<REFS0) | (1<<REFS1)|  (1<<ADLAR);
	ADCSRA |= 1<<ADIE;
	ADCSRA |= 1<<ADEN;
}
void set_PWM()	{
	DDRD |= 0xFF;
	TCCR1A |= 1<<WGM11 | 1<<COM1A1 | 1<<COM1A0| 1<<COM1B1 | 1<<COM1B0;
	TCCR1B |= 1<<WGM13 | 1<<WGM12 | 1<<CS10;
	ICR1 = 24999; 
}
int main(void) {
	set_ADC();
	set_PWM();
	sei( ); 
	ADCSRA |= 1<<ADSC; 							//B is right
	float kp=0.3,turn=5;      
	float ep = 0;
	float forward_pow =0.5;                     //Calibrate
	OCR1A=24999-forward_pow*24999;
	OCR1B=24999-forward_pow*24999;
	//cp = 0,ci = 0,cd = 0,kd = 1,ki = 1,sum =0 ,e =0;
	while(1){
		ep=kp*(l-r);
		if(m>512 & r>512 & l>512)
		 {
			if(f>512)	{ 
				_delay_ms(50);
			} 
		//	else { 
		//		OCR1A=0;OCR1B=24999;_delay_ms(200);
		//	}
		}
		if(m>512 | r>512 | l>512){								//Calibrate
			ep=kp*(l-r);
			if(ep<0)
				OCR1A -= turn*(-ep);	
			else
				OCR1B -= turn*(ep);
		}
	
		_delay_ms(20);
		OCR1A = 24999-forward_pow*24999;			//reset
		OCR1B = 24999-forward_pow*24999;			//reset
	}
	return 1;
}
ISR(ADC_vect)	{	
	uint8_t low_1 = ADCL;
	uint8_t tempA =ADMUX;
	tempA =tempA<<6;
	//int count = 0;
	uint16_t ADC_val=1023- (ADCH<<2 | low_1>>6);
	if(tempA==0b01000000) m = ADC_val;
	else if(tempA == 0b00000000)
		l =  ADC_val;
	else if(tempA == 0b10000000) 
		r = ADC_val;
	if(tempA == 0b11000000) { 
		ADMUX &= 0b11111100;
		f=1023-ADC_val;     //Check
	}
	else 
		ADMUX++;
//count++;
//_delay_ms(2000);
	ADCSRA |= 1<<ADSC;
}
