/*
 * CardGame.c
 *
 *  Created on: Dec 2, 2017
 *      Author: philippe
 */
#include <stdio.h>

enum CardType {HEARTS, CLUBS, DIAMONDS, SPADES};
enum CardValue {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, \
	JACK, QUEEN, KING};

struct Card {
	enum CardType Type;
	enum CardValue Value;
};

struct Card handACard(){
	//feed random generator
	//
	int random = 3;
	struct Card randomCard;
	randomCard.Type = CardType(random);
	randomCard.Value = CardValue(random);
	return randomCard;
}

int main()
{
	//
	printf("Hand a random card. \n");
	struct Card rCard = handACard();
	printf("Type: %d, Value: %d", rCard.Type, rCard.Value);
}


