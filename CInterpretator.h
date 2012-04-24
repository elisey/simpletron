/*
 * CInterpretator.h
 *
 * Created: 24.04.2012 17:58:26
 *  Author: Krot
 */ 


#ifndef CINTERPRETATOR_H_
#define CINTERPRETATOR_H_

#include "config.h"
#include "Interface.h"

#define SIMP_MRY_SIZE	50

#define KEY_TAB		0x09//вверх на одну строку
#define KEY_ENTER	0x0D//Вниз на одну тсроку
#define KEY_ESC		0x1B//Запуск
#define KEY_BACKSPASE	0x7F

class CInterpretator
{
public:
	CInterpretator();
	void editProgramm();
	uint8_t rumProgramm();
	void memoryDump();
	
private:
	uint16_t memory[SIMP_MRY_SIZE];		//Память программ и данных.
	uint8_t	accumulator;				//Аккумулятор. Пока один.
	uint8_t	operand;					//Операнд. Данные
	uint8_t	curCommand;					//текущая комманда
	uint16_t instructionCounter;		//счетчик комманд
	
	
};



#endif /* CINTERPRETATOR_H_ */