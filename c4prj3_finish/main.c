#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

int main(int argc, char **argv) 
{
	if (2 > argc)
	{
		fprintf(stderr, "Usage: input file required\n");
		return EXIT_FAILURE;
	}
	int num_trials = 10000;
	if (3 == argc)
	{
		num_trials = atoi(argv[2]);
	}
	char *input = argv[1];
	FILE *f = fopen(input, "r");
	if (NULL == f)
	{
		perror("fopen");
		fprintf(stderr, "Trying to open %s\n", input);
		return EXIT_FAILURE;
	}
	future_cards_t *fc = create_unknowns();
	size_t n_hands = 0;
	deck_t **hands = read_input(f, &n_hands, fc);
	deck_t *deck = build_remaining_deck(hands, n_hands);
	unsigned *win_counts = calloc(n_hands + 1, sizeof(*win_counts));
	size_t i;
	unsigned j;
	for (i = 0; i < num_trials; ++i)
	{
		shuffle(deck);
		future_cards_from_deck(deck, fc);
		int result;
		int index = 0;
		deck_t *best = hands[index];
		for (j = 1; j < n_hands; ++j)
		{
			result = compare_hands(best, hands[j]);
			if(0 > result) 
			{
				index = j;
				best = hands[index];
			}
			else if(0 == result) 
			{
				index = n_hands;
			}
		}
		win_counts[index]++;
	}
	for (i = 0; i < n_hands; ++i)
	{
		double ratio = (((double)win_counts[i] / (double)num_trials) * (double)100);
		printf("Hand %zu won %u / %u times (%.2f%%)\n", i, win_counts[i], num_trials, ratio);
		free_deck(hands[i]);
	}
	free(hands);
	printf("And there were %u ties\n", win_counts[n_hands]);
	free(win_counts);
	win_counts = NULL;
	free_deck(deck);
	for (i = 0; i < fc->n_decks; ++i)
	{
		free(fc->decks[i].cards);
		fc->decks[i].cards = NULL;
	}
	free(fc->decks);
	fc->decks = NULL;
	free(fc);
	if (0 != fclose(f))
	{
		perror("fclose");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
