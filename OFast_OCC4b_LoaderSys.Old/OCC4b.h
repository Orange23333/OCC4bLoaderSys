#ifndef __OCC4b_h
	#define __OCC4b_h
	
	//MAIN
	#define NOPE		0x0
	#define RESET		0x1
	#define GOTO		0x2
	#define SET			0x3
	#define UPDATE		0x4
	#define CAL1		0x5
	#define CAL2		0x6
	#define CAL3		0x7
	#define CAL4		0x8
	#define BOOL		0x9
	#define IF			0xA
	#define IFELSE		0xB
	#define SWAP		0xC
	#define DELAY		0xD
	#define MEMSET		0xE
	#define EXIT		0xF
	
	//TYPE 
	#define VALUE		0x0
	#define VAR			0x8
	#define SIGNED		0x0
	#define UNSIGNED	0x4
	#define BYTE		0x0
	#define INT			0x1
	#define LONG		0x2
	#define FLOAT		0x3
	#define DOUBLE		0x7
	
	//CAL1: ValueBlock a|Byte operation|ValueBlock b|Address c
	#define ADD			0x0// c=a+b
	#define SUB			0x1// c=a-b
	#define MULT		0x2// c=a*b
	#define DIV			0x3// c=a/b
	#define AND			0x4// c=a&b
	#define OR			0x5// c=a|b
	#define XOR			0x6// c=a^b
	#define MOD			0x7// c=a%b
	#define MOVL		0x8// c=a<<b
	#define MOVR		0x9// c=a>>b
	#define MAX			0xA// c=max(a,b)
	#define MIN			0xB// c=min(a,b)
	#define POW			0xC// c=pow(a,b)
	#define NPOW		0xD// c=pow(a,1/b)
//	#define LOG			0xE// c=log(a,b)
//	#define .			0xF// .
	
	//CAL2: Address a|Byte operation|
	#define PLUS		0x0// a++
	#define MINUS		0x1// a--
	#define NOT			0x2// a=!a
	#define REV			0x3// a=~a
//	#define .			0x4// .
//	#define .			0x5// .
//	#define .			0x6// .
//	#define .			0x7// .
//	#define .			0x8// .
//	#define .			0x9// .
//	#define .			0xA// .
//	#define .			0xB// .
//	#define .			0xC// .
//	#define .			0xD// .
//	#define .			0xE// .
//	#define .			0xF// .
	
	//CAL3: ValueBlock a|Byte operation|Address c
	#define SIN			0x0// c=sin(a)
	#define COS			0x1// c=cos(a)
	#define TAN			0x2// c=tan(a)
//	#define COT			0x3// c=cot(a)
	#define ASIN		0x4// c=asin(a)
	#define ACOS		0x5// c=acos(a)
	#define ATAN		0x6// c=atan(a)
//	#define ACOT		0x7// c=acot(a)
	#define LG			0x8// c=log10(a)
	#define LN			0x9// c=log(a)
	#define MULT2		0xA// c=a<<1
	#define SQRT		0xB// c=sqrt(a)
	#define FACT		0xC// c=a!
	#define REV			0xD// c=~a
	#define NOT			0xE// c=!a
//	#define .			0xF// .
	
	//CAL4: Address a|Byte operation|ValueBlock b|
	#define ADD			0x0// b+=a
	#define SUB			0x1// b-=a
	#define MULT		0x2// b*=a
	#define DIV			0x3// b/=a
	#define AND			0x4// b&=a
	#define OR			0x5// b|=a
	#define XOR			0x6// b^=a
	#define MOD			0x7// b%=a
	#define MOVL		0x8// b<<=a
	#define MOVR		0x9// b>>=a
	#define MAX			0xA// b=max(b,a)
	#define MIN			0xB// b=min(b,a)
//	#define POW			0xC// b=pow(b,a)
//	#define NPOW		0xD// b=pow(b,1/a)
//	#define LOG			0xE// b=log(b,a)
//	#define .			0xF// .
	
	//BOOL: ValueBlock a|Byte operation|ValueBlock b|Address c
	#define AND			0x0// c=a&&b
	#define OR			0x1// c=a||b
	#define EQU			0x2// c=a==b
	#define NEQ			0x3// c=a!=b
	#define LSS			0x4// c=a<b
	#define LEQ			0x5// c=a<=b
	#define GTR			0x6// c=a>b
	#define GEQ			0x7// c=a>=b
	#define AS			0x8// c=a==b
//	#define .			0x9// .
//	#define .			0xA// .
//	#define .			0xB// .
//	#define .			0xC// .
//	#define .			0xD// .
//	#define .			0xE// .
//	#define .			0xF// .
	
#endif
