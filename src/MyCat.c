#include <stdio.h>
#include <string.h> //strcpy

#define BUFFERSIZE_IN 10
#define BUFFERSIZE 10
#define READ_TIMES 20000

int main() 
{
    puts("Enter a file to read:");
    char buff[BUFFERSIZE_IN] = "";
    fgets(buff, BUFFERSIZE_IN, stdin);
    //TODO: sanity check
    char fileName [BUFFERSIZE_IN];
    sscanf(buff, "%s", fileName);
    printf("The file is: %s|", fileName);
    FILE * fs = fopen(fileName, "r");
    //~ FILE * fs = fopen("test.c", "r");
    printf("filestream: %p\n", (void*) fs);
    if (fs == NULL){
        printf("file does not exist!");
        return 1;
    }
    
    printf("Reading %s:\n", fileName);
    char readBuff[BUFFERSIZE*READ_TIMES+1] = "";
    size_t rc = fread(readBuff, BUFFERSIZE, READ_TIMES, fs);
    printf("rc: %d\n", (unsigned int) rc);
    printf("%s", readBuff);
    //~ while (fread(readBuff, BUFFERSIZE-1, READ_TIMES, fs) == READ_TIMES) {
        //~ printf("\n========\n");
        //~ printf("%s", readBuff);
    //~ }
    printf("\n");
    
    fs = fopen("/tmp/null", "w");
    char hello [] = "Hello World!";
    rc = fwrite(hello, 10,2, fs);
    
    
    return 0;
}
