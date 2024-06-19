#include <stdio.h>
#include <string.h>
#include <argp.h>


struct arguments
{
	char *password;
};

static struct argp_option options[] = 
{
	{"password", 'p', "PASSWORD", 0, "Don't prompt interactively for the password"},
	{0}
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	struct arguments *arguments = state->input;

	switch (key)
	{
	case 'p':
		arguments->password = arg;
		break;
	case ARGP_KEY_ARG:
		argp_usage(state);
		break;
	case ARGP_KEY_END:
		break;
	default:
		return ARGP_ERR_UNKNOWN;
	}
	return 0;
}


static char args_doc[] = "";
static char doc[] = "bufferoverflow - A program to demonstrate how to execute bufferoverflow errors. \
And how to parse arguments using argp.";

static struct argp argp = {options, parse_opt, args_doc, doc};


int main(int argc, char *argv[])
{
	struct arguments arguments;
	arguments.password = "";
	argp_parse(&argp, argc, argv, 0, 0, &arguments);
	

	if(strcmp(arguments.password, "") == 0){
		char pwd[38];
		printf("Please enter your password:\n");
		gets(pwd);
		arguments.password = pwd;
	}

	if(strcmp(arguments.password, "secret") == 0){
		printf("Access granted\n");
		return 0;
	}

	printf("Wrong\n");
	return 1;
}