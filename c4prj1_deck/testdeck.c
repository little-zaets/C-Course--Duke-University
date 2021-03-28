#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

unsigned *get_match_counts(deck_t *hand);
deck_t *create_deck(void);
/*
void test()
{
	card_t c1 = {VALUE_JACK, CLUBS};
	card_t c2 = {10, SPADES};
	card_t c3 = {9, CLUBS};
	card_t c4 = {8, SPADES};
	card_t c5 = {7, CLUBS};
	card_t c6 = {4, CLUBS};
	card_t c7 = {3, DIAMONDS};

	card_t c8 = {VALUE_JACK, CLUBS};
	card_t c9 = {10, SPADES};
	card_t c10 = {9, CLUBS};
	card_t c11 = {8, SPADES};
	card_t c12 = {7, CLUBS};
	card_t c13 = {6, CLUBS};
	card_t c14 = {5, DIAMONDS};

	card_t *cards1[] = {&c1, &c2};
	card_t *cards2[] = {&c8, &c9};
	deck_t *hand1 = NULL;
	deck_t *hand2 = NULL;
	hand1 = 
	hand2->cards = 
	deck_t **hands = NULL;
	hands[0] = hand1;
	hands[1] = hand2;

	deck_t *deck = build_remaining_deck(hands, 2);
	print_hand(deck);
}*/

int main()
{
	size_t i;
	card_t c1 = {VALUE_JACK, CLUBS};
	card_t c2 = {VALUE_JACK, SPADES};
	card_t c3 = {VALUE_JACK, CLUBS};
	card_t c4 = {10, SPADES};
	card_t c5 = {10, CLUBS};
	card_t c6 = {4, CLUBS};
	card_t c7 = {3, DIAMONDS};

	/*card_t c8 = {VALUE_ACE, HEARTS};
	card_t c9 = {10, CLUBS};
	card_t c10 = {9, HEARTS};
	card_t c11 = {7, SPADES};
	card_t c12 = {7, CLUBS};
	card_t c13 = {6, CLUBS};
	card_t c14 = {5, DIAMONDS};*/

	card_t *cards1[] = {&c1, &c2, &c3, &c4, &c5, &c6, &c7};
	/*card_t *cards2[] = {&c8, &c9, &c10, &c11};*/
	deck_t *hand1 = create_deck();
	/*deck_t *hand2 = create_deck();
	deck_t **hands = malloc(sizeof(**hands));

	hands[0] = hand1;
	hands[1] = hand2;*/
	for (i = 0; i < 7; ++i)
	{
		add_card_to(hand1, *cards1[i]);
		/*add_card_to(hand2, *cards2[i]);*/
	}
	//cards1[i] = add_empty_card(hand1);
	//deck_t *deck = build_remaining_deck(hands, 2);

	printf("hand1: \n");
	print_hand(hand1);
	printf("\n");
	unsigned *match_counts = get_match_counts(hand1);
	for (i = 0; i < hand1->n_cards; ++i)
	{
		printf("%u ", match_counts[i]);
		printf(" ");
	}
	printf("\n");
	/*free_deck(hand1);
	printf("\n");
	printf("hand2: \n");
	print_hand(hand2);
	free_deck(hand2);
	printf("\n");
	printf("deck1: \n");
	print_hand(deck);
	printf("\n");
	free_deck(deck);
	free(hands);*/



	return 0;
}