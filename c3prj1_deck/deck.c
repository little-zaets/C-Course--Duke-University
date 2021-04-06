#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t *hand)
{
	assert(hand);
  	size_t i;
  	for(i = 0; i < hand->n_cards; ++i)
    {
      	print_card(*(hand->cards[i]));
      	printf(" ");
    }
}

int deck_contains(deck_t *d, card_t c)
{
  	assert(d);
 	unsigned i;
  	for(i = 0; i < d->n_cards; ++i)
	{
      	if ( c.value == d->cards[i]->value && c.suit == d->cards[i]->suit )
		{
	 	 return 1;
		}
    }
  	return 0;
}

void randomize(deck_t *deck)
{
  	assert(deck);
 	unsigned i;
  	unsigned r1;
  	unsigned r2;
  	card_t *temp;
  	for(i = 0; i < deck->n_cards; ++i)
    {
      	r1 = random() % deck->n_cards;
      	r2 = random() % deck->n_cards;
      	temp = deck->cards[r1];
     	 deck->cards[r1] = deck->cards[r2];
      	deck->cards[r2] = temp;
    }
}

void shuffle(deck_t *d)
{
	randomize(d);
}

void assert_full_deck(deck_t *d)
{
  	assert(d);
  	unsigned i;
  	int contains_card;
  	assert(d);
  	for(i = 0; i < d->n_cards; ++i)
    {
      	assert_card_valid(*(d->cards[i]));
      	contains_card = deck_contains(d, *(d->cards[i]));
      	assert(contains_card && "Card does not exist in deck");
    } 
}

deck_t *create_deck(void)
{
	deck_t *deck = malloc(sizeof(*deck));
	assert(deck && "malloc failed for deck_t*");
	deck->cards = NULL;
	deck->n_cards = 0;
	return deck;
}

card_t *copy_card(card_t c)
{
	card_t *card = malloc(sizeof(*card));
	assert(card && "malloc failed for card_t*");
	*card = c;
	return card;
}

void add_card_to(deck_t *deck, card_t c)
{
	deck->cards = realloc(deck->cards, sizeof(deck->cards) * (deck->n_cards + 1));
	assert(deck->cards && "realloc failed");
	deck->cards[deck->n_cards] = copy_card(c);
	deck->n_cards++;
}

card_t *add_empty_card(deck_t *deck)
{
	card_t *temp = malloc(sizeof(*temp));
	assert(temp && "malloc failed for card_t*");
	temp->value = 0;
	temp->suit = 0;
	deck->cards = realloc(deck->cards, sizeof(deck->cards) * (deck->n_cards + 1));
	deck->cards[deck->n_cards] = temp;
	deck->n_cards++;
	return temp;
}

deck_t *make_deck_exclude(deck_t *excluded_cards)
{
	deck_t *deck = create_deck();
	size_t i;
	for (i = 0; i < 52; ++i)
	{
		card_t card = card_from_num(i);
		if (!deck_contains(excluded_cards, card))
		{
			add_card_to(deck, card);
		}
	}
	return deck;
}

deck_t *build_remaining_deck(deck_t **hands, size_t n_hands)
{
	deck_t *temp = create_deck();
	size_t j;
	size_t i;
	for (i = 0; i < n_hands; ++i, ++j)
	{
		for (j = 0; j < hands[i]->n_cards; ++j)
		{
			if (!deck_contains(temp, *hands[i]->cards[j]))
			{
				add_card_to(temp, *hands[i]->cards[j]);
			}
		}
	}
	deck_t *deck = make_deck_exclude(temp);
	free_deck(temp);
	return deck; 
}

void free_deck(deck_t *deck)
{
	size_t i;
	for (i = 0; i < deck->n_cards; ++i)
	{
		free(deck->cards[i]);
	}
	free(deck->cards);
	deck->cards = NULL;
	deck->n_cards = 0;
	free(deck);
	deck = NULL;
}
