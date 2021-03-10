#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t *hand)
{
  //assert(hand);
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
