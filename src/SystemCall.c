/*
 * SystemCall.c
 *
 *  Created on: Jan 8, 2018
 *      Author: philippe
 *
 *  Exercise: 	- Write a small shell script to echo hello world.
 *  		Launch it from a C program using system()
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int rc = system("/home/philippe/git/Linux_C_Start/src/hello_world.sh");
	printf("System call was a %s\n", rc?"failure":"succes");
	return 0;
}
