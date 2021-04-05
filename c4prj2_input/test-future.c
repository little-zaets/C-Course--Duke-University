#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "future.h"

int main()
{
	size_t i;
	card_t c1 = {VALUE_ACE, CLUBS};
	card_t c2 = {VALUE_ACE, DIAMONDS};
	card_t c3 = {VALUE_ACE, HEARTS};
	card_t c4 = {VALUE_KING, CLUBS};
	/*card_t c5 = {VALUE_KING, DIAMONDS};
	card_t c6 = {VALUE_KING, SPADES};
	card_t c7 = {VALUE_QUEEN, DIAMONDS};

	card_t c8 = {VALUE_QUEEN, HEARTS};
	card_t c9 = {VALUE_QUEEN, SPADES};
	card_t c10 = {10, DIAMONDS};
	card_t c11 = {10, SPADES};*/
	/*card_t c12 = {9, CLUBS};
	card_t c13 = {9, HEARTS};
	card_t c14 = {5, DIAMONDS};*/

	card_t *cards1[] = {&c1, &c2, &c3, &c4};
	deck_t *hand1 = create_deck();
//	card_t *cards2[] = {&c8, &c9, &c10, &c11};
	for (i = 0; i < 4; ++i)
	{
		add_card_to(hand1, *cards1[i]);
	}
	deck_t *deck = make_deck_exclude(hand1);
	while (i < 6)
	{
		add_empty_card(hand1);
		++i;
	}
	
	shuffle(deck);
	future_cards_t *unknowns = create_unknowns();
	card_t *card_ptr = hand1->cards[hand1->n_cards - 2];

	for (i = 0; i < 2; ++i)
	{
		add_future_card(unknowns, i, card_ptr);
		card_ptr++; 
	}
	future_cards_from_deck(deck, unknowns);
	deck_t **hands = malloc(sizeof(**hands) * 3);
	hands[0] = hand1;
	hands[1] = unknowns->decks;
	deck = build_remaining_deck(hands, 2);
	printf("unknown->decks: \n");
	print_hand(unknowns->decks);
	printf("\n");
	printf("hand1: \n");
	print_hand(hand1);
	printf("\n");
	printf("remaining deck: \n");
	print_hand(deck);
	printf("\n");

	return 0;	
}