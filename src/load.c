#include <stdio.h>

#define BUFF_SIZE 10
#define READ_TIMES 2

int main()
{
    // /proc/loadavg layout: a b c d/e f
    // a,b,c: load avg 1,5,15 minutes
    // d vs e: no of executing vs no of planned processes/threads
    // f: PID of last created process
    FILE * fsLoad = fopen("/proc/loadavg", "r");
    char buffer[BUFF_SIZE*READ_TIMES + 1] = {0};
    fread(&buffer, BUFF_SIZE, READ_TIMES, fsLoad);
    float load_1, load_5, load_15;
    char dummy [BUFF_SIZE*READ_TIMES +  1] = {0};
    sscanf(buffer, "%f %f %f %s %s", &load_1, &load_5, &load_15, dummy, dummy);
    printf("load 1: %f\n", load_1);
    printf("load 5: %f\n", load_5);
    printf("load 15: %f\n", load_15);
    printf("remainder: %s\n", dummy);
    
}
