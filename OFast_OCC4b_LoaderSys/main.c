//OFastOCC4bLoaderSys.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OOC_ADDRESS_INT
//#define OOC_ADDRESS_LLONG
#define SHOW_DEBUG
#define SHOW_INFO
#define SHOW_WARN
#define SHOW_ERROR
#define KEEP_BEFORE_EXIT
#include "ctrlv.h"
#include "occbin4b.h"

#define ALLMEMSZ 265 //All memory size
Byte memory[ALLMEMSZ];
const Byte B4B[] = {
	GOTO, 0,0,0,0x0C,NOPE,
	GOTO, 0,0,0,0x00,NOPE,
	GOTO, 0,0,0,0x06,NOPE
};//Bin4Bit

void CleanMemory();
void Init();
void CheckB4B();
int Run();

int main() {
	int r = 0;
	Init();
	CheckB4B();
	r = Run();

	Exit(r);
	return r;
}

void CleanMemory() {
	memset(memory, 0, ALLMEMSZ * sizeof(Byte));
}

void Init() {
#ifdef SHOW_INFO
	printf("[Info]Init: Initialising the OFast OurCoreCode_4bit loader system...\n");
#endif
	CleanMemory();
#ifdef SHOW_INFO
	printf("[Info]Init: Initialised.\n");
#endif
}

void CheckB4B() {
#ifdef SHOW_INFO
	printf("[Info]CheckB4B: Checking Bin 4bit...\n");
#endif
	;//Check block is completed;
	;//Has EXIT and end;
	;//GOTO not out of index and at right address;
	;//The frame has meaning.
#ifdef SHOW_INFO
	printf("[Info]CheckB4B: Checked.\n");
#endif
}

Address npt;//now pointer
int Run() {
	unsigned char frame;
	Address tempAddress;

	npt = 0;
	for (;;) {
#ifdef SHOW_DEBUG
		printf("[Debug]Run: Load command head at 0x%X: ", npt);
#endif
		frame = B4B[npt];
#ifdef SHOW_DEBUG
		printf("Head frame = 0x%X.\n", frame);
#endif

		switch (frame)
		{
		case NOPE:
			npt++;
			break;
		case RESET:
			CheckBlockEnd(B4B, ++npt);
			CleanMemory();
			npt = 0;
		case GOTO:
			tempAddress = ReadAddress(B4B, ++npt);
			CheckBlockEnd(B4B, npt + sizeof(Address));
			npt = tempAddress;
#ifdef SHOW_DEBUG
			printf("[Debug]Run: Goto 0x%X.\n", tempAddress);
#endif
			break;
		default:
#ifdef SHOW_ERROR
			printf("[Error]Run: B4B error at frame %d, unknown meaning.\n", npt);
#endif
			Exit(npt);
		}
#ifdef SHOW_DEBUG
		printf("[Debug]Run: Finished a block.\n");
		getchar();
		printf("[Debug]Run: End and next.\n");
#endif
	}
}