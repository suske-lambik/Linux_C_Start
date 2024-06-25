#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 5
/* 
	User: Start program, 
		* choose first/second for each group
		* choose best four thirds
		* choose winner of each knock-out match
		* get the winner	

	Structure:
		* countries are strings
		* groups are arrays
		* knock-outs are arrays
		* every round is also an array composed of groups/knock-outs
		* when user is prompted he needs to enter the array idx of the "winning" team 
*/
char *get_team(char *teams[], uint8_t group_id, uint8_t team_id, uint8_t group_size)
{
	return teams[group_id * group_size + team_id];
}


char *get_group_team(char *teams[], uint8_t group_id, uint8_t team_id)
{
	return get_team(teams, group_id, team_id, 4);
}

char *get_final16_team(char *teams[], uint8_t final_id, uint8_t team_id)
{
	return get_team(teams, final_id, team_id, 2);
}

void print_group(char *teams[], uint8_t group_id)
{
	printf("Group %c: \n", group_id + 65);
	for(int j = 0; j < 4; j++){
		printf("%i. %s ", j, get_group_team(teams, group_id, j));
	}
	printf("\n");
}


void print_final(char *final_teams[], uint8_t final_id)
{
	printf("Final %i: \n", final_id);
	for(int j = 0; j < 2; j++){
		printf("%i. %s ", j, get_final16_team(final_teams, final_id, j));
	}
	printf("\n");
}


uint8_t prompt_first_team(void)
{
	return 2;
}


uint8_t prompt_second_team(void)
{
	return 0;
}


void enter_final16(char *final16[16], uint8_t group_id, char * first, char * second)
{
	switch(group_id){
	case 0:
		final16[2] = first;
		final16[0] = second;
		break;
	case 1:
		final16[6] = first;
		final16[7] = "third A/D/E/F";
		final16[1] = second;
		break;
	case 2:
		final16[4] = first;
		final16[5] = "third D/E/F";
		final16[3] = second;
		break;
	case 3:
		final16[14] = first;
		final16[8] = second;
		break;
	case 4:
		final16[12] = first;
		final16[13] = "third A/B/C/D";
		final16[9] = second;
		break;
	case 5:
		final16[10] = first;
		final16[11] = "third A/B/C";
		final16[15] = second;
		break;
	}
}


int prompt_int(char * question)
{
	char buffer[BUFFERSIZE]="";

    printf(question);
    char* bytes = fgets(buffer, BUFFERSIZE, stdin);
    if(bytes == NULL)
    {
        printf("Entered 0 bytes\n");
        return 99;
    }

    char *pos;
    if ((pos=strchr(buffer, '\n')) != NULL){
        *pos = '\0';
    }

    return (int) strtol(buffer, NULL, 10);
}


int main(void)
{
	char *teams[24] = {"Duitsland", "Zwitserland", "Schotland", "Hongarije",\
	 "Kroatie", "Spanje", "Albanie", "Italie",\
	 "Engeland", "Denemarken", "Slovenie", "Servie",\
	 "Frankrijk", "Nederland", "Oostenrijk", "Polen",\
	 "Belgie", "Slovakije", "Roemenie", "Oekraine",\
	 "Turkije", "Portugal", "f3", "f4"};
	char *final16[16];

	for(int i = 0; i < 6; i++){
		print_group(teams, i);
		uint8_t first = prompt_int("Who will be first?"); //prompt_first_team();
		uint8_t second = prompt_int("Who will be second?");
		printf("%i - %i\n", first, second);
		enter_final16(final16, i, get_group_team(teams, i, first), get_group_team(teams, i, second));
	}
	for(int i = 0; i < 8; i++){
		print_final(final16, i);
	}
	//let user choose

//	int first = 0;
//	int second = 2;
//	final16[1][0] = (*groups[0])[first]
//	final16[0][0] = (*groups[0])[second]
}