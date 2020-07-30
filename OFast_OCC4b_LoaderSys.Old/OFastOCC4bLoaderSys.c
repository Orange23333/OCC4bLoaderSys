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

Address npt;//当前的指针now pointer
int Run(){
	unsigned char frame;
	Address tempAdrs;
	
	//初始化指针位置（非必要操作） 
	npt=0; 
	while(1){
		printf("Load command head at 0x%X: ",npt);//DEBUG
		//读取一个帧 
		frame=B4B[npt];
		printf("Head Frame = 0x%X.\n",frame);//DEBUG
		//运行当前帧的指令 
		switch(frame){
			//空程序快 
			case NOPE:
				//移动指针 
				npt++;
				break;
			case RESET:
				//检查代码块尾部 
				CkBlkEd();
				npt=0;
				printf("Reseted."); 
				break;
			case GOTO:
				//移动指针并读取数据区中存放的代码区地址 
				npt++;
				tempAdrs=RdAdrsFH();
				//检查代码块尾部
				CkBlkEd();
				//移动指针到所获得的地址处 
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
