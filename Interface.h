/*
 * interface.h
 *
 * Created: 23.04.2012 20:49:36
 *  Author: Elis
 */ 


#ifndef INTERFACE_H_
#define INTERFACE_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/avrlibtypes.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/pgmspace.h>

#include "config.h"

#define RX_BUFFER_SIZE	128

#define LF	0x0A
#define CR	0x0D
#define NUL	0x00



class CUart
{
	public:
		CUart();
		void printChar (char);
		//void putInt (char);
		void printInt(uint16_t, uint8_t base );
		void printInt(int16_t, uint8_t base );
		void print (const char *str);
		void printF(char *pgm_str);
		
		void newLine ();
		
		uint8_t getChar ();
		uint16_t getUInt(uint8_t base);
		int16_t  getSInt(uint8_t base);
		const char* getString();
		
		void UartRxISR();
		
		
	private:
		//ISR (USART_RXC_vect)
			
		uint8_t isRegularChar(char x);
		uint8_t isDigit(char x);
		uint16_t strToUint8(uint8_t *s_num);
		
		volatile uint8_t rxBuffer[RX_BUFFER_SIZE];
		volatile uint8_t	rxBufferBegin;
		volatile uint8_t rxBufferEnd;
};



#endif /* INTERFACE_H_ */