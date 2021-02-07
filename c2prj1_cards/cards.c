#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c)
{
  assert(2 <= c.value && c.value <= 14);
  assert(SPADES <= c.suit && c.suit < NUM_SUITS);
}

const char *ranking_to_string(hand_ranking_t r)
{
  switch (r)
  {
  case STRAIGHT_FLUSH:
    return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND";
  case FULL_HOUSE:
    return "FULL_HOUSE";
  case FLUSH:
    return "FLUSH";
  case STRAIGHT:
    return "STRAIGHT";
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND";
  case TWO_PAIR:
    return "TWO_PAIR";
  case PAIR:
    return "PAIR";
  case NOTHING:
    return "NOTHING";
  default: return "";
  }
}

char value_letter(card_t c)
{
  char value_letter = '0';
  if ( c.value >= 2 && c.value <= 9 )
  {
    return value_letter + c.value;
  }
  if ( c.value > 9 && c.value <= VALUE_ACE )
  {
    switch (c.value)
    {
      case 10:
	return value_letter;
      case VALUE_JACK:
	return 'J';
      case VALUE_QUEEN:
	return 'Q';
      case VALUE_KING:
	return 'K';
      case VALUE_ACE:
	return 'A';
      default:
	return 'x';
    }
  }
  return value_letter;
}

char suit_letter(card_t c)
{
  switch (c.suit)
  {
  case SPADES:
    return 's';
  case HEARTS:
    return 'h';
  case DIAMONDS:
    return 'd';
  case CLUBS:
    return 'c';
  default:
    return 'x';
  }
}

void print_card(card_t c)
{
  printf("%c", value_letter(c));
  printf("%c", suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let)
{
  card_t temp;
  if ( '2' <= value_let && value_let <= '9' )
    {
      temp.value = value_let - '0';
    }
  else
    {
      switch (value_let)
	{
	case '0':
	  temp.value = 10;
	  break;
	case 'J':
	  temp.value = VALUE_JACK;
	  break;
	case 'Q':
	  temp.value = VALUE_QUEEN;
	  break;
	case 'K':
	  temp.value = VALUE_KING;
	  break;
	case 'A':
	  temp.value = VALUE_ACE;
	  break;
	}
    }
  switch (suit_let)
    {
  case 's':
    temp.suit = SPADES;
    break;
  case 'h':
    temp.suit = HEARTS;
    break;
  case 'd':
    temp.suit = DIAMONDS;
    break;
  case 'c':
    temp.suit = CLUBS;
    break;
  default:
    temp.suit = NUM_SUITS;
    }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c)
{
  assert(52 > c && c >= 0);
  card_t temp;
  if ( 52 > c && c >= 39 )
    {
      temp.suit = CLUBS;
    }
  else if ( 39 > c && c >= 26 )
    {
       temp.suit = DIAMONDS;
    }
  else if ( 26 > c && c >= 13 )
    {
       temp.suit = HEARTS;
    }
  else 
    {
       temp.suit = SPADES;
    }
  temp.value = (c % 13) + 2;
  return temp;
}
