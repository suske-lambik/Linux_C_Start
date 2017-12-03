/*
 * CardGame.c
 *
 *  Created on: Dec 2, 2017
 *      Author: philippe
 */
#include <stdio.h>
#include <stdlib.h> //rand()
#include <time.h> //time()
#include <string.h>

#define _unsafe_sscanf sscanf
#include "poison.h" //bad functions

enum CardType {HEARTS = 0, CLUBS, DIAMONDS, SPADES, N_TYPES};
enum CardValue {ONE = 0, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, \
	JACK, QUEEN, KING, N_VALUES};
/*
 * Function to change enum to string value
 * possible options to return a string from a function:
 * 	- allocate on stack at client side
 * 	- pointer to string literal (pointer to const char: const char * ...)
 * 	- allocate on heap at server side
 * 	- allocate as static at server side
 * use switch case, to ensure all enum values are handled.
 */
const char * strCardType(enum CardType type)
{
	switch (type)
	{
	case HEARTS: return "HEARTS";
	case CLUBS: return "CLUBS";
	case DIAMONDS: return "DIAMONDS";
	case SPADES: return "SPADES";
	case N_TYPES: return "NO_TYPE";
	}
	return "NO_TYPE";
}

const char * strCardValue(enum CardValue value)
{
	switch (value)
	{
	case ONE: return "ONE";
	case TWO: return "TWO";
	case THREE: return "THREE";
	case FOUR: return "FOUR";
	case FIVE: return "FIVE";
	case SIX: return "SIX";
	case SEVEN: return "SEVEN";
	case EIGHT: return "EIGHT";
	case NINE: return "NINE";
	case TEN: return "TEN";
	case JACK: return "JACK";
	case QUEEN: return "QUEEN";
	case KING: return "KING";
	case N_VALUES: return "NO_VALUE";
	}
	return "NO_VALUE";
}

struct Card {
	enum CardType Type;
	enum CardValue Value;
};

struct Card handRandomCard(enum CardType type, enum CardValue value)
{
	time_t seed;
	int randIdx;
	struct Card randomCard;
	srand((unsigned)time(&seed));
	if (type >= N_TYPES){
		randIdx = rand() % N_TYPES;
		randomCard.Type = (enum CardType) randIdx;
	} else {
		randomCard.Type = type;
	}
	if (value >= N_VALUES){
		randIdx = rand() % N_VALUES;
		randomCard.Value = (enum CardValue) randIdx;
	} else {
		randomCard.Value = value;
	}
	return randomCard;
}

int main()
{
	printf("Hand a random card. \n");
	printf("Which type do you want?\n");
	//inputs parsing: fgets + sscanf for the win!!
	char buf[3];
	int type;
	fgets(buf, 3, stdin);
	_unsafe_sscanf(buf, "%d", &type);
	struct Card rCard = handRandomCard((enum CardType) type, N_VALUES);
	printf("Type: %d, Value: %d\n", rCard.Type, rCard.Value);
	printf("Type: %s, Value: %s\n", strCardType(rCard.Type), strCardValue(rCard.Value));
}


