#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Suit values
 *
 * @SPADE: Spade suit
 * @HEART: Heart suit
 * @CLUB: Club suit
 * @DIAMOND: Diamond suit
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Card structure
 *
 * @value: Value of the card
 *        Ace-King
 * @kind: Suit of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck structure
 *
 * @card: Pointer to the card
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
