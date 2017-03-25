void adc_init(){
	ADMUX = (1<<REFS0) ;
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0) ;
}

uint16_t adc_read(uint8_t ch){
	ch &= 0b00000111;
	ADMUX &= 0b11111000;
	ADMUX |= ch;
	ADCSRA |= (1<<ADSC) ;

	while(ADCSRA & (1<<ADSC));

	uint8_t low_1 = ADCL;
	uint16_t output_ans = ADCH << 8 | low_1;
	return (output_ans);
}