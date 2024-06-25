#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#define BUFFERSIZE 50


int cat(FILE* fd, size_t buffsize)
{
	struct timeval tval_before, tval_after, tval_result;
	gettimeofday(&tval_before, NULL);

	char buffer[buffsize];
	size_t bytes = fread(buffer, sizeof(char), buffsize, fd);

	while(bytes > 0){
		fwrite(buffer, sizeof(char), bytes, stdout);
		bytes = fread(buffer, sizeof(char), buffsize, fd);
	}

	printf("\nEOF\n");

	gettimeofday(&tval_after, NULL);
	timersub(&tval_after, &tval_before, &tval_result);
	printf("Time elapsed: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
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
		cat(fd, 100);
	}
	return 0;
}