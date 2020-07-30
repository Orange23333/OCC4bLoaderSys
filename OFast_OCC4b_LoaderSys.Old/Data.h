#ifndef __Data_h
	#define __Data_h
	
	#define MAX_DATA_SIZE 8
	
	typedef unsigned char Byte;
	typedef const Byte* const ReadonlyCodeArray;
	typedef unsigned char Type;
	typedef unsigned long long Address;
	
	typedef struct{
		Type type;
		Byte data[MAX_DATA_SIZE];
	}ValueBlock;//ValueBlock
	/*
	typedef struct{
		unsigned char type;
		unsigned char data[MAX_DATA_SIZE];
	}Val;//Value
	*/
	typedef struct{
		Type type;
		Address address;
	}Var;//Variable
	
	Address ArrayToAddress(Byte *buffer);
	Address GetValueBlockAddress(const Byte type, const Byte *codeArray, const Address beginAddress);
	Byte GetValueBlockSize(const Byte type);
	Address ReadAddress(const Byte *codeArray, const Address beginAddress);
	
#endif
