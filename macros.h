#ifndef MACROS_H
#define MACROS_H

#define setBit(x,y)   	   (x |= 1<<y)
#define clearBit(x,y) 	   (x &= ~(1<<y))
#define invertBit(x,y)		(x ^= 1<<y)
#define checkBit(x,y) 	   (x & 1<<y)

#endif
