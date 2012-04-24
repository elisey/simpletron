/*
 * CInterpretator.cpp
 *
 * Created: 24.04.2012 17:58:17
 *  Author: Krot
 */ 
#include "CInterpretator.h"
#include "config.h"
extern CUart Terminal;

const char *commands[] = 	{"READ","WRTE","LOAD","STRE","ADDT","SUBS","DIVI","MULT","JUMP","BRNE","BRPO","BRZE","HALT"};

void CInterpretator::editProgramm()
{
	uint16_t editorLine = 0;
	char currentCommand[9];
	uint8_t index = 0;
	Terminal.printF(PSTR("Симплетрон 1.0.0.\r\n"));
	Terminal.printF(PSTR("Редактирование программы.\r\n"));
	Terminal.printF(PSTR("ESC - Запустить, TAB - строка вверх, Enter - Страка вниз.\r\n"));
	Terminal.printF(PSTR("-------------------------------------\r\n"));
	uint8_t data;
	data = Terminal.getChar();
	switch (data)
	{
		case KEY_ENTER:
			Terminal.printChar(KEY_ENTER);
			if (editorLine <= SIMP_MRY_SIZE)
				editorLine++;
				
			index = 0;
			break;
		case KEY_TAB:
			Terminal.printChar(0x1B);
			Terminal.printChar(0x5B);
			Terminal.printChar(0x41);
			if (editorLine != 0)
				editorLine--;
			index = 0;	
			break;
		case KEY_ESC:
			//Компилирование и запус
			break;
			
		case KEY_BACKSPASE:
			
			break;
		default:
			
			break;
	}
}

 CInterpretator::CInterpretator()
{
	
}
