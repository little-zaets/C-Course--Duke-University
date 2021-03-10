#include "eval.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_straight()
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

    card_t *cards1[] = {&c1, &c2, &c3, &c4, &c5, &c6, &c7};
    card_t *cards2[] = {&c8, &c9, &c10, &c11, &c12, &c13, &c14};
    deck_t hand1;
    deck_t hand2;
    hand1.n_cards = sizeof(cards1)/sizeof(card_t*);
    hand1.cards = cards1;
    hand2.n_cards = 7;
    hand2.cards = cards2;
    printf("Result of compare hands: %d\n", compare_hands(&hand1, &hand2));
    

}

int main ()
{
    printf("XYZ\n");
    test_straight();
    return 0;
}