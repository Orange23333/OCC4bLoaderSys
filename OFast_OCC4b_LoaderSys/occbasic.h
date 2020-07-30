//OCC4B basic functions
#ifndef __OCCBASIC_H
	#define __OCCBASIC_H

	#include <stdio.h>
	#include <stdlib.h>

void Exit(const int exitCode) {
	#ifdef SHOW_INFO
	printf("[Info]Exit: Exited with code %d.\n", exitCode);
	#endif
	#ifdef KEEP_BEFORE_EXIT
	getchar();
	#endif
	//ShowExitCode(exitCode);
	exit(exitCode);
}

#endif