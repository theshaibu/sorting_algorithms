#include "deck.h"
#include <string.h>

/* ... (unchanged code above) */

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
    return strcmp(s1, s2);
}

/**
 * get_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *card)
{
    switch (_strcmp(card->card->value, "Ace"))
    {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    /* ... (other cases) */
    default:
        return 13; /* Default case for unknown card values */
    }
}

/* ... (unchanged code below) */

