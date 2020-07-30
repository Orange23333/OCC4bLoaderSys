//OCC4B Types
#ifndef __CTRLV_H
	#define __CTRLV_H
#include <stdlib.h>
#include <string.h>

#include "occtype.h"
#include "occbasic.h"

Address ToAddress(const Byte* const buffer) {
	Byte i;
	Address r = 0;

	#ifdef SHOW_DEBUG
	printf("[Debug]ToAddress: ");
	for (i = 0; i < sizeof(Address); i++) {
		printf("0x%02X ", buffer[i]);
	}printf("=>\n");
	#endif
	for (i = 0; i < sizeof(Address); i++) {
		r <<= 8;
		r += buffer[i];
	#ifdef SHOW_DEBUG
		printf("\t%d: 0x%08X\n", i, r);
	#endif
	}

	return r;
}

VBlock ReadVBlock(const Byte* const buffer, Address bufferSize, Address offset) {
	Byte i, n;
	VBlock r;
	Byte* target;
	
	target = buufer + offset;

	r.type = buffer[vBlockAddress];
	n = GetTypeSize(r.type);
	if (n == 0) {
	#ifdef SHOW_ERROR
		printf("[Error]ReadVBlock: Error at frame %d, unknown type.\n", vBlockAddress);
	#endif
		Exit(vBlockAddress);
	}
	r.data=(Byte*)calloc(1,n);
	temp = GetVBlockAddress(codeArray, r.type, vBlockAddress + sizeof(Type));

	if((r.type&TVPART)==VALUE){
		for (i = 0; i < n; i++) {
			r.data[i] = codeArray[temp + n - i - 1];
		}
	}else{
		if(memory==NULL){
			for (i = 0; i < n; i++) {
				r.data[i] = *(((Byte*)temp) + n - i - 1);
			}
		}else{
			for (i = 0; i < n; i++) {
				r.data[i] = memory[temp + n - i - 1];
			}
		}
	}

	return r;
}

void WriteVBlobk(ReadonlyCodeArray codeArray, const VBlock vBlock, const Address target) {
	Byte n;
	Address temp;
	
	n = GetTypeSize(vBlock.type);
	if (n == 0) {
	#ifdef SHOW_ERROR
		printf("[Error]WriteVBlock: vBlock has an unknown type.\n");
	#endif
		Exit(n);
	}
	temp = GetVBlockAddress(codeArray, vBlock.type, target + sizeof(Type));
}

Address GetVBlockAddress(ReadonlyCodeArray codeArray, const Type type, const Address vBlockDataAddress) {
	if ((type & TVPART) == VAR) {
		//VAR
		return ReadAddress(codeArray, vBlockDataAddress);//ReadAddress
	}
	else {
		//VALUE
		return vBlockDataAddress;
	}
}

Address ReadAddress(ReadonlyCodeArray codeArray, const Address position) {
	Byte i;
	Byte buffer[sizeof(Address)];

	for (i = 0; i < sizeof(Address); i++) {
		buffer[i] = codeArray[position + sizeof(Address) - i - 1];
	}

	return *((Address*)buffer);
}

#endif