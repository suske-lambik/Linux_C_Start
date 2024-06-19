/*
 * asciiTable.c
 *
 *  Created on: Dec 2, 2017
 *      Author: philippe
 */
#include <stdio.h>

int main()
{
	//print complete ASCII table by type conversion, 0->128
	for (int i=255; i<384; ++i){
		printf("%d == %c == %d == %c\n", i, (char) i, i%256, (char) i%256);
	}
}

