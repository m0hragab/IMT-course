#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>

u8 u8reading;

void main(void) {
	
	DIO_vidSetPinDirection(DIO_PORTB,0,1);
	DIO_vidSetPinDirection(DIO_PORTB,1,1);
	/*Configuring global interrupt*/
	SET_BIT(SREG,7);

	DIO_vidSetPinDirection(DIO_PORTD,2,0);
	DIO_vidSetPinValue(DIO_PORTD,2,1);

	/*MCUCR : Interrupt Sense Control*/
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

	/*GICR: External Interrupt Enable*/
	SET_BIT(GICR,6);

	/**/
	CLEAR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

	/*Selecting left adjustment*/
	SET_BIT(ADMUX,5);

	/*Selecting channel*/
	CLEAR_BIT(ADMUX,4);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,2);
	CLEAR_BIT(ADMUX,1);
	CLEAR_BIT(ADMUX,0);

	/*ADCSRA*/
	SET_BIT(ADCSRA,7);
	CLEAR_BIT(ADCSRA,6);
	SET_BIT(ADCSRA,5);
	SET_BIT(ADCSRA,4);
	SET_BIT(ADCSRA,3);
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);

	/*SFIOR*/
	CLEAR_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);

	u8 u8analog;
	while(1) {
		u8analog = (u8reading*5)/256;
		if (u8analog > 2) {
			DIO_vidSetPinValue(DIO_PORTB,1,1);	
			DIO_vidSetPinValue(DIO_PORTB,0,0);
		}
		else {
			DIO_vidSetPinValue(DIO_PORTB,0,1);
			DIO_vidSetPinValue(DIO_PORTB,1,0);
		}
	}

}

ISR(INT0_vect) {

}

ISR(ADC_vect) {
	u8reading = ADCH;
}
