#include <stdio.h>


int main(void)
{

	for(int i = 0; i < 64; i++){
		printf("| %i = %02c |", i, i);
		printf(" %i = %02c |", 64 + i, 64 + i);
		printf("\n");
	}
}