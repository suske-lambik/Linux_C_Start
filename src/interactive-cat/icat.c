#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#define BUFFERSIZE 50


int cat(FILE* fd)
{
	char buffer[BUFFERSIZE];
	size_t bytes = fread(buffer, sizeof(char), BUFFERSIZE, fd);
	
	while(bytes > 0){
		fwrite(buffer, sizeof(char), bytes, stdout);
		bytes = fread(buffer, sizeof(char), BUFFERSIZE, fd);
	}

	fputs("\nEOF\n", stdout);
	return 0;
}


int main(void)
{
	char buffer[BUFFERSIZE]="";
	FILE* fd;

	while(true)
	{
		printf("\nWhich file should I cat?\n");
		char* bytes = fgets(buffer, BUFFERSIZE, stdin);
		if(bytes == NULL)
		{
			printf("Entered 0 bytes\n");
			continue;
		}
		
		char *pos;
		if ((pos=strchr(buffer, '\n')) != NULL){
		    *pos = '\0';
		}
		else{
		    printf("input too long to be read!\n");
			continue;
		}

		fd = fopen(buffer, "r");
		if(fd == NULL)
		{
			printf("The file %s couldn't be opened.\n", buffer);
			continue;
		}
		printf("Will print contents of %s\n", buffer);
		cat(fd);
	}
	return 0;
}