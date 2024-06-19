#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#define BUFSIZE 4
#define HUNDER_MILLISEC 300000
#define LOW_LOAD 0.3
#define NORMAL_LOAD 0.5


enum COLOR{
	RED,
	GREEN,
	BLUE
};


float mygetloadavg(void)
{
	FILE* fd = fopen("/proc/loadavg", "r");
	char buffer[BUFSIZE + 1] = "";

	size_t bytes = fread(buffer, sizeof(char), BUFSIZE, fd);
	if(bytes != BUFSIZE){
		return 666;
	}
	return atof(buffer);
}


enum COLOR loadtocolor(float load)
{
	if (load < LOW_LOAD)
		return GREEN;
	if (load < NORMAL_LOAD)
		return BLUE;
	return RED;
}


void lightupled(enum COLOR color)
{
	switch(color){
	case GREEN:
		printf("GREEN: LOW LOAD\n");
		break;
	case BLUE:
		printf("BLUE: NORMAL LOAD\n");
		break;
	case RED:
		printf("RED: HIGH LOAD\n");
		break;
	}
}


int main(void)
{
	float loadavg = 0.0;
	enum COLOR color = RED;

	while(true){
		loadavg = mygetloadavg();
		color = loadtocolor(loadavg);
		lightupled(color);
		//printf("Current load: %2g\n", loadavg);
		usleep(HUNDER_MILLISEC);
	}
	return 0;
}