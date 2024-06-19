#include <stdint.h>
#include <stdio.h>


enum suite{
	HEARTS,
	DIAMONDS,
	SPADES,
	CLUBS
};


struct card{
	enum suite suite;
	uint8_t number;
};


struct card draw_card()
{
	struct card card;
	card.suite = HEARTS;
	card.number = 5;
	return card;
}


int main(void)
{
	/* 	use enum to define array of cards
		use random function to hand a random card
		add method to check if your color choice matched the card
		add arguments to pass color choice
	*/
	struct card card = draw_card();
	printf("Drew %d.%d\n", card.suite, card.number);
}