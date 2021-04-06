#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "input.h"

int main(int argc, char **argv)
{
	if (2 != argc)
	{
		fprintf(stderr, "Usage: input file required\n");
		return EXIT_FAILURE;
	}
	char *input = argv[1];
	size_t i;
	size_t j;
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
	for (i = 0; i < n_hands; ++i)
	{
		print_hand(hands[i]);
		printf("\n");
	}
	printf("\n");
	deck_t *deck = build_remaining_deck(hands, n_hands);
	print_hand(deck);
	printf("\n");
	shuffle(deck);
	printf("shuffled deck: \n");
	print_hand(deck);
	printf("\n");
	future_cards_from_deck(deck, fc);
	free_deck(deck);
	deck = build_remaining_deck(hands, n_hands);
	printf("remaining deck: \n");
	print_hand(deck);
	printf("\n");
	free_deck(deck);
	printf("hands after shuffle: \n");
	for (i = 0; i < n_hands; ++i)
	{
		print_hand(hands[i]);
		printf("\n");
	}

	for (i = 0; i < n_hands; ++i)
	{
		free_deck(hands[i]);
	}
	free(hands);
	for (j = 0; j < fc->n_decks; ++j)
	{
		free(fc->decks[j].cards);
		fc->decks[j].cards = NULL;
	}
	free(fc->decks);
	fc->decks = NULL;
	free(fc);
	fc = NULL;
	if (0 != fclose(f))
	{
		perror("fclose");
		return EXIT_FAILURE;
	}

	return 0;
}