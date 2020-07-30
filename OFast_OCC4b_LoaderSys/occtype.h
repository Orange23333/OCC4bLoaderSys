//OCC4B Types
#ifndef __OCCTYPE_H
	#define __OCCTYPE_H

	#include "occ4b.h"

	#define TVPART 0x8 //Type var/value flag part
	#define TTPART 0x7 //Type type part

typedef long long			DLONG;
typedef unsigned char		HByte;
typedef unsigned char		Byte;
typedef unsigned short		Byte2;
typedef unsigned int		Byte4;
typedef unsigned long long	Byte8;

typedef Byte				Type;
	
	#ifdef OOC_ADDRESS_INT
		#ifdef OOC_ADDRESS_LLONG
			#error "OOC_ADDRESS_INT and OOC_ADDRESS_LLONG mutually exclusive."
		#endif
typedef int					Address;
	#endif
	#ifndef OOC_ADDRESS_INT
		#ifndef OOC_ADDRESS_LLONG
			#define OOC_ADDRESS_INT
		#endif
	#endif
	#ifdef OOC_ADDRESS_LLONG
typedef long long			Address;
	#endif
typedef HByte				Operation;
typedef Byte*				CodeArray;
typedef const Byte* const	ReadonlyCodeArray;

/// <summary>
/// 兼容常量和变量的逻辑区块。
/// </summary>
struct _VBlock
{
	Type type;
	Byte* data;
};
/// <summary>
/// 变量逻辑区块。
/// </summary>
struct _Var
{
	Type type;
	Address address;
};
/// <summary>
/// 常量逻辑区块。
/// </summary>
struct _Value
{
	Type type;
	Byte* data;
};
typedef struct _VBlock	VBlock;
typedef struct _Var		Var;
typedef struct _Value	Value;

Byte GetTypeSize(const Type type) {
	if ((type & TVPART) == VALUE) {
		//VALUE
		switch (type & TTPART) {
		case BYTE:
		case UNSIGNED|BYTE:
			return sizeof(char);
		case SINT:
		case UNSIGNED|SINT:
			return sizeof(short);
		case LINT:
		case UNSIGNED|LINT:
			return sizeof(int);
		case FLOAT:
			return sizeof(float);
		case DOUBLE:
			return sizeof(double);
		default:
			return 0;
		}
	}
	else {
		//VAR
		return sizeof(Address);
	}
}

#endif