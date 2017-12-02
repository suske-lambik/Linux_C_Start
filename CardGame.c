/*
 * CardGame.c
 *
 *  Created on: Dec 2, 2017
 *      Author: philippe
 */
#include <stdio.h>
#include <string.h>

enum CardType {HEARTS = 0, CLUBS, DIAMONDS, SPADES, N_TYPES};
enum CardValue {ONE = 0, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, \
	JACK, QUEEN, KING, N_VALUES};
/*
 * Function to change enum to string value
 * to return string:
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

struct Card handACard(){
	//feed random generator
	//
	int random = 3;
	struct Card randomCard;
	randomCard.Type = (enum CardType) random;
	randomCard.Value = (enum CardValue) random;
	return randomCard;
}

int main()
{
	//
	printf("Hand a random card. \n");
	struct Card rCard = handACard();
	printf("Type: %d, Value: %d", rCard.Type, rCard.Value);
	printf("Type: %s, Value: %s", strCardType(rCard.Type), strCardValue(rCard.Value));
}


