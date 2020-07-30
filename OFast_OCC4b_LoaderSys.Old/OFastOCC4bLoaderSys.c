//OFastOCC4bLoaderSys.c
#define DEBUG

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "OCC4b.h"
#include "Data.h"
#include "BasicFunction.h"
#include "Bin4Bit.h"

const unsigned char B4B[]={
	GOTO,6,0,0,0,0,0,0,0,NOPE,
	GOTO,0,0,0,0,0,0,0,0,NOPE
};//Bin4bit

void Init();
void CheckB4B();
int Run();
void Exit(const int exitCode);

int main()
{
	int r;
	
	Init();
	
	CheckB4B();
	
	;
	
	r=Run();
	//Exit(r);
	
	return 0;
}

void Init(){
	printf("Info: Initialising the OFast OurCoreCode_4bit loader system...\n");
	;
	printf("Info: Initialised.\n");
}

void CheckB4B(){
	printf("Info: Checking B4B...\n");
	;//Check block is completed,has EXIT at end,GOTO not out of index and at right way,the frame has meaning.
	//printf("Error: B4B error at code block %d.\n",count);
	printf("Info: Checked.\n");
}

Address npt;//��ǰ��ָ��now pointer
int Run(){
	unsigned char frame;
	Address tempAdrs;
	
	//��ʼ��ָ��λ�ã��Ǳ�Ҫ������ 
	npt=0; 
	while(1){
		printf("Load command head at 0x%X: ",npt);//DEBUG
		//��ȡһ��֡ 
		frame=B4B[npt];
		printf("Head Frame = 0x%X.\n",frame);//DEBUG
		//���е�ǰ֡��ָ�� 
		switch(frame){
			//�ճ���� 
			case NOPE:
				//�ƶ�ָ�� 
				npt++;
				break;
			case RESET:
				//�������β�� 
				CkBlkEd();
				npt=0;
				printf("Reseted."); 
				break;
			case GOTO:
				//�ƶ�ָ�벢��ȡ�������д�ŵĴ�������ַ 
				npt++;
				tempAdrs=RdAdrsFH();
				//�������β��
				CkBlkEd();
				//�ƶ�ָ�뵽����õĵ�ַ�� 
				npt=tempAdrs;
				printf("GOTO 0x%X.\n",tempAdrs);//DEBUG 
				break;
			default:
				printf("Error: B4B error at frame %d, do not has meaning.\n",npt);
				Exit(npt/(sizeof(Address)/sizeof(int)));
		}
		//printf("Finished a block.\n");//DEBUG
		getchar();//DEBUG
		//printf("End and next.\n");//DEBUG
	}
	
	return 0;
}
