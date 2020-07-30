#include "OCC4b.h"
#include "Data.h"
#include "BasicFunction.h"

inline Byte SafeReadCode(ReadonlyCodeArray codeArray, const int codeArraySize, const Address targetAddress){
	if(targetAddress<codeArraySize){
		return codeArray[targetAddress];
	}else{
		printf("SafeReadCode: Over index, read 0x%X in a 0x%X(max) code array.\n",targetAddress,codeArraySize);
		Exit(targetAddress/(sizeof(Address)/sizeof(int)));
	}
}

//检查一段代码块的结尾（结尾必须为NOPE） 
void CheckBlockEnd(ReadonlyCodeArray codeArray, const Address endAddress){
	if(codeArray[endAddress]!=NOPE){
		printf("CheckBlockEnd: here(0x%X) should be EMPTY.\n",endAddress);
		Exit(endAddress/(sizeof(Address)/sizeof(int)));
	}
}

void OverEmptyBlock(ReadonlyCodeArray codeArray, Address * const pointer){
	while(codeArray[*pointer]==NOPE){
		(*pointer)++;
	}
}
