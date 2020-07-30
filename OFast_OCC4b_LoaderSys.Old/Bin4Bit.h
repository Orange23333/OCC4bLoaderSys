#ifndef __Bin4Bit_h
	#define __Bin4Bit_h
	
	#include "Data.h"

inline Byte SafeReadCode(ReadonlyCodeArray codeArray, const int codeArraySize, const Address targetAddress);
void CheckBlockEnd(ReadonlyCodeArray codeArray, const Address endAddress);
void OverEmptyBlock(ReadonlyCodeArray codeArray, const Address *pointer);
#endif
