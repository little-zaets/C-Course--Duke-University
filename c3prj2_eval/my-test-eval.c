#include "eval.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int find_straight(deck_t * hand, suit_t fs, hand_eval_t * ans);
hand_eval_t build_hand_from_match(deck_t *hand,
				  unsigned n,
				  hand_ranking_t what,
				  size_t idx);
void print_card(card_t c);
/*
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
    hand2.n_cards = sizeof(cards2)/sizeof(card_t*);
    hand2.cards = cards2;
    hand_eval_t hand_2 = evaluate_hand(&hand2);
    find_straight(&hand2, NUM_SUITS, &hand_2);
    
}
*/
void test_build_hand()
{
    size_t i;
    unsigned match_counts1[] = {3, 3, 3, 1, 2, 2, 1};
    unsigned match_counts2[] = {3, 3, 3, 1, 3, 3, 3};
    ssize_t match_idx1;
    ssize_t other_match_idx1;
    ssize_t match_idx2;
    ssize_t other_match_idx2;
    card_t c1 = {VALUE_KING, DIAMONDS};
    card_t c2 = {VALUE_KING, HEARTS};
    card_t c3 = {VALUE_KING, CLUBS};
    card_t c4 = {8, DIAMONDS};
    card_t c5 = {7, CLUBS};
    card_t c6 = {7, HEARTS};
    card_t c7 = {2, CLUBS};
    card_t c8 = {VALUE_QUEEN, DIAMONDS};
    card_t c9 = {VALUE_QUEEN, HEARTS};
    card_t c10 = {VALUE_QUEEN, CLUBS};
    card_t c11 = {9, HEARTS};
    card_t c12 = {7, CLUBS};
    card_t c13 = {7, HEARTS};
    card_t c14 = {7, SPADES};
    
    card_t *cards1[] = {&c1, &c2, &c3, &c4, &c5, &c6, &c7};
    card_t *cards2[] = {&c8, &c9, &c10, &c11, &c12, &c13, &c14};
    deck_t hand1;
    deck_t hand2; 
    hand1.cards = cards1;
    hand2.cards = cards2;
    hand1.n_cards = sizeof(cards1)/sizeof(card_t*);
    hand2.n_cards = sizeof(cards2)/sizeof(card_t*);
    match_idx1 = get_match_index(&match_counts1, hand1.n_cards, 3);
    other_match_idx1 = find_secondary_pair(&hand1, &match_counts1, match_idx1)
    hand_eval_t hand_1 = build_hand_from_match(&hand1, 3, FULL_HOUSE, match_idx1);
    hand_eval_t hand_2 = build_hand_from_match(&hand2, 3, FULL_HOUSE, match_idx2);
    hand_1.cards[3] = hand1.cards[other_match_idx];
    hand_1.cards[4] = hand1.cards[other_match_idx + 1];
    hand_2.cards[3] = hand2.cards[other_match_idx];
    hand_2.cards[4] = hand2.cards[other_match_idx + 1];
    
    for(i = 0; i < 5; ++i)
    {
      print_card(*(hand_1.cards[i]));
      printf(" ");
    }
    printf(" ; ");
    for(i = 0; i < 5; ++i)
    {
      print_card(*(hand_2.cards[i]));
      printf(" ");
    }

}

int main ()
{
    /*test_straight();*/
    test_build_hand();

    return 0;
}