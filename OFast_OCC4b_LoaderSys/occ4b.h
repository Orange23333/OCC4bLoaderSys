//OCC4B Words
#ifndef __OCC4B_H
	#define __OCC4B_H

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
	#define	VALUE		0x0 //  0XXX
	#define	VAR			0x8 //4 1XXX
	#define	SIGNED		0x0 //  X000
	#define	UNSIGNED	0x4 //  X100
	#define	BYTE		0x0 //1 X000
	#define	SINT		0x1 //2 X001
	#define	LINT		0x2 //4 X010
	#define	FLOAT		0x3 //4 X011
	#define	DOUBLE		0x7 //4 X111
//	#define	BYTE		0x9 //1 X000
//	#define	SINT		0xA //2 X001
//	#define	LINT		0xB //4 X010
//	#define	LLONG		0xC //8 X011
//	#define	FLOAT		0xD //4 X101
//	#define	DOUBLE		0xE //8 X110

	//CAL1: VBlock a|Operation op|VBlock b|Address r
	#define	ADD			0x0 //Addition:			r=a+b
	#define	SUB			0x1 //Subtraction:		r=a-b
	#define	MULT		0x2 //Multiplication:	r=a*b
	#define	DIV			0x3 //Division:			r=a/b
	#define	AND			0x4 //AND:				r=a&b
	#define	OR			0x5 //OR:				r=a|b
	#define	XOR			0x6 //XOR:				r=a^b
	#define	MOD			0x7 //Modeling:			r=a%b
	#define	MOVL		0x8 //Left shift:		r=a<<b
	#define	MOVR		0x9 //Right shift:		r=a>>b
	#define	MAX			0xA //Max:				r=max(a,b)
	#define	MIN			0xB //Min:				r=min(a,b)
	#define	POW			0xC //Power:			r=pow(a,b)
	#define	ROT			0xD //Roots:			r=pow(a,1/b)
	#define	LOG			0xE //Logarithm:		r=log(a,b)
//	#define	.			0xF //.

	//CAL2: Address a|Operation op
	#define SPLUS		0x0 //Self plus:	a++
	#define SMINUS		0x1 //Self minus	a--
	#define SNOT		0x2 //Self NOT:		a=!a
	#define SREV		0x3 //Self Reverse:	a=~a
//	#define .			0x4 //.
//	#define .			0x5 //.
//	#define .			0x6 //.
//	#define .			0x7 //.
//	#define .			0x8 //.
//	#define .			0x9 //.
//	#define .			0xA //.
//	#define .			0xB //.
//	#define .			0xC //.
//	#define .			0xD //.
//	#define .			0xE //.
//	#define .			0xF //.

	//CAL3: VBlock a|Operation op|Address r
	#define SIN			0x0 //Sine:					r=sin(a)
	#define COS			0x1 //Cosine:				r=cos(a)
	#define TAN			0x2 //Tangent:				r=tan(a)
	#define COT			0x3 //Cotangent:			r=cot(a)
	#define ASIN		0x4 //Arcsine:				r=asin(a)
	#define ACOS		0x5 //ArcCosine:			r=acos(a)
	#define ATAN		0x6 //Arctangent:			r=atan(a)
	#define ACOT		0x7 //ArcCotangent			r=acot(a)
	#define LG			0x8 //Commmon logarithm:	r=lg(a)
	#define LN			0x9 //Natural logarithm:	r=ln(a)
	#define TIME2		0xA //Times 2:				r=a<<1
	#define SQRT		0xB //Square root:			r=sqrt(a)
	#define FACT		0xC //Factorial:			r=a!
	#define REV			0xD //Reverse:				r=~a
	#define NOT			0xE //NOT:					r=!a
//	#define .			0xF //.

	//CAL4: Address a|Operation op|VBlock b
	#define ADDE		0x0 //Addition and evaluation:			a+=b
	#define SUBE		0x1 //Subtraction and evaluation:		a-=b
	#define MULTE		0x2 //Multiplication and evaluation:	a*=b
	#define DIVE		0x3 //Division and evaluation:			a/=b
	#define ANDE		0x4 //AND per bit and evaluation:		a&=b
	#define ORE			0x5 //OR per bit and evaluation:		a|=b
	#define XORE		0x6 //XOR per bit and evaluation:		a^=b
	#define MODE		0x7 //Modeling and evaluation:			a%=b
	#define MOVLE		0x8 //Left shift and evaluation:		a<<=b
	#define MOVRE		0x9 //Right shift and evaluation:		a>>=b
	#define MAXE		0xA //Get max with self and evaluation:	a=max(a,b)
	#define MINE		0xB //Get min with self and evaluation:	a=min(a,b)
//	#define POWE		0xC //Power and evaluation:				a=pow(a,b)
//	#define ROTE		0xD //Roots and evaluation:				a=pow(a,1/b)
//	#define LOGE		0xE //Logarithm and evaluation:			a=log(a,b)
//	#define .			0xF //.

	//BOOL: VBlock a|Operation op|VBlock b|Address r
	#define LAND		0x0 //Logic AND:			r=a&&b
	#define LOR			0x1 //Logic OR:				r=a||b
	#define EQU			0x2 //Equals:				r=a==b
	#define NEQ			0x3 //Not equals:			r=a!=b
	#define LSS			0x4 //Less:					r=a<b
	#define LEQ			0x5 //Less or equals:		r=a<=b
	#define GTR			0x6 //Greater:				r=a>b
	#define GEQ			0x7 //Greater or equals:	r=a>=b
	#define AS			0x8 //As:					r=typeof(a)==typeof(b)
//	#define .			0x9 //.
//	#define .			0xA //.
//	#define .			0xB //.
//	#define .			0xC //.
//	#define .			0xD //.
//	#define .			0xE //.
//	#define .			0xF //.

#endif