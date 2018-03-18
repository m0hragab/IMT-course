#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "RTO_interface.h"
#include "SevenSegment_interface.h"
#include <util/delay.h>

void vidCount(void);

Task_Type Task1;
Task_Type Task2;

u8 i;
void main(void) {
	//Initialization
	SevenSegment_vidInit(DIO_PORTB,DIO_PORTC);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,STD_HIGH);
	RTO_vidInit();
	Task1.periodicity = 500;
	Task1.first_delay = 0;
	Task1.state = RTO_U8TASK_RUNNING;
	Task1.ptrfun = vidCount;

	RTO_vidCreateTask(&Task1,1);
	while(1);
	
}

void vidCount(void) {
	static u8 u8Count = 0;
	u8Count++;
	SevenSegment_vidWriteNumber(u8Count);
	if (u8Count == 99) {
		u8Count = 0;
	}
}
