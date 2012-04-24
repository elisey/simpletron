/*
 * Simpletron.cpp
 *
 * Created: 24.04.2012 17:52:05
 *  Author: Krot
 */ 

#include "config.h"

CUart Terminal;
CInterpretator	mySimpletron;

ISR (USART_RXC_vect)
{
	Terminal.UartRxISR();
}

int main(void)
{
    while(1)
    {
        uint8_t temp = Terminal.getChar();
		if (temp == 9)
		{
			Terminal.printChar(0x1B);
			Terminal.printChar(0x5B);
			Terminal.printChar(0x41);
		}
		else
		{
			Terminal.printInt(temp,16);
			Terminal.newLine();
		}	
		
		
	
    }
}