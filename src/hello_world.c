#include <stdio.h>

#define BUFFERSIZE 10

int main(void)
{
    puts("Please give me some text");
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    printf("The number is %s \n", buffer);
   return 0;
}

