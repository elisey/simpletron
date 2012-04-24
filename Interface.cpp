/*
 * Interface.cpp
 *
 * Created: 23.04.2012 20:49:18
 *  Author: Elis
 */ 
#include "Interface.h"

 CUart::CUart()
{
	rxBufferBegin = 0;
	rxBufferEnd = 0;
	
	UBRRH = 0; 
	UBRRL=0x03; // 115200 bps on 7.xxxx MHz
	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
	UCSRB = (1<<RXEN) | (1<<TXEN) | (1<<RXCIE);
	sei();
	
}

void CUart::printChar( char ch)
{
	while (!( UCSRA & (1<<UDRE)));
	UDR = ch;
}

void CUart::printInt(uint16_t data, uint8_t base)
{
	char str[6];
	ultoa(data,str,base);
	print(str);
}

void CUart::printInt( int16_t data, uint8_t base)
{
	char str[7];
	ltoa(data,str,base);
	print(str);
}

void CUart::print( const char *str )
{
	uint8_t i = 0;
	while (str [i] != 0) {
		printChar(str[i++]);
	}
}

void CUart::printF( char *pgm_str )
{
	char data;
	do 
	{	data = pgm_read_byte(pgm_str);
		pgm_str++;
		if (data) 
			printChar(data);
	} while (data != '\0');
}

uint8_t CUart::getChar()
{
	while(rxBufferBegin == rxBufferEnd) {};
	uint8_t data = rxBuffer[rxBufferEnd++];
	if (rxBufferEnd >= RX_BUFFER_SIZE)	{
		rxBufferEnd = 0;
	}
	//printChar(data);
	return data;
}

uint8_t CUart::isRegularChar( char x )
{
	if (((x>='A') && (x<='Z')) || ((x>='a') && (x<='z')) || ((x>='0') && (x<='9')))
        return 1;
    else
        return 0;
}

uint8_t CUart::isDigit( char x )
{
	if (((x>='0') && (x<='9')) || (x == '-'))
        return 1;
    else
        return 0;
}

uint16_t CUart::strToUint8( uint8_t *s_num )
{
	uint8_t i=0,dgt_len=0;
    uint16_t r_val=0,mult=1;

    while (isDigit(s_num[dgt_len]))
        dgt_len++;

    for (i=dgt_len; i>0; i--)
    {
        r_val+=(s_num[i-1]-'0')*mult;
        mult*=10;
    }

    return r_val;
}

void CUart::newLine()
{
	printChar(LF);
	printChar(CR);
// 	while (!( UCSRA & (1<<UDRE)));
// 	UDR = 0x0A;
// 	while (!( UCSRA & (1<<UDRE)));
// 	UDR = 0x0D;
}

uint16_t CUart::getUInt(uint8_t base)
{
	//uint8_t data;
	uint8_t counter = 0;
	char str[6];
	do 
	{	str[counter++] = getChar();
		if (counter >=6)	break;
	} while (isDigit(str[counter-1]));
	str[counter] = '\n';
	newLine();
	return (strtoul(str, NULL, base));
}

int16_t CUart::getSInt(uint8_t base)
{
	uint8_t counter = 0;
	char str[7];
	do 
	{	str[counter++] = getChar();
		if (counter >=7)	break;
	} while (isDigit(str[counter-1]));
	str[counter] = '\n';
	newLine();
	return (strtol(str, NULL, base));
}

const char* CUart::getString()
{
	uint8_t counter = 0;
	char str[50];
	do 
	{	str[counter++] = getChar();
		if (counter >=50)	break;
	} while (isRegularChar(str[counter-1]));
	str[counter] = '\n';
	newLine();
	return (str);
}

void CUart::UartRxISR()
{
	rxBuffer[rxBufferBegin] = UDR;
	rxBufferBegin++;
	if (rxBufferBegin >= RX_BUFFER_SIZE)	{
		rxBufferBegin = 0;
	}
	if (rxBufferBegin == rxBufferEnd)	{
		newLine();
		print("Error. RX buffer overflow.");
	}
};








