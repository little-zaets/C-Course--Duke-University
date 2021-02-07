#include <stdio.h>
#include <string.h>
#include "cards.h"
#define TEST(expr) ((expr) ? printf("PASSED\n") : \
		printf("FAILED: '%s', line: %d\n", #expr, __LINE__))

void testSpades();
void testHearts();
void testDiamonds();
void testClubs();
void testChar_to_card(char suit);
void testRanking();

int main(void)
{
  char suit1 = 's';
  char suit2 = 'h';
  char suit3 = 'd';
  char suit4 = 'c';
  char suit5 = '5';
  
  testSpades();
  testHearts();
  testDiamonds();
  testClubs();

  testRanking();
  testChar_to_card(suit1);
  testChar_to_card(suit2);
  testChar_to_card(suit3);
  testChar_to_card(suit4);
  testChar_to_card(suit5);

  
  return 0;
}

void testSpades()
{
  unsigned i;
  card_t test;

  for(i = 0; i < 13; ++i)
    {
      test = card_from_num(i);
      print_card(test);
      printf("\n");
      TEST(SPADES == test.suit);
      TEST(((i % 13) + 2) == test.value);
    }
}

void testHearts()
{
  unsigned i;
  card_t test1;

  for(i = 13; i < 26; ++i)
    {
      test1 = card_from_num(i);
      print_card(test1);
      printf("\n");
      TEST(HEARTS == test1.suit);
      TEST(((i % 13) + 2) == test1.value);
    }
}

void testDiamonds()
{
  unsigned i;
  card_t test2;

  for(i = 26; i < 39; ++i)
    {
      test2 = card_from_num(i);
      print_card(test2);
      printf("\n");
      TEST(DIAMONDS == test2.suit);
      TEST(((i % 13) + 2) == test2.value);
    }
}

void testClubs()
{
  unsigned i;
  card_t test3;

  for(i = 39; i < 52; ++i)
    {
      test3 = card_from_num(i);
      print_card(test3);
      printf("\n");
      TEST(CLUBS == test3.suit);
      TEST(((i % 13) + 2) == test3.value);
    }
}

void testChar_to_card(char suit)
{
  printf("Test Char to Card\nSuit: %c\n", suit);
  unsigned SUIT;
  char value;
  unsigned i;
  card_t test_card;
  switch (suit)
    {
  case 's':
    SUIT = SPADES;
    break;
  case 'h':
    SUIT = HEARTS;
    break;
  case 'd':
    SUIT = DIAMONDS;
    break;
  case 'c':
    SUIT = CLUBS;
    break;
  default:
    printf("Invalid suit\n");
    }
  for(i = '2'; i <= '9'; ++i)
    {
      value = i;
      test_card = card_from_letters(value, suit);
      TEST((i - '0') == test_card.value);
      TEST(SUIT == test_card.suit);
    }
  value = '0';
  test_card = card_from_letters(value, suit);
  TEST(10 == test_card.value);
  value = 'J';
  test_card = card_from_letters(value, suit);
  TEST(VALUE_JACK == test_card.value);
  value = 'Q';
  test_card = card_from_letters(value, suit);
  TEST(VALUE_QUEEN == test_card.value);
  value = 'K';
  test_card = card_from_letters(value, suit);
  TEST(VALUE_KING == test_card.value);
  value = 'A';
  test_card = card_from_letters(value, suit);
  TEST(VALUE_ACE == test_card.value);
}

void testRanking()
{
  printf("Test Ranking\n");
  TEST(0 == strcmp(ranking_to_string(STRAIGHT_FLUSH), "STRAIGHT FLUSH"));
  TEST(0 == strcmp(ranking_to_string(FOUR_OF_A_KIND), "FOUR OF A KIND"));
  TEST(0 == strcmp(ranking_to_string(FULL_HOUSE),"FULL HOUSE"));
  TEST(0 == strcmp(ranking_to_string(FLUSH), "FLUSH"));
  TEST(0 == strcmp(ranking_to_string(STRAIGHT), "STRAIGHT"));
  TEST(0 == strcmp(ranking_to_string(THREE_OF_A_KIND), "THREE OF A KIND"));
  TEST(0 == strcmp(ranking_to_string(TWO_PAIR), "TWO PAIR"));
  TEST(0 == strcmp(ranking_to_string(PAIR), "PAIR"));
  TEST(0 == strcmp(ranking_to_string(NOTHING), "NOTHING"));
}
