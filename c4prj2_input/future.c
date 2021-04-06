#include "future.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

future_cards_t *create_unknowns()
{
	future_cards_t *unknowns = (future_cards_t *)malloc(sizeof(*unknowns));
	assert(unknowns && "malloc failed for future_cards_t *");
	unknowns->decks = create_deck();
	unknowns->n_decks = 0;
	return unknowns;
}

void add_future_card(future_cards_t *fc, size_t index, card_t *ptr)
{
	assert(fc);
	if (fc->n_decks <= index)
	{
		fc->decks = realloc(fc->decks, sizeof(deck_t) * (index + 1));
		assert(fc->decks && "realloc failed for fc->decks");
		memset(fc->decks + fc->n_decks, 0, sizeof(deck_t) * (index + 1 - fc->n_decks));
		fc->n_decks = index + 1;
	}
	fc->decks[index].cards = realloc(fc->decks[index].cards, (fc->decks[index].n_cards + 1) * sizeof(card_t *));
	assert(fc->decks[index].cards && "realloc failed for fc->decks[index].cards");
	//fc->decks[index].cards[fc->decks[index].n_cards] = NULL;
	//fc->decks[index].cards[fc->decks[index].n_cards] = realloc(fc->decks[index].cards[fc->decks[index].n_cards], sizeof(card_t));
	//assert(fc->decks[index].cards && "realloc failed for fc->decks[index].cards[fc->decks[index].n_cards]");
	fc->decks[index].cards[fc->decks[index].n_cards] = ptr;
	++(fc->decks[index]).n_cards;
}

void future_cards_from_deck(deck_t *deck, future_cards_t *fc)
{
	assert_full_deck(deck);
	if (0 == fc->decks)
	{
		fprintf(stderr, "fc is empty");
		return;
	}
	if (fc->n_decks > deck->n_cards)
	{
		fprintf(stderr, "too many unknown cards");
		exit(EXIT_FAILURE);
	}
	size_t i;
	size_t j;
	for (i = 0; i < fc->n_decks; ++i)
	{
		for (j = 0; j < fc->decks[i].n_cards; ++j)
		{
			
				fc->decks[i].cards[j]->value = deck->cards[i]->value;
				fc->decks[i].cards[j]->suit = deck->cards[i]->suit;
			
		}
	}
}
