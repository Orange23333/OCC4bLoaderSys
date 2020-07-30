#include <stdio.h>
#include <stdlib.h>

void Exit(const int exitCode){
#ifdef DEBUG
	printf("Info: Exited with code %d.\n",exitCode);
#endif
	exit(exitCode);//ShowExitCode(exitCode);
}
