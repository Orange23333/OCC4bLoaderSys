//OCC4B binary 4 bit operations
#ifndef __OCCBIN4B_H
	#define __OCCBIN4B_H

	#include "occtype.h"
	#include "occbasic.h"

Byte SafeReadCode(ReadonlyCodeArray codeArray, const Address codeArraySize, const Address target) {
	if (target < codeArraySize) {
		return codeArray[target];
	}
	else {
	#ifdef SHOW_ERROR
		printf("[Error]SafeReadCode: Over index, read 0x%X in a 0x%X(max) code array.\n", target, codeArraySize);
	#endif
		Exit(target);
	}
}

void CheckBlockEnd(ReadonlyCodeArray codeArray, const Address checkAddress) {
	if (codeArray[checkAddress] != NOPE) {
	#ifdef SHOW_ERROR
		printf("[Error]CheckBlockEnd: Here(0x%X) should be NOPE.\n", checkAddress);
	#endif
		Exit(checkAddress);
	}
}

void OverEmptyBlock(ReadonlyCodeArray codeArray, Address* const pointer) {
	while (codeArray[*pointer] == NOPE) {
		(*pointer)++;
	}
}

#endif