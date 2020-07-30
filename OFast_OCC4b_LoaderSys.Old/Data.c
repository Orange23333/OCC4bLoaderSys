#include "OCC4b.h"
#include "Data.h"
#include "BasicFunction.h"

Address ArrayToAddress(Byte *buffer){
	Byte i;
	Address r=0;
	
#ifdef DEBUG
	printf("ArrayToAddress: 0x")
	for(i=0;i<sizeof(Address);i++){
		printf("%X ",buffer[i]);
	}printf("=>\n");
#endif
	for(i=sizeof(Address)-1;i<sizeof(Address);i--){
		r*=pow(2,8);
		r+=buffer[i];
#ifdef DEBUG
		printf("\t%d: 0x%X\n",i,r);
#endif
	}
	
	return r;
}

ValueBlock ReadValueBlock(const Byte *codeArray, const Address targetAddress){
	Byte i,n;
	ValueBlock r;
	Address temp;
	memset(&r,0,sizeof(r));
	
	r.type=codeArray[targetAddress];
	temp=GetValueBlockAddress(r.type,codeArray,targetAddress+1);
	n=GetTypeSize(r.type);
	if(n==0){
		printf("Error: B4B error at frame %d, unknown type.\n",targetAddress);
		Exit(targetAddress/(sizeof(Address)/sizeof(int)));
	}
	
	for(i=0;i<n;i++){
		r.data[i]=codeArray[temp+i];
	}
	
	return r;
}

Address GetValueBlockAddress(const Byte type, const Byte *codeArray, const Address beginAddress){
	if(type&0x8==VALUE){
		//VALUE
		return ReadAddress(codeArray, beginAddress);
	}else{
		//VAR
		return beginAddress;
	}
}

//不计Type大小
Byte GetValueBlockSize(const Byte type){
	if(type&0x8==VALUE){
		//VALUE
		switch(type&0x7){
			case BYTE:
			case UNSIGNED|BYTE:
				return sizeof(char);
			case INT:
			case UNSIGNED|INT:
				return sizeof(int);
			case LONG:
			case UNSIGNED|LONG:
				return sizeof(long);
			case FLOAT:
				return sizeof(float);
			case DOUBLE:
				return sizeof(double);
			default:
				return 0;
		}
	}else{
		//VAR
		return sizeof(Address);
	}
	
}

Address ReadAddress(const Byte *codeArray, const Address beginAddress){
	Byte i;
	Byte buffer[sizeof(Address)];
	
	for(i=0;i<sizeof(Address);i++){
		buffer[i]=codeArray[beginAddress+i];
	}
	
	return *((Address*)buffer);
}
