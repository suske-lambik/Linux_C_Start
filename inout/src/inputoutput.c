#include <stdio.h>
#define BUFFER_SIZE 10

int main(void)
{
	int number;
	
	puts("Please provide some text:");
	char buffer[BUFFER_SIZE];
	fgets(buffer, BUFFER_SIZE, stdin);
	printf("The number is %s !\n", buffer);
}

